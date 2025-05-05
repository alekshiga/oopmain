#include "AudioFile.h"
#include "SpaceObject.h"
#include <iostream>

AudioFile::AudioFile(std::string fileName, int volume) : fileName(fileName), volume(volume) {}

void AudioFile::play() {
    std::cout << "������������ �����: " << fileName << " �� ��������� " << volume << "\n";
}

void AudioFile::stop() {
    std::cout << "��������� �����: " << fileName << "\n";
}

void AudioFile::setVolume(int volume) {
    this->volume = volume;
    std::cout << "���������: " << volume << "\n";
}
