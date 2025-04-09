#pragma once
#ifndef SATELITE_H
#define SATELITE_H

#include <iostream>
#include <sstream>
#include <iomanip>
#include "SpaceObject.h"
#include "Planet.h"

class Satelite : public SpaceObject {
private:
    std::string name;
    //���������� ���������� ������: ���� ������� ������ � ���� ��������� �� ������������ �������, �� ��� �������� ������������ ������� ���������� ������� �������
    std::string parentPlanetName;
    AudioFile* audioFile;
    SpaceObjectType type = SpaceObjectType::Satelite;

public:
    Satelite(std::string name, std::string parentPlanetName, AudioFile* audioFile) : name(name), parentPlanetName(parentPlanetName), audioFile(audioFile) {}

    void display() override {
        std::cout << "����������� ��������: " << name << "\n";
    }

    std::string getDescription() override {
        return "�������� ��������: " + name + ". ��������� ������: " + parentPlanetName + "\n";
    }

    void getAdditionalInfo() override {
        std::cout << "�������������� ����������" << std::endl;
        std::cout << "���� ��� ��� �������������� ���������� � ��������" << std::endl;
    }

    std::string getName() override {
        return name;
    }

    void playAudio() override {
        audioFile->play();
    }
};

#endif
