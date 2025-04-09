#pragma once
#ifndef PLANET_H
#define PLANET_H

#include <iostream>
#include <sstream>
#include <iomanip>
#include "SpaceObject.h"
#include "SpaceObjectType.h"


class Planet : public SpaceObject {
private:
    std::string name;
    float radius;
    AudioFile* audioFile;
    SpaceObjectType type = SpaceObjectType::Planet;
    bool life;

public:
    Planet(std::string name, float radius, bool life, AudioFile* audioFile) : name(name), radius(radius), audioFile(audioFile), life(life) {}

    void display() override {
        std::cout << "Отображение планеты: " << name << "\n";
    }

    void getAdditionalInfo() override {
        std::cout << "Дополнительная информация" << std::endl;
        std::cout << "На планете есть жизнь? ";
        if (life) std::cout << "Да" << std::endl;
        else std::cout << "Нет" << std::endl;
    }

    std::string getDescription() override {
        std::stringstream stream;
        stream << std::fixed << std::setprecision(1) << radius; // Устанавливаем точность 1 знак после запятой
        std::string radiusString = stream.str();
        return "Название планеты: " + name + ". Радиус = " + radiusString + " км.";
    }

    std::string getName() override {
        return name;
    }

    void playAudio() override {
        audioFile->play();
    }
};

#endif