#include "SpaceObject.h"
#include "SpaceObjectProxy.h"
#include <iostream>

class SpaceObjectDecorator : public SpaceObject {
protected:
    SpaceObject* decoratedObject; //  ����������� ������

public:
    SpaceObjectDecorator(SpaceObject* object) : decoratedObject(object), SpaceObject(object->audioFile) {}

    void display() override {
        decoratedObject->display(); // ����������� �����������
    }

    std::string getDescription() override {
        return decoratedObject->getDescription(); //  ����������� ��������
    }

    std::string getName() override {
        return decoratedObject->getName();
    }

    void playAudio() override {
        decoratedObject->playAudio();
    }
    void getAdditionalInfo() override {
        decoratedObject->getAdditionalInfo();
    }

};

// ���������� ���������, �������� ��������� �������
class HighlightDecorator : public SpaceObjectDecorator {
public:
    HighlightDecorator(SpaceObject* object) : SpaceObjectDecorator(object) {}

    void display() override {
        SpaceObjectDecorator::display();
        std::cout << "  (�� ��� � ����������!)" << std::endl;
    }
};

// ���������� ���������, �������� �������
class RotationDecorator : public SpaceObjectDecorator {
public:
    RotationDecorator(SpaceObject* object) : SpaceObjectDecorator(object) {}

    void display() override {
        SpaceObjectDecorator::display();
        std::cout << "  (� ��������� ������ ����� ���!)" << std::endl;
    }
};