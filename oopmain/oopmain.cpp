#include <iostream>
#include "SpaceObject.h"
#include "Planet.h"
#include "Star.h"
#include "Satelite.h"
#include "Scene.h"
#include "Excursion.h"
#include "LinearExcursion.h"
#include "Visitor.h"
#include "AudioFile.h"
#include <vector>
#include <windows.h>
#include <locale>

int main() {

    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    // создание объектов Земля и Солнце
    Planet* earth = new Planet("Земля", 6378.0);
    Star* sun = new Star("Солнце", 696340.0, 5778);
    //Planet* mars = new Planet("Марс", 3389.5);
    Satelite* moon = new Satelite("Луна", earth);

    earth->display();
    sun->display();
    //mars->display();

    std::vector<SpaceObject*> routeSolarSystem;
    routeSolarSystem.push_back(sun);
    routeSolarSystem.push_back(earth);
    routeSolarSystem.push_back(moon);
    //routeSolarSystem.push_back(mars);
    try {
        LinearExcursion* solarSystemExcursion = new LinearExcursion(routeSolarSystem, "Путешествие по Солнечной Системе.");
        Scene* scene = Scene::getInstance(solarSystemExcursion);
        scene->displayScene();
        // создание посетителя
        Visitor* visitor = new Visitor("Турист");
        for (SpaceObject* obj : routeSolarSystem) {
            visitor->visit(obj);
        }
        delete solarSystemExcursion; // удаляем вручную
        delete visitor;
    }
    catch (const std::exception& e) {
        std::cerr << "Ошибка при создании экскурсии: " << e.what() << std::endl;
    }
    catch (...) {
        std::cerr << "Неизвестная ошибка!" << std::endl;
    }

    AudioFile* song = new AudioFile("source/audio/sunSound", 50);
    std::cout << std::endl;
    song->setVolume(15);
    song->play();
    song->stop();

    // очень важно освободить память вручную, так как конструкторы в C++ не делают это автоматически
    delete earth;
    delete sun;
    delete moon;
    //delete mars;
    return 0;
}

