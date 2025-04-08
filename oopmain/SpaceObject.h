#pragma once
#ifndef SPACEOBJECT_H
#define SPACEOBJECT_H

#include <string>
#include "AudioFile.h"

// интерфейс, который реализуют различные типы космических объектов

class SpaceObject {
public:
	AudioFile* audioFile;

	virtual void display() = 0;
	virtual std::string getDescription() = 0;
	virtual ~SpaceObject() {}
	virtual std::string getName() = 0;
	virtual void playAudio() = 0;
};

#endif