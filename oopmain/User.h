#pragma once
#ifndef VISITOR_H
#define VISITOR_H

#include "SpaceObject.h"
#include <string>
#include <iostream>

class User {
private:
    std::string name;
    int rating;
    Scene* scene; // собственная сцена у каждого пользователя

public:
    User(std::string name, Excursion* excursion) : name(name) {
        rating = 0;
        scene = new Scene(excursion);
    }
    void visit(SpaceObject* spaceObject) {
        std::cout << name << " посещает Космический объект. Информация о посещаемом объекте: ";
        std::cout << spaceObject->getDescription() << std::endl;
    }

    Scene* getScene() {
        return scene;
    }
};

#endif