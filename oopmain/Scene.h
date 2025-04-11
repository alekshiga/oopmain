#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include <string>
#include "Excursion.h"

class Scene {
private:
    Excursion* currentExcursion;
    
public:
    Scene(Excursion* excursion);
    ~Scene();  // деструктор
    void displayScene();
    std::string getDescription() const;
    Excursion* getCurrentExcursion() const;
    void setCurrentExcursion(Excursion* excursion);
    void requestMoreInfo();
    void startExcursion();
};

#endif