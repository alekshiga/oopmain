#include "RandomExcursion.h"
#include "SpaceObject.h"
#include <iostream>
#include <vector>
#include <random>
#include <limits>

RandomExcursion::RandomExcursion(const std::vector<SpaceObject*>& objects) : route(objects), random(std::random_device{}()) {
    std::shuffle(route.begin(), route.end(), random);  // Перемешиваем объекты при создании
}

RandomExcursion::~RandomExcursion() {}

SpaceObject* RandomExcursion::getCurrentObject() {
    if (currentObjectIndex < route.size() && !finished) {
        return route[currentObjectIndex];
    }
    return nullptr;
}

void RandomExcursion::goToNextObject() {
    if (currentObjectIndex < route.size() - 1) { // Ensure we don't go out of bounds.
        currentObjectIndex++;
    }
    else {
        finished = true; // No more objects to visit.
    }
}

bool RandomExcursion::isFinished() {
    return finished || currentObjectIndex >= route.size();
}

void RandomExcursion::finishExcursion() {
    finished = true;
}

void RandomExcursion::startExcursion() {
    while (!isFinished()) {
        SpaceObject* currentObject = getCurrentObject();
        if (currentObject) {
            std::cout << "Осматриваем: " << currentObject->getName() << std::endl;

            char choice;
            while (true) {
                std::cout << "Посетить другой объект? (y/n): ";
                std::cin >> choice;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Очищаем буфер ввода

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
