#include "Satelite.h"
#include "SpaceObject.h"
#include <iostream>

Satelite::Satelite(std::string name, std::string parentPlanetName, AudioFile* audioFile) : name(name), parentPlanetName(parentPlanetName), SpaceObject(audioFile) {}

void Satelite::display() {
    std::cout << "Отображение спутника: " << name << "\n";
}

std::string Satelite::getDescription() {
    return "Название спутника: " + name + ". Вращается вокруг: " + parentPlanetName + "\n";
}

void Satelite::getAdditionalInfo() {
    std::cout << "Дополнительная информация" << std::endl;
    std::cout << "Пока что нет дополнительной информации о спутнике" << std::endl;
}

std::string Satelite::getName() {
    return name;
}

void Satelite::playAudio() {
    audioFile->play();
}
