#include "Asteroid.h"
#include "SpaceObject.h"
#include <iostream>

Asteroid::Asteroid(std::string name, std::string composition, AudioFile* audioFile) : name(name), composition(composition), SpaceObject(audioFile) {}

void Asteroid::display() {
    std::cout << "Отображение астероида: " << name << "\n";
}

void Asteroid::getAdditionalInfo() {
    std::cout << "Дополнительная информация" << std::endl;
    std::cout << "Пока что нет дополнительной информации об астероиде" << std::endl;
}

std::string Asteroid::getDescription() {
    return "Название астероида: " + name + ". Состав: " + composition;
}

std::string Asteroid::getName() {
    return name;
}

void Asteroid::playAudio() {
    audioFile->play();
}
