#pragma once
#ifndef STAR_H
#define STAR_H

#include "SpaceObject.h"
#include <sstream>
#include <iomanip>
#include <iostream>
#include <string>

class Star : public SpaceObject {
private:
    std::string name;
    int temperature;
    AudioFile* audioFile;
    SpaceObjectType type = SpaceObjectType::Star;

public:
    Star(std::string name, int temperature, AudioFile* audioFile) : name(name), temperature(temperature), audioFile(audioFile) {}

    void display() override {
        std::cout << "Отображение звезды: " << name << "\n";
    }

    void getAdditionalInfo() override {
        std::cout << "Дополнительная информация" << std::endl;
        std::cout << "Пока что нет дополнительной информации о звезде" << std::endl;
    }

    std::string getDescription() override {
        return "Название звезды " + name + ". Температура = " + std::to_string(temperature) + " C.";
    }

    std::string getName() override {
        return name;
    }

    void playAudio() override {
        audioFile->play();
    }
};

#endif