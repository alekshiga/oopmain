#ifndef SCENE_H
#define SCENE_H

#include "SpaceObject.h"
#include "Excursion.h"
#include <string>

class Scene {
private:
    Excursion* currentExcursion;

public:
    Scene(Excursion* excursion);
    ~Scene();
    void displayScene();
    std::string getDescription() const;
    Excursion* getCurrentExcursion() const;
    void setCurrentExcursion(Excursion* excursion);
    void requestMoreInfo();
    void startExcursion();
};

#endif
