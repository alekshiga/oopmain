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
            realObject = new Planet(name, radius, true, audioFile);
            break;
        case SpaceObjectType::Satelite: {
            audioFile = new AudioFile("satelite_audio.mp3", 50);
            realObject = new Satelite(name, parentPlanetName, audioFile);
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
            if (realObject == nullptr) {
                std::cerr << "Ошибка: не удалось загрузить realObject\n";
            }
        }
        realObject->display();
    }

    void getAdditionalInfo() override {
        // если объект ещё не создан, то вызываем метод display() для создания
        if (realObject == nullptr) {
            display();
            std::cout << "Proxy: Загрузка дополнительной информации: " << name << "...\n";
        }
        realObject->getAdditionalInfo();
    }

    void playAudio() override {
        // если объект ещё не создан, то вызываем метод display() для создания
        if (realObject == nullptr) {
            display();
            std::cout << "Proxy: Загрузка аудио для " << name << "...\n";
        }
        realObject->playAudio();
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