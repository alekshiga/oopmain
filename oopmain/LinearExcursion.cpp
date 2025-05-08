#include "LinearExcursion.h"
#include "SpaceObject.h"
#include "AudioFile.h"
#include "ExcursionRoute.h"
#include <iostream>

LinearExcursion::LinearExcursion(ExcursionRoute* route)
    : Excursion(route),   // Вызываем конструктор Excursion с route
    route(route),
    iterator(route->createIterator()) {
}

LinearExcursion::~LinearExcursion() {
    delete iterator;
}

SpaceObject* LinearExcursion::getCurrentObject() {
    if (!iterator->isDone()) {
        return iterator->current();
    }
    else {
        return nullptr; // Экскурсия закончена
    }
}

void LinearExcursion::goToNextObject() {
    iterator->next();
}

bool LinearExcursion::isFinished() {
    return iterator->isDone();
}

void LinearExcursion::startExcursion() {
    for (SpaceObject* object = iterator->first(); !iterator->isDone(); object = iterator->next()) {
        object->display();
        if (object->audioFile) object->audioFile->play();
    }
}
