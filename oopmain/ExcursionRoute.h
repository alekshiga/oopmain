#ifndef EXCURSIONROUTE_H
#define EXCURSIONROUTE_H

#include <vector>
#include "SpaceObject.h"
#include "Aggregate.h"

class ExcursionRouteIterator;

class ExcursionRoute : public Aggregate {
private:
    std::vector<SpaceObject*> objects;

public:
    ExcursionRoute(const std::vector<SpaceObject*>& objects);

    int count() const;
    SpaceObject* get(int index) const;
    Iterator* createIterator() override;
    const std::vector<SpaceObject*>& getObjects() const;
    void setObjects(const std::vector<SpaceObject*>& newObjects);
};

#endif