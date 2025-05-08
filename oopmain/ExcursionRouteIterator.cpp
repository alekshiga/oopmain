#include "ExcursionRouteIterator.h"
#include "ExcursionRoute.h" 

ExcursionRouteIterator::ExcursionRouteIterator(ExcursionRoute* route) : route(route) {}

SpaceObject* ExcursionRouteIterator::first() {
    currentPosition = 0;
    return route->get(currentPosition);
}

SpaceObject* ExcursionRouteIterator::next() {
    currentPosition++;
    if (!isDone()) {
        return route->get(currentPosition);
    }
    return nullptr;
}

bool ExcursionRouteIterator::isDone() {
    return currentPosition >= route->count();
}

SpaceObject* ExcursionRouteIterator::current() {
    return route->get(currentPosition);
}