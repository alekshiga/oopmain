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
    //исправлена логическа€ ошибка: если спутник хранит в себе указатель на родительскую планету, то без создани€ родительской планеты невозможно создать спутник
    std::string parentPlanetName;
    AudioFile* audioFile;
    SpaceObjectType type = SpaceObjectType::Satelite;

public:
    Satelite(std::string name, std::string parentPlanetName, AudioFile* audioFile) : name(name), parentPlanetName(parentPlanetName), audioFile(audioFile) {}

    void display() override {
        std::cout << "ќтображение спутника: " << name << "\n";
    }

    std::string getDescription() override {
        return "Ќазвание спутника: " + name + ". ¬ращаетс€ вокруг: " + parentPlanetName + "\n";
    }

    void getAdditionalInfo() override {
        std::cout << "ƒополнительна€ информаци€" << std::endl;
        std::cout << "ѕока что нет дополнительной информации о спутнике" << std::endl;
    }

    std::string getName() override {
        return name;
    }

    void playAudio() override {
        audioFile->play();
    }
};

#endif
