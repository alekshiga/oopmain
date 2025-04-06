#include "Scene.h"
#include "Excursion.h"
#include "SpaceObject.h"
#include <iostream>
#include <algorithm> 

// ���������� ������� Scene

// ������������� ����������� ����������, ����� ����� �������� �������� �����
Scene* Scene::instance = nullptr;

Scene::Scene(Excursion* excursion) : currentExcursion(excursion) {}

Scene::~Scene() {
    delete currentExcursion;
}

Scene* Scene::getInstance(Excursion* excursion) {
    if (instance == nullptr) {
        instance = new Scene(excursion);
    }
    return instance;
}

void Scene::displayScene() {
    std::cout << "\n*����������� �����* �� ����� ������: " << currentExcursion->getCurrentObject()->getDescription() << std::endl;
}

std::string Scene::getDescription() const {
    return "�������� �����";
}

Excursion* Scene::getCurrentExcursion() const {
    return currentExcursion;
}

void Scene::setCurrentExcursion(Excursion* excursion) {
    currentExcursion = excursion;
}

