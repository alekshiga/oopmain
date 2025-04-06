#pragma once
#ifndef VISITOR_H
#define VISITOR_H

#include "SpaceObject.h"
#include <string>
#include <iostream>

class Visitor {
private:
    std::string name;
    int rating;

public:
    Visitor(std::string name) : name(name) {
        rating = 0;
    }
    void visit(SpaceObject* spaceObject) {
        std::cout << name << " посещает Космический объект. Информация о посещаемом объекте: ";
        std::cout << spaceObject->getDescription() << std::endl;
    }
};

#endif