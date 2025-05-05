#ifndef USER_H
#define USER_H

#include "SpaceObject.h"
#include <string>

class SpaceObject;
class Scene;
class Excursion;

class User {
private:
    std::string username;
    int rating;
    Scene* scene; // собственная сцена у каждого пользователя

public:
    User(std::string username, Excursion* excursion);

    void visit(SpaceObject* spaceObject);
    Scene* getScene() const;
    void setExcursion(Excursion* excursion);
    std::string getUsername() const;
    int getRating() const;
    void increaseRating();
};

#endif
