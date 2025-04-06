#pragma once
#ifndef STAR_H
#define STAR_H

#include "SpaceObject.h"
#include <sstream>
#include <iomanip>
#include <iostream>
#include <string>

class Star : public SpaceObject {
private:
    std::string name;
    float radius;
    int temperature;

public:
    Star(std::string name, float radius, int temperature) : name(name), temperature(temperature), radius(radius) {}

    void display() override {
        std::cout << "����������� ������: " << name << "\n";
    }

    std::string getDescription() override {
        return "�������� ������ " + name + ". ����������� = " + std::to_string(temperature) + " C.";
    }
};

#endif