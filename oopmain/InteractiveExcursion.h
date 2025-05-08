#ifndef INTERACTIVEEXCURSION_H
#define INTERACTIVEEXCURSION_H

#include "Excursion.h"
#include "SpaceObject.h"
#include "ExcursionRoute.h"
#include "Iterator.h"
#include <string>
#include <vector>

class SpaceObject;

class InteractiveExcursion : public Excursion {
private:
    ExcursionRoute* availableObjectsRoute; 
    SpaceObject* currentObject;
    std::string description;
    bool finished;

    void getToObject(int n);

public:
    InteractiveExcursion(ExcursionRoute* availableObjectsRoute, std::string description);
    ~InteractiveExcursion() override;

    std::vector<SpaceObject*> getRoute();
    void chooseNextObject(SpaceObject* nextObject);
    SpaceObject* getCurrentObject() override;
    std::string getDescription();
    void startExcursion() override;
    void goToNextObject() override;
    bool isFinished() override;
};

#endif