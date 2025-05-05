#pragma once

#include "SpaceObject.h"
#include <string>

class Star : public SpaceObject {
private:
    std::string name;
    int temperature;

public:
    Star(std::string name, int temperature, AudioFile* audioFile);

    void display() override;
    void getAdditionalInfo() override;
    std::string getDescription() override;
    std::string getName() override;
    void playAudio() override;
};
