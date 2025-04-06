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
    Planet* planet;

public:
    Satelite(std::string name, Planet* planet) : name(name), planet(planet) {}

    void display() override {
        std::cout << "����������� ��������: " << name << "\n";
    }

    std::string getDescription() override {
        return "�������� ��������: " + name + ". ��������� ������: " + planet->getName() + "\n";
    }

    std::string getName() override {
        return name;
    }
};

#endif
