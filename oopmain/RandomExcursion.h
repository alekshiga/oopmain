#pragma once
#define QUIZEXCRUSION_H
#ifndef RANDOMEXCURSION_H

#include <iostream>
#include <vector>
#include <random>
#include <limits>

#include "Excursion.h"
#include "SpaceObject.h"
#include "User.h"

class RandomExcursion : public Excursion {
private:
    std::vector<SpaceObject*> route;
    std::mt19937 random;
    std::uniform_int_distribution<int> distribution; // диапазон случайных чисел
    bool finished = false;

public:
    RandomExcursion(const std::vector<SpaceObject*>& objects) : route(objects), random(std::random_device{}()),
        distribution(0, objects.size() - 1) {
        if (!objects.empty()) {
            distribution = std::uniform_int_distribution<int>(0, objects.size() - 1);
        }
    }

    SpaceObject* getCurrentObject() override {
        if (route.empty() || finished) {
            return nullptr;
        }
        return route[distribution(random)];
    }

    void goToNextObject() override {
        std::cout << "следующий объект" << std::endl;
    }

    bool isFinished() override {
        return finished;
    }

    void finishExcursion() {
        finished = true;
    }
};

#endif