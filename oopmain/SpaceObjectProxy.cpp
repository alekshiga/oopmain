#include "SpaceObjectProxy.h"
#include "SpaceObject.h"
#include "Star.h"
#include "Planet.h"
#include "Satelite.h"
#include "Asteroid.h"
#include <iostream>

SpaceObjectProxy::SpaceObjectProxy(std::string name, SpaceObjectType type, bool life, float radius) : name(name), radius(radius), type(type), life(life), realObject(nullptr), SpaceObject(nullptr) {
    temperature = 0;
    composition = "";
    parentPlanetName = "";
}

SpaceObjectProxy::SpaceObjectProxy(std::string name, int temperature, SpaceObjectType type) : name(name), temperature(temperature), type(type), realObject(nullptr), SpaceObject(nullptr) {
    radius = 0;
    composition = "";
    parentPlanetName = "";
}

SpaceObjectProxy::SpaceObjectProxy(std::string name, std::string planetName, SpaceObjectType type) : name(name), parentPlanetName(planetName), type(type), realObject(nullptr), SpaceObject(nullptr) {
    radius = 0;
    temperature = 0;
    composition = "";
}

SpaceObjectProxy::SpaceObjectProxy(std::string name, SpaceObjectType type, std::string composition) : name(name), composition(composition), type(type), realObject(nullptr), SpaceObject(nullptr) {
    radius = 0;
    temperature = 0;
    parentPlanetName = "";
}

SpaceObjectProxy::~SpaceObjectProxy() {
    if (realObject != nullptr) {
        delete realObject;
    }
}

void SpaceObjectProxy::load() {
    switch (type) {
    case SpaceObjectType::Star:
        audioFile = new AudioFile("star_audio.mp3", 50);
        realObject = new Star(name, temperature, audioFile);
        break;
    case SpaceObjectType::Planet:
        audioFile = new AudioFile("planet_audio.mp3", 50);
        realObject = new Planet(name, radius, life, audioFile);
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

void SpaceObjectProxy::display() {
    if (realObject == nullptr) {
        load();
        if (realObject == nullptr) {
            std::cerr << "Ошибка: не удалось загрузить realObject\n";
            return;
        }
    }
    realObject->display();
}

void SpaceObjectProxy::getAdditionalInfo() {
    if (realObject == nullptr) {
        display();
        if (realObject == nullptr) return;
        std::cout << "Proxy: Загрузка дополнительной информации: " << name << "...\n";
    }
    realObject->getAdditionalInfo();
}

void SpaceObjectProxy::playAudio() {
    if (realObject == nullptr) {
        display();
        if (realObject == nullptr) return;
        std::cout << "Proxy: Загрузка аудио для " << name << "...\n";
    }
    realObject->playAudio();
}

std::string SpaceObjectProxy::getDescription() {
    if (realObject == nullptr) {
        return "Описание объекта " + name + " будет доступно после отображения и реального создания объекта.";
    }
    return realObject->getDescription();
}

std::string SpaceObjectProxy::getName() {
    return name;
}
