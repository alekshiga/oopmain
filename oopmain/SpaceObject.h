#pragma once

#include <string>
#include "AudioFile.h"
#include "SpaceObjectType.h"

class SpaceObject {
public:
    SpaceObject(AudioFile* audioFile);
    virtual ~SpaceObject();

    virtual void display() = 0;
    virtual std::string getDescription() = 0;
    virtual std::string getName() = 0;
    virtual void playAudio() = 0;
    virtual void getAdditionalInfo() = 0;
    AudioFile* audioFile;

};
