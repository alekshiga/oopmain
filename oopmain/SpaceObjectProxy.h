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
    SpaceObject* realObject; // ��������� �� �������� ������, ������� ����� ����������� ������ ��� �������������

public:
    // ���������� ������������� ��� ������ ����� ����������� ��������
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
        // ������� �������� ������, ���� �� ��� ������
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
                std::cerr << "������: �� ������� ������������ ������� ��� �������� " << name << std::endl;
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
            std::cerr << "������: ����������� ��� ������������ �������" << std::endl;
            return;
        }
        std::cout << "Proxy: �������� �������� ��� " << name << "...\n";
    }

    void display() override {
        if (realObject == nullptr) {
            load();
        }
        realObject->display();
    }

    void playAudio() override {
        // ���� ������ ��� �� ������, �� �������� ����� display() ��� ��������
        if (realObject == nullptr) {
            display();
            std::cout << "Proxy: �������� ����� ��� " << name << "...\n";
        }
        realObject->playAudio();
    }

    Planet* findPlanetByName(const std::string& name) {
        auto it = planets.find(name);
        if (it != planets.end()) {
            return it->second; // ���������� ��������� �� �������
        }
        else {
            return nullptr; // ������� �� �������
        }
    }

    std::string getDescription() override {
        if (realObject == nullptr) {
            // ���������� ���������� ��������, ���� ������ �� ��������
            return "�������� ������� " + name + " ����� �������� ����� ����������� � ��������� �������� �������.";
        }
        return realObject->getDescription();
    }

    std::string getName() override {
        return name;
    }

};