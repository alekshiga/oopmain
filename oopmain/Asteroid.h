#pragma once

#include "SpaceObject.h"
#include <iostream>


class Asteroid : public SpaceObject {
private:
    std::string name;
    std::string composition; // ������ ������
    AudioFile* audioFile;

public:
    Asteroid(std::string name, std::string composition, AudioFile* audioFile) : name(name), composition(composition), audioFile(audioFile) {}

    void display() override {
        std::cout << "����������� ���������: " << name << "\n";
    }

    std::string getDescription() override {
        return "�������� ���������: " + name + ". ������: " + composition;
    }

    std::string getName() override {
        return name;
    }

    void playAudio() override {
        audioFile->play();
    }
};