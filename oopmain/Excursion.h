#pragma once
#ifndef EXCURSION_H
#define EXCURSION_H

#include <vector>
#include <string>
#include "SpaceObject.h"

// интерфейс, который реализуют разные классы экскурсий

class Excursion {
public:
    virtual std::vector<SpaceObject*> getRoute() = 0;
    virtual SpaceObject* getCurrentObject() = 0;
    virtual std::string getDescription() = 0;
    virtual ~Excursion() {}
};

#endif