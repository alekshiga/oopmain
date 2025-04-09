#pragma once
#ifndef PLANET_H
#define PLANET_H

#include <iostream>
#include <sstream>
#include <iomanip>
#include "SpaceObject.h"
#include "SpaceObjectType.h"


class Planet : public SpaceObject {
private:
    std::string name;
    float radius;
    AudioFile* audioFile;
    SpaceObjectType type = SpaceObjectType::Planet;
    bool life;

public:
    Planet(std::string name, float radius, bool life, AudioFile* audioFile) : name(name), radius(radius), audioFile(audioFile), life(life) {}

    void display() override {
        std::cout << "����������� �������: " << name << "\n";
    }

    void getAdditionalInfo() override {
        std::cout << "�������������� ����������" << std::endl;
        std::cout << "�� ������� ���� �����? ";
        if (life) std::cout << "��" << std::endl;
        else std::cout << "���" << std::endl;
    }

    std::string getDescription() override {
        std::stringstream stream;
        stream << std::fixed << std::setprecision(1) << radius; // ������������� �������� 1 ���� ����� �������
        std::string radiusString = stream.str();
        return "�������� �������: " + name + ". ������ = " + radiusString + " ��.";
    }

    std::string getName() override {
        return name;
    }

    void playAudio() override {
        audioFile->play();
    }
};

#endif