#pragma once
#ifndef EXCURSION_H
#define EXCURSION_H

#include <vector>
#include <string>
#include "SpaceObject.h"

// интерфейс, который реализуют разные классы экскурсий

class Excursion {
public:
    virtual SpaceObject* getCurrentObject() = 0;
    virtual void goToNextObject() = 0;
    virtual bool isFinished() = 0;
    virtual ~Excursion() {}
};

#endif