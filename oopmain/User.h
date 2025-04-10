#pragma once
#ifndef VISITOR_H
#define VISITOR_H

#include "SpaceObject.h"
#include <string>
#include <iostream>

class User {
private:
    std::string username;
    int rating;
    Scene* scene; // собственная сцена у каждого пользователя

public:
    User(std::string username, Excursion* excursion) : username(username) {
        rating = 0;
        scene = new Scene(excursion);
    }
    void visit(SpaceObject* spaceObject) {
        std::cout << username << " посещает Космический объект. Информация о посещаемом объекте: ";
        std::cout << spaceObject->getDescription() << std::endl;
    }

    Scene* getScene() const {
        return scene;
    }

    void setExcursion(Excursion* excursion) {
        this->scene->setCurrentExcursion(excursion);
    }

    std::string getUsername() const {
        return this->username;
    }

    int getRating() const {
        return this->rating;
    }

    void increaseRating() {
        this->rating++;
    }
};

#endif