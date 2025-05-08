#ifndef RANDOMEXCURSION_H
#define RANDOMEXCURSION_H

#include "SpaceObject.h"
#include "Excursion.h"
#include "ExcursionRoute.h"
#include "Iterator.h"
#include <string>
#include <vector>
#include <random>

class RandomExcursion : public Excursion {
private:
    ExcursionRoute* route;
    Iterator* iterator; 
    std::mt19937 random;
    bool finished = false;

public:
    RandomExcursion(ExcursionRoute* route);
    ~RandomExcursion() override;

    SpaceObject* getCurrentObject();
    void goToNextObject();
    bool isFinished();
    void finishExcursion();
    void startExcursion();
};

#endif