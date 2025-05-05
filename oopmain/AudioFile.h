#pragma once

#include <string>

class AudioFile {
private:
    std::string fileName;
    int volume;

public:
    AudioFile(std::string fileName, int volume);

    void play();
    void stop();
    void setVolume(int volume);
};
