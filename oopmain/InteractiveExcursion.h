#ifndef INTERACTIVEEXCURSION_H
#define INTERACTIVEEXCURSION_H

#include "Excursion.h"
#include "User.h"
#include <vector>
#include <string>
#include <iostream>

class InteractiveExcursion : public Excursion {
private:
    std::vector<SpaceObject*> availableObjects;
    std::vector<User*> users;
    SpaceObject* currentObject;
    std::string description;

public:
    InteractiveExcursion(std::vector<SpaceObject*> availableObjects, std::string description) : availableObjects(availableObjects), currentObject(nullptr), description(description) {}

    std::vector<SpaceObject*> getRoute() {
        std::vector<SpaceObject*> currentRoute;
        if (currentObject != nullptr) {
            currentRoute.push_back(currentObject);
        }
        return currentRoute;
    }

    // �����, ����� ������������ ������ ��������� ������
    void chooseNextObject(SpaceObject* nextObject) {
        bool found = false;
        for (SpaceObject* obj : availableObjects) {  // �������, �������� �� ��������� ������
            if (obj == nextObject) {
                found = true;
                break;
            }
        }
        if (found) {
            currentObject = nextObject;
        }
        else {
            std::cerr << "��������, ������ ����������." << std::endl; // ���� ������� ���, �� ������� ���������
        }
    }

    SpaceObject* getCurrentObject() override {
        return currentObject;
    }

    void getToObject(int n) {
        currentObject = availableObjects[n - 1];
    }

    std::string getDescription() {
        return description;
    }
};

#endif