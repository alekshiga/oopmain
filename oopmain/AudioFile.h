#pragma once
#ifndef AUDIOFILE_H
#define AUDIOFILE_H
#include <iostream>

class AudioFile {
private:
    std::string filePath;
    int volume;

public:
    AudioFile(std::string filePath, int volume) : filePath(filePath), volume(volume) {}

    void play() {
        std::cout << "������������ �����: " << filePath << " �� ��������� " << volume << "\n";
    }
    
    void stop() {
        std::cout << "��������� �����: " << filePath << "\n";
    }
    void setVolume(int volume) {
        this->volume = volume;
        std::cout << "���������: " << volume << "\n";
    };
};




#endif