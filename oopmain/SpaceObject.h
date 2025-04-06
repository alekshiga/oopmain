#pragma once
#ifndef SPACEOBJECT_H
#define SPACEOBJECT_H

#include <string>

// ���������, ������� ��������� ��������� ���� ����������� ��������

class SpaceObject {
public:
    virtual void display() = 0;
    virtual std::string getDescription() = 0;
    virtual ~SpaceObject() {} // ����������
};

#endif