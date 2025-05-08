#pragma once

#include "Excursion.h"
#include "SpaceObject.h"
#include "ExcursionRoute.h"
#include "Iterator.h"
#include <string>
#include <vector>

class LinearExcursion : public Excursion {
private:
    ExcursionRoute* route;
    Iterator* iterator;

public:
    LinearExcursion(ExcursionRoute* route);
    ~LinearExcursion() override;

    SpaceObject* getCurrentObject() override;
    void goToNextObject() override;
    bool isFinished() override;
    void startExcursion() override;
};