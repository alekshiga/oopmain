#ifndef INTERACTIVEEXCURSION_H
#define INTERACTIVEEXCURSION_H

#include "Excursion.h"
#include "Visitor.h"
#include <vector>
#include <string>
#include <iostream>

class SpaceObject;

class InteractiveExcursion : public Excursion {
private:
    std::vector<SpaceObject*> availableObjects;
    std::vector<Visitor*> visitors;
    SpaceObject* currentObject;
    std::string description;

public:
    InteractiveExcursion(std::vector<SpaceObject*> availableObjects, std::string description) : availableObjects(availableObjects), currentObject(nullptr), description(description) {}

    std::vector<SpaceObject*> getRoute() override {
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