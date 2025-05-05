#pragma once

#include "SpaceObject.h"
#include <string>

class Asteroid : public SpaceObject {
private:
    std::string name;
    std::string composition; // Состав породы

public:
    Asteroid(std::string name, std::string composition, AudioFile* audioFile);

    void display() override;
    void getAdditionalInfo() override;
    std::string getDescription() override;
    std::string getName() override;
    void playAudio() override;
};
