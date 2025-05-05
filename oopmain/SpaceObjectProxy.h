#pragma once

#include <string>
#include "SpaceObject.h"
#include "SpaceObjectType.h"

class SpaceObjectProxy : public SpaceObject {
private:
    std::string name;
    float radius;
    bool life;
    int temperature;
    std::string composition;
    std::string parentPlanetName;
    SpaceObjectType type;
    SpaceObject* realObject; // указатель на реальный объект

    void load(); // Метод для создания реального объекта

public:
    // перегрузки конструкторов для разных типов
    SpaceObjectProxy(std::string name, SpaceObjectType type, bool life, float radius);
    SpaceObjectProxy(std::string name, int temperature, SpaceObjectType type);
    SpaceObjectProxy(std::string name, std::string planetName, SpaceObjectType type);
    SpaceObjectProxy(std::string name, SpaceObjectType type, std::string composition);

    ~SpaceObjectProxy() override;

    void display() override;
    void getAdditionalInfo() override;
    void playAudio() override;
    std::string getDescription() override;
    std::string getName() override;
};
