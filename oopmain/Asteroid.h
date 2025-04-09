#pragma once

#include "SpaceObject.h"
#include <iostream>


class Asteroid : public SpaceObject {
private:
    std::string name;
    std::string composition; // Состав породы
    AudioFile* audioFile;
    SpaceObjectType type = SpaceObjectType::Asteroid;

public:
    Asteroid(std::string name, std::string composition, AudioFile* audioFile) : name(name), composition(composition), audioFile(audioFile) {}

    void display() override {
        std::cout << "Отображение астероида: " << name << "\n";
    }

    void getAdditionalInfo() override {
        std::cout << "Дополнительная информация" << std::endl;
        std::cout << "Пока что нет дополнительной информации об астероиде" << std::endl;
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