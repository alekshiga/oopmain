#include "LinearExcursion.h"
#include "SpaceObject.h"
#include "AudioFile.h"
#include <iostream>

LinearExcursion::LinearExcursion(const std::vector<SpaceObject*>& objects) : route(objects), currentObjectIndex(0) {}

SpaceObject* LinearExcursion::getCurrentObject() {
    if (currentObjectIndex < route.size()) {
        return route[currentObjectIndex];
    }
    else {
        return nullptr; // Ёкскурси€ закончена
    }
}

void LinearExcursion::goToNextObject() {
    if (currentObjectIndex < route.size()) {
        currentObjectIndex++;
    }
}

bool LinearExcursion::isFinished() {
    return currentObjectIndex >= route.size();
}

void LinearExcursion::startExcursion() {
    for (SpaceObject* object : route) {
        object->display();
        object->audioFile->play();
    }
}
