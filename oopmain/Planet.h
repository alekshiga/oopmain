#pragma once
#ifndef PLANET_H
#define PLANET_H

#include <iostream>
#include <sstream>
#include <iomanip>
#include "SpaceObject.h"


class Planet : public SpaceObject {
private:
    std::string name;
    float radius;

public:
    Planet(std::string name, float radius) : name(name), radius(radius) {}

    void display() override {
        std::cout << "����������� �������: " << name << "\n";
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
};

#endif