#pragma once
#ifndef SPACEOBJECT_H
#define SPACEOBJECT_H

#include <string>

// интерфейс, который реализуют различные типы космических объектов

class SpaceObject {
public:
    virtual void display() = 0;
    virtual std::string getDescription() = 0;
    virtual ~SpaceObject() {} // Деструктор
};

#endif