#pragma once

#include "SpaceObject.h"
#include <string>

class Satelite : public SpaceObject {
private:
    std::string name;
    std::string parentPlanetName;

public:
    Satelite(std::string name, std::string parentPlanetName, AudioFile* audioFile);

    void display() override;
    std::string getDescription() override;
    void getAdditionalInfo() override;
    std::string getName() override;
    void playAudio() override;
};
