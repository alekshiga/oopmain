#include "ExcursionRoute.h"
#include "ExcursionRouteIterator.h"
#include <iostream>

ExcursionRoute::ExcursionRoute(const std::vector<SpaceObject*>& objects) : objects(objects) {}

int ExcursionRoute::count() const {
    return objects.size();
}

SpaceObject* ExcursionRoute::get(int index) const {
    if (index >= 0 && index < objects.size()) {
        return objects[index];
    }
    return nullptr;
}

Iterator* ExcursionRoute::createIterator() {
    return new ExcursionRouteIterator(this);
}

const std::vector<SpaceObject*>& ExcursionRoute::getObjects() const {
    return objects;
}

void ExcursionRoute::setObjects(const std::vector<SpaceObject*>& newObjects) {
    objects = newObjects;
}