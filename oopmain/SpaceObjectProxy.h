#pragma once

#include <string>
#include "SpaceObject.h"
#include "Star.h"
#include "Planet.h"
#include "Satelite.h"
#include "Asteroid.h"
#include "SpaceObjectType.h"
#include <map>


class SpaceObjectProxy : public SpaceObject {
private:
    std::string name;
    float radius;
    int temperature;
    std::string composition;
    std::string parentPlanetName;
    std::map<std::string, Planet*> planets;
    SpaceObjectType type;
    SpaceObject* realObject; // указатель на реальный объект, который будет создаваться только при необходимости

public:
    // перегрузки конструкторов для разных типов космических объектов
    SpaceObjectProxy(std::string name, SpaceObjectType type, float radius): name(name), radius(radius), type(type), realObject(nullptr) {
        temperature = 0;
        composition = "";
        parentPlanetName = "";
    };
    SpaceObjectProxy(std::string name, int temperature, SpaceObjectType type) : name(name), temperature(temperature), type(type), realObject(nullptr) {
        radius = 0;
        composition = "";
        parentPlanetName = "";
    };
    SpaceObjectProxy(std::string name, std::string planetName, SpaceObjectType type) : name(name), parentPlanetName(planetName), type(type), realObject(nullptr) {
        radius = 0;
        temperature = 0;
        composition = "";
    };
    SpaceObjectProxy(std::string name, SpaceObjectType type, std::string composition) : name(name), composition(composition), type(type), realObject(nullptr) {
        radius = 0;
        temperature = 0;
        parentPlanetName = "";
    };

    ~SpaceObjectProxy() {
        // удалить реальный объект, если он был создан
        if (realObject != nullptr) {
            delete realObject;
        }
    }

    void load() {
        switch (type) {
        case SpaceObjectType::Star:
            audioFile = new AudioFile("star_audio.mp3", 50);
            realObject = new Star(name, temperature, audioFile);
            break;
        case SpaceObjectType::Planet:
            audioFile = new AudioFile("planet_audio.mp3", 50);
            planets[name] = new Planet(name, radius, audioFile);
            realObject = planets[name];
            break;
        case SpaceObjectType::Satelite: {
            Planet* parentPlanet = findPlanetByName(parentPlanetName);
            if (parentPlanet == nullptr) {
                std::cerr << "Ошибка: Не найдена родительская планета для спутника " << name << std::endl;
                return;
            }
            audioFile = new AudioFile("satelite_audio.mp3", 50);
            realObject = new Satelite(name, parentPlanet, audioFile);
            break;
        }
        case SpaceObjectType::Asteroid:
            audioFile = new AudioFile("asteroid_audio.mp3", 50);
            realObject = new Asteroid(name, composition, audioFile);
            break;
        default:
            std::cerr << "Ошибка: Неизвестный тип космического объекта" << std::endl;
            return;
        }
        std::cout << "Proxy: Загрузка ресурсов для " << name << "...\n";
    }

    void display() override {
        if (realObject == nullptr) {
            load();
        }
        realObject->display();
    }

    void playAudio() override {
        // если объект ещё не создан, то вызываем метод display() для создания
        if (realObject == nullptr) {
            display();
            std::cout << "Proxy: Загрузка аудио для " << name << "...\n";
        }
        realObject->playAudio();
    }

    Planet* findPlanetByName(const std::string& name) {
        auto it = planets.find(name);
        if (it != planets.end()) {
            return it->second; // Возвращаем указатель на планету
        }
        else {
            return nullptr; // Планета не найдена
        }
    }

    std::string getDescription() override {
        if (realObject == nullptr) {
            // Возвращаем упрощенное описание, пока объект не загружен
            return "Описание объекта " + name + " будет доступно после отображения и реального создания объекта.";
        }
        return realObject->getDescription();
    }

    std::string getName() override {
        return name;
    }

};