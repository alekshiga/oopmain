#pragma once

#include "Excursion.h"
#include "SpaceObject.h"
#include <string>
#include <vector>

class LinearExcursion : public Excursion {
private:
    std::vector<SpaceObject*> route;
    int currentObjectIndex;

public:
    LinearExcursion(const std::vector<SpaceObject*>& objects);

    SpaceObject* getCurrentObject() override;
    void goToNextObject() override;
    bool isFinished() override;
    void startExcursion() override;
};
