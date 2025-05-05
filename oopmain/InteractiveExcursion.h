#ifndef INTERACTIVEEXCURSION_H
#define INTERACTIVEEXCURSION_H

#include "Excursion.h"
#include "SpaceObject.h"
#include <string>
#include <vector>

class SpaceObject;

class InteractiveExcursion : public Excursion {
private:
    std::vector<SpaceObject*> availableObjects;
    SpaceObject* currentObject;
    std::string description;
    bool finished;

    void getToObject(int n);

public:
    InteractiveExcursion(std::vector<SpaceObject*> availableObjects, std::string description);

    std::vector<SpaceObject*> getRoute();
    void chooseNextObject(SpaceObject* nextObject);
    SpaceObject* getCurrentObject() override;
    std::string getDescription();
    void startExcursion() override;
    void goToNextObject() override;
    bool isFinished() override;
};

#endif
