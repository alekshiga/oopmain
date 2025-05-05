#include "User.h"
#include "SpaceObject.h"
#include "Scene.h"
#include <iostream>

User::User(std::string username, Excursion* excursion) : username(username) {
    rating = 0;
    scene = new Scene(excursion);
}

void User::visit(SpaceObject* spaceObject) {
    std::cout << username << " посещает Космический объект. Информация о посещаемом объекте: ";
    std::cout << spaceObject->getDescription() << std::endl;
}

Scene* User::getScene() const {
    return scene;
}

void User::setExcursion(Excursion* excursion) {
    this->scene->setCurrentExcursion(excursion);
}

std::string User::getUsername() const {
    return this->username;
}

int User::getRating() const {
    return this->rating;
}

void User::increaseRating() {
    this->rating++;
}
