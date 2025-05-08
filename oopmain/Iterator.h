#pragma once
#ifndef ITERATOR_H
#define ITERATOR_H

#include "SpaceObject.h"

class Iterator {
public:
	virtual SpaceObject* first() = 0;
	virtual SpaceObject* next() = 0;
	virtual bool isDone() = 0;
	virtual SpaceObject* current() = 0;
	virtual ~Iterator() {}
};

#endif