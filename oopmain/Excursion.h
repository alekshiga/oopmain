#pragma once

#include "SpaceObject.h"
#include <string>

class SpaceObject;

class Excursion {
public:
    virtual SpaceObject* getCurrentObject() = 0;
    virtual void goToNextObject() = 0;
    virtual bool isFinished() = 0;
    virtual ~Excursion() {}
    virtual void startExcursion() = 0;
};
