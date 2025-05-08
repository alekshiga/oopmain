#include "InteractiveExcursion.h"
#include "SpaceObject.h"
#include "Iterator.h"
#include <iostream>
#include <limits>

InteractiveExcursion::InteractiveExcursion(ExcursionRoute* availableObjectsRoute, std::string description)
    : Excursion(availableObjectsRoute),  // �������� ����������� Excursion � availableObjectsRoute
    availableObjectsRoute(availableObjectsRoute),
    currentObject(nullptr),
    description(description),
    finished(false) {
}

InteractiveExcursion::~InteractiveExcursion() {
    //delete availableObjectsRoute; // �� �������!  �������� ���������� � main()
}

std::vector<SpaceObject*> InteractiveExcursion::getRoute() {
    std::vector<SpaceObject*> currentRoute;
    if (currentObject != nullptr) {
        currentRoute.push_back(currentObject);
    }
    return currentRoute;
}

void InteractiveExcursion::chooseNextObject(SpaceObject* nextObject) {
    bool found = false;
    const std::vector<SpaceObject*>& availableObjects = availableObjectsRoute->getObjects();

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

SpaceObject* InteractiveExcursion::getCurrentObject() {
    return currentObject;
}

std::string InteractiveExcursion::getDescription() {
    return description;
}

void InteractiveExcursion::getToObject(int n) {
    if (n > 0 && n <= availableObjectsRoute->count()) {
        currentObject = availableObjectsRoute->get(n - 1);
    }
    else {
        std::cerr << "������������ ����� �������." << std::endl;
    }
}

void InteractiveExcursion::startExcursion() {
    std::cout << "����� ���������� �� ������������� ���������!" << std::endl;
    std::cout << description << std::endl;

    while (!finished) {
        std::cout << "\n��������� �������:" << std::endl;
        const std::vector<SpaceObject*>& availableObjects = availableObjectsRoute->getObjects();
        for (size_t i = 0; i < availableObjects.size(); ++i) {
            std::cout << i + 1 << ". " << availableObjects[i]->getName() << std::endl;
        }

        std::cout << "������� ����� ������� ��� ��������� (��� 'q' ��� ������): ";
        std::string input;
        std::getline(std::cin, input);

        if (input == "q") {
            finished = true;
            std::cout << "��������� ���������." << std::endl;
        }
        else {
            try {
                int objectNumber = std::stoi(input);
                if (objectNumber > 0 && objectNumber <= availableObjectsRoute->count()) {
                    getToObject(objectNumber);
                    if (currentObject) {
                        std::cout << "�� ��������: ";
                        currentObject->display();
                    }
                }
                else {
                    std::cout << "������������ ����� �������." << std::endl;
                }
            }
            catch (const std::invalid_argument& e) {
                std::cout << "������������ ����. ������� ����� ��� 'q'." << std::endl;
            }
            catch (const std::out_of_range& e) {
                std::cout << "������� ������� �����." << std::endl;
            }
        }
    }
}

void InteractiveExcursion::goToNextObject() {
    // ��� �������������, �.�. ��������� � ������� �� ������ ������������
}

bool InteractiveExcursion::isFinished() {
    return finished;
}
