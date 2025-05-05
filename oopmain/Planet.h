#pragma once

#include "SpaceObject.h"
#include <string>

class Planet : public SpaceObject {
private:
    std::string name;
    float radius;
    bool life;

public:
    Planet(std::string name, float radius, bool life, AudioFile* audioFile);

    void display() override;
    void getAdditionalInfo() override;
    std::string getDescription() override;
    std::string getName() override;
    void playAudio() override;
};
