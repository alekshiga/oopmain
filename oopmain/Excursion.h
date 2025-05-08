#pragma once

#include "SpaceObject.h"
#include "ExcursionRoute.h"
#include <string>
#include <iostream>

class Excursion {
public:
    Excursion(ExcursionRoute* route) : route(route) {}

    virtual SpaceObject* getCurrentObject() = 0;
    virtual void goToNextObject() = 0;
    virtual bool isFinished() = 0;
    virtual ~Excursion() {}
    virtual void startExcursion() {
        std::cout << "Начало абстрактной экскурсии" << std::endl;
    }

protected:
    ExcursionRoute* route;
};