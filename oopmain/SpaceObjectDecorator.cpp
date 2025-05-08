#include "SpaceObject.h"
#include "SpaceObjectProxy.h"
#include <iostream>

class SpaceObjectDecorator : public SpaceObject {
protected:
    SpaceObject* decoratedObject; //  Оборачиваем объект

public:
    SpaceObjectDecorator(SpaceObject* object) : decoratedObject(object), SpaceObject(object->audioFile) {}

    void display() override {
        decoratedObject->display(); // Стандартное отображение
    }

    std::string getDescription() override {
        return decoratedObject->getDescription(); //  Стандартное описание
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

// Конкретный декоратор, например подсветка объекта
class HighlightDecorator : public SpaceObjectDecorator {
public:
    HighlightDecorator(SpaceObject* object) : SpaceObjectDecorator(object) {}

    void display() override {
        SpaceObjectDecorator::display();
        std::cout << "  (но уже с подсветкой!)" << std::endl;
    }
};

// Конкретный декоратор, вращение объекта
class RotationDecorator : public SpaceObjectDecorator {
public:
    RotationDecorator(SpaceObject* object) : SpaceObjectDecorator(object) {}

    void display() override {
        SpaceObjectDecorator::display();
        std::cout << "  (и вращением вокруг своей оси!)" << std::endl;
    }
};