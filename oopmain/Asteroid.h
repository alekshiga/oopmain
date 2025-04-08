#pragma once

#include "SpaceObject.h"
#include <iostream>


class Asteroid : public SpaceObject {
private:
    std::string name;
    std::string composition; // Состав породы
    AudioFile* audioFile;

public:
    Asteroid(std::string name, std::string composition, AudioFile* audioFile) : name(name), composition(composition), audioFile(audioFile) {}

    void display() override {
        std::cout << "Отображение астероида: " << name << "\n";
    }

    std::string getDescription() override {
        return "Название астероида: " + name + ". Состав: " + composition;
    }

    std::string getName() override {
        return name;
    }

    void playAudio() override {
        audioFile->play();
    }
};