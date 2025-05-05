#ifndef RANDOMEXCURSION_H
#define RANDOMEXCURSION_H

#include "SpaceObject.h"
#include "Excursion.h"
#include <string>
#include <vector>
#include <random>

class SpaceObject;

class RandomExcursion : public Excursion {
private:
    std::vector<SpaceObject*> route;
    std::mt19937 random;
    int currentObjectIndex = 0;
    bool finished = false;

public:
    RandomExcursion(const std::vector<SpaceObject*>& objects);
    ~RandomExcursion();

    SpaceObject* getCurrentObject();
    void goToNextObject();
    bool isFinished();
    void finishExcursion();
    void startExcursion();
};

#endif
