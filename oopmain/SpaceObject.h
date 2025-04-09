#pragma once
#ifndef SPACEOBJECT_H
#define SPACEOBJECT_H

#include <string>
#include "AudioFile.h"
#include "SpaceObjectType.h"

// интерфейс, который реализуют различные типы космических объектов

class SpaceObject {
public:
	AudioFile* audioFile;
	SpaceObjectType type;

	virtual void display() = 0;
	virtual std::string getDescription() = 0;
	virtual ~SpaceObject() {}
	virtual std::string getName() = 0;
	virtual void playAudio() = 0;
	virtual void getAdditionalInfo() = 0;
};

#endif