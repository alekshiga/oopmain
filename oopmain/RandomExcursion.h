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
    int currentObjectIndex = 0;
    bool finished = false;

public:
    RandomExcursion(const std::vector<SpaceObject*>& objects) : route(objects), random(std::random_device{}()) {
        std::shuffle(route.begin(), route.end(), random);  // Перемешиваем объекты при создании
    }

    ~RandomExcursion() override {}

    SpaceObject* getCurrentObject() override {
        if (currentObjectIndex < route.size() && !finished) {
            return route[currentObjectIndex];
        }
        return nullptr;
    }

    void goToNextObject() override {
        if (currentObjectIndex < route.size() - 1) { // Ensure we don't go out of bounds.
            currentObjectIndex++;
        }
        else {
            finished = true; // No more objects to visit.
        }
    }

    bool isFinished() override {
        return finished || currentObjectIndex >= route.size();
    }

    void finishExcursion() {
        finished = true;
    }

    void startExcursion() override {
        while (!isFinished()) {
            SpaceObject* currentObject = getCurrentObject();
            if (currentObject) {
                std::cout << "Осматриваем: " << currentObject->getName() << std::endl;

                char choice;
                while (true) {
                    std::cout << "Посетить другой объект? (y/n): ";
                    std::cin >> choice;
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer

                    if (choice == 'y') {
                        goToNextObject();
                        break;
                    }
                    else if (choice == 'n') {
                        finishExcursion();
                        break;
                    }
                    else {
                        std::cout << "Некорректный ввод. Пожалуйста, введите 'y' или 'n'." << std::endl;
                    }
                }
            }
            else {
                std::cout << "Экскурсия закончена." << std::endl;
                break;
            }
        }
    }
};

#endif