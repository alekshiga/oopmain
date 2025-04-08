#pragma once
#ifndef AUDIOFILE_H
#define AUDIOFILE_H
#include <iostream>

class AudioFile {
private:
    std::string fileName;
    int volume;

public:
    AudioFile(std::string fileName, int volume) : fileName(fileName), volume(volume) {}

    void play() {
        std::cout << "Проигрывание аудио: " << fileName << " на громкости " << volume << "\n";
    }
    
    void stop() {
        std::cout << "Остановка аудио: " << fileName << "\n";
    }
    void setVolume(int volume) {
        this->volume = volume;
        std::cout << "Громкость: " << volume << "\n";
    };
};




#endif