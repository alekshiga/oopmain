#pragma once
#ifndef LINEAREXCURSION_H
#define LINEAREXCURSION_H

#include "Excursion.h"
#include "User.h"
#include <vector>
#include <string>
#include <iostream>

class LinearExcursion : public Excursion {
private:
    std::vector<SpaceObject*> route;
    int currentObjectIndex;

public:
    LinearExcursion(const std::vector<SpaceObject*>& objects) : route(objects), currentObjectIndex(0) {}

    SpaceObject* getCurrentObject() override {
        if (currentObjectIndex < route.size()) {
            return route[currentObjectIndex];
        }
        else {
            return nullptr; // Ёкскурси€ закончена
        }
    }

    void goToNextObject() override {
        if (currentObjectIndex < route.size()) {
            currentObjectIndex++;
        }
    }

    bool isFinished() override {
        return currentObjectIndex >= route.size();
    }
};

#endif