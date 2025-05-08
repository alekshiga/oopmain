#include "InteractiveExcursion.h"
#include "SpaceObject.h"
#include "Iterator.h"
#include <iostream>
#include <limits>

InteractiveExcursion::InteractiveExcursion(ExcursionRoute* availableObjectsRoute, std::string description) : availableObjectsRoute(availableObjectsRoute), currentObject(nullptr), description(description), finished(false) {}

InteractiveExcursion::~InteractiveExcursion() {

    delete availableObjectsRoute;
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

    for (SpaceObject* obj : availableObjects) {  // Смотрим, доступен ли следующий объект
        if (obj == nextObject) {
            found = true;
            break;
        }
    }
    if (found) {
        currentObject = nextObject;
    }
    else {
        std::cerr << "Извините, объект недоступен." << std::endl; // Если объекта нет, то выводим сообщение
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
        std::cerr << "Некорректный номер объекта." << std::endl;
    }
}

void InteractiveExcursion::startExcursion() {
    std::cout << "Добро пожаловать на интерактивную экскурсию!" << std::endl;
    std::cout << description << std::endl;

    while (!finished) {
        std::cout << "\nДоступные объекты:" << std::endl;
        const std::vector<SpaceObject*>& availableObjects = availableObjectsRoute->getObjects(); 
        for (size_t i = 0; i < availableObjects.size(); ++i) {
            std::cout << i + 1 << ". " << availableObjects[i]->getName() << std::endl;
        }

        std::cout << "Введите номер объекта для посещения (или 'q' для выхода): ";
        std::string input;
        std::getline(std::cin, input);

        if (input == "q") {
            finished = true;
            std::cout << "Экскурсия завершена." << std::endl;
        }
        else {
            try {
                int objectNumber = std::stoi(input);
                if (objectNumber > 0 && objectNumber <= availableObjectsRoute->count()) {
                    getToObject(objectNumber);
                    if (currentObject) {
                        std::cout << "Вы посетили: ";
                        currentObject->display();
                    }
                }
                else {
                    std::cout << "Некорректный номер объекта." << std::endl;
                }
            }
            catch (const std::invalid_argument& e) {
                std::cout << "Некорректный ввод. Введите число или 'q'." << std::endl;
            }
            catch (const std::out_of_range& e) {
                std::cout << "Слишком большое число." << std::endl;
            }
        }
    }
}

void InteractiveExcursion::goToNextObject() {
    // Нет необходимости, т.к. переходим к объекту по выбору пользователя
}

bool InteractiveExcursion::isFinished() {
    return finished;
}