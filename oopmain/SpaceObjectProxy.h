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
    bool life;
    int temperature;
    std::string composition;
    std::string parentPlanetName;
    SpaceObjectType type;
    SpaceObject* realObject; // ��������� �� �������� ������, ������� ����� ����������� ������ ��� �������������

public:
    // ���������� ������������� ��� ������ ����� ����������� ��������
    SpaceObjectProxy(std::string name, SpaceObjectType type, bool life, float radius): name(name), radius(radius), type(type), life(life), realObject(nullptr) {
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
            std::cerr << "������: ����������� ��� ������������ �������" << std::endl;
            return;
        }
        std::cout << "Proxy: �������� �������� ��� " << name << "...\n";
    }

    void display() override {
        if (realObject == nullptr) {
            load();
            if (realObject == nullptr) {
                std::cerr << "������: �� ������� ��������� realObject\n";
            }
        }
        realObject->display();
    }

    void getAdditionalInfo() override {
        // ���� ������ ��� �� ������, �� �������� ����� display() ��� ��������
        if (realObject == nullptr) {
            display();
            std::cout << "Proxy: �������� �������������� ����������: " << name << "...\n";
        }
        realObject->getAdditionalInfo();
    }

    void playAudio() override {
        // ���� ������ ��� �� ������, �� �������� ����� display() ��� ��������
        if (realObject == nullptr) {
            display();
            std::cout << "Proxy: �������� ����� ��� " << name << "...\n";
        }
        realObject->playAudio();
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