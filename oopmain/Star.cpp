#include "Star.h"
#include "SpaceObject.h"
#include <iostream>
#include <sstream>
#include <iomanip>

Star::Star(std::string name, int temperature, AudioFile* audioFile) : name(name), temperature(temperature), SpaceObject(audioFile) {}

void Star::display() {
    std::cout << "Отображение звезды: " << name << "\n";
}

void Star::getAdditionalInfo() {
    std::cout << "Дополнительная информация" << std::endl;
    std::cout << "Пока что нет дополнительной информации о звезде" << std::endl;
}

std::string Star::getDescription() {
    return "Название звезды " + name + ". Температура = " + std::to_string(temperature) + " C.";
}

std::string Star::getName() {
    return name;
}

void Star::playAudio() {
    audioFile->play();
}
