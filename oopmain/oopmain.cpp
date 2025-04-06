#include <iostream>
#include "SpaceObject.h"
#include "Planet.h"
#include "Star.h"
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

    // �������� �������� ����� � ������
    Planet* earth = new Planet("�����", 6378.0);
    Star* sun = new Star("������", 696340.0, 5778);
    Planet* mars = new Planet("����", 3389.5);

    earth->display();
    sun->display();
    mars->display();

    std::vector<SpaceObject*> routeSolarSystem;
    routeSolarSystem.push_back(sun);
    routeSolarSystem.push_back(earth);
    routeSolarSystem.push_back(mars);
    try {
        LinearExcursion* solarSystemExcursion = new LinearExcursion(routeSolarSystem, "����������� �� ��������� �������.");
        Scene* scene = Scene::getInstance(solarSystemExcursion);
        scene->displayScene();
        // �������� ����������
        Visitor* visitor = new Visitor("������");
        for (SpaceObject* obj : routeSolarSystem) {
            visitor->visit(obj);
        }
        delete solarSystemExcursion; // ������� �������
        delete visitor;
    }
    catch (const std::exception& e) {
        std::cerr << "������ ��� �������� ���������: " << e.what() << std::endl;
    }
    catch (...) {
        std::cerr << "����������� ������!" << std::endl;
    }

    AudioFile* song = new AudioFile("source/audio/sunSound", 50);
    std::cout << std::endl;
    song->setVolume(15);
    song->play();
    song->stop();

    // ����� ����� ���������� ������ �������, ��� ��� ������������ � C++ �� ������ ��� �������������
    delete earth;
    delete sun;
    delete mars;
    return 0;
}

