#include "RandomExcursion.h"
#include "SpaceObject.h"
#include "Iterator.h"
#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <limits>

RandomExcursion::RandomExcursion(ExcursionRoute* route)
    : route(route),
    random(std::random_device{}()),
    iterator(nullptr)
{
    std::vector<SpaceObject*> tempObjects = route->getObjects();
    std::shuffle(tempObjects.begin(), tempObjects.end(), random);

    route->setObjects(tempObjects);
    iterator = route->createIterator();

    if (iterator) {
        iterator->first();
    }
}

RandomExcursion::~RandomExcursion() {
    delete iterator;
}

SpaceObject* RandomExcursion::getCurrentObject() {
    if (iterator && !iterator->isDone()) {
        return iterator->current();
    }
    return nullptr;
}

void RandomExcursion::goToNextObject() {
    if (iterator) {
        iterator->next();
    }
}

bool RandomExcursion::isFinished() {
    return !iterator || iterator->isDone();
}

void RandomExcursion::finishExcursion() {
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
                    break;
                }
                else {
                    std::cout << "������������ ����. ����������, ������� 'y' ��� 'n'." << std::endl;
                }
            }
            if (choice == 'n') break;
        }
        else {
            std::cout << "��������� ���������." << std::endl;
            break;
        }
    }
}

