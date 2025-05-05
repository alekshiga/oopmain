#include "Scene.h"
#include "Excursion.h"
#include "SpaceObject.h"
#include <iostream>

Scene::Scene(Excursion* excursion) : currentExcursion(excursion) {}

Scene::~Scene() {
    delete currentExcursion;
}

void Scene::displayScene() {
    std::cout << "\n*отображение сцены* на сцене сейчас: " << currentExcursion->getCurrentObject()->getDescription() << std::endl;
}

std::string Scene::getDescription() const {
    return "Описание сцены";
}

Excursion* Scene::getCurrentExcursion() const {
    return currentExcursion;
}

void Scene::setCurrentExcursion(Excursion* excursion) {
    currentExcursion = excursion;
}

void Scene::requestMoreInfo() {
    SpaceObject* object = currentExcursion->getCurrentObject();
    object->getAdditionalInfo();
}

void Scene::startExcursion() {
    currentExcursion->startExcursion();
}
