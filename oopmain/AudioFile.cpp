#include "AudioFile.h"
#include "SpaceObject.h"
#include <iostream>

AudioFile::AudioFile(std::string fileName, int volume) : fileName(fileName), volume(volume) {}

void AudioFile::play() {
    std::cout << "Проигрывание аудио: " << fileName << " на громкости " << volume << "\n";
}

void AudioFile::stop() {
    std::cout << "Остановка аудио: " << fileName << "\n";
}

void AudioFile::setVolume(int volume) {
    this->volume = volume;
    std::cout << "Громкость: " << volume << "\n";
}
