#pragma once
#ifndef LINEAREXCURSION_H
#define LINEAREXCURSION_H

#include "Excursion.h"
#include "Visitor.h"
#include <vector>
#include <string>
#include <iostream>

class LinearExcursion : public Excursion {
private:
    std::vector<SpaceObject*> route;
    std::vector<Visitor*> visitors;
    int currentObjectNumber;
    std::string description;
    SpaceObject* currentObject;


public:
    LinearExcursion(std::vector<SpaceObject*> route, std::string description) : route(route), description(description), currentObjectNumber(0) {
        if (!route.empty()) {
            currentObject = route[0];
        }
        else {
            std::cout << "Маршрут экскурсии пуст!" << std::endl;
            currentObject = nullptr;
        }
    }

    std::vector<SpaceObject*> getRoute() override {
        return route;
    }

    std::string getDescription() override {
        return description;
    }

    SpaceObject* getCurrentObject() override {
        return currentObject;
    }

    void getToNextObject() {
        if (currentObjectNumber + 1 < route.size()) {
            currentObjectNumber++;
            currentObject = route[currentObjectNumber];
        }
        else {
            std::cout << "В экскурсии нет следующего объекта" << std::endl;
        }
    }
};

#endif