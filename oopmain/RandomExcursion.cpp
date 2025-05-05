#include "RandomExcursion.h"
#include "SpaceObject.h"
#include <iostream>
#include <vector>
#include <random>
#include <limits>

RandomExcursion::RandomExcursion(const std::vector<SpaceObject*>& objects) : route(objects), random(std::random_device{}()) {
    std::shuffle(route.begin(), route.end(), random);  // ������������ ������� ��� ��������
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
            std::cout << "�����������: " << currentObject->getName() << std::endl;

            char choice;
            while (true) {
                std::cout << "�������� ������ ������? (y/n): ";
                std::cin >> choice;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ������� ����� �����

                if (choice == 'y') {
                    goToNextObject();
                    break;
                }
                else if (choice == 'n') {
                    finishExcursion();
                    break;
                }
                else {
                    std::cout << "������������ ����. ����������, ������� 'y' ��� 'n'." << std::endl;
                }
            }
        }
        else {
            std::cout << "��������� ���������." << std::endl;
            break;
        }
    }
}
