#ifndef EXCURSIONROUTEITERATOR_H
#define EXCURSIONROUTEITERATOR_H

#include "Iterator.h"
#include "ExcursionRoute.h"

class ExcursionRouteIterator : public Iterator {
private:
	ExcursionRoute* route;
	int currentPosition = 0;

public:
	ExcursionRouteIterator(ExcursionRoute* route);

	SpaceObject* first() override;
	SpaceObject* next() override;
	bool isDone() override;
	SpaceObject* current() override;
};

#endif