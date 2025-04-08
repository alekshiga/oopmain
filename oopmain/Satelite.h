#pragma once
#ifndef SATELITE_H
#define SATELITE_H

#include <iostream>
#include <sstream>
#include <iomanip>
#include "SpaceObject.h"
#include "Planet.h"

class Satelite : public SpaceObject {
private:
    std::string name;
    Planet* planet;
    AudioFile* audioFile;

public:
    Satelite(std::string name, Planet* planet, AudioFile* audioFile) : name(name), planet(planet), audioFile(audioFile) {}

    void display() override {
        std::cout << "Отображение спутника: " << name << "\n";
    }

    std::string getDescription() override {
        return "Название спутника: " + name + ". Вращается вокруг: " + planet->getName() + "\n";
    }

    std::string getName() override {
        return name;
    }

    void playAudio() override {
        audioFile->play();
    }
};

#endif
