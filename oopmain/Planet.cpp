#include "Planet.h"
#include "SpaceObject.h"
#include <iostream>
#include <sstream>
#include <iomanip>

Planet::Planet(std::string name, float radius, bool life, AudioFile* audioFile) : name(name), radius(radius), life(life), SpaceObject(audioFile) {}

void Planet::display() {
    std::cout << "Отображение планеты: " << name << "\n";
}

void Planet::getAdditionalInfo() {
    std::cout << "Дополнительная информация" << std::endl;
    std::cout << "На планете есть жизнь? ";
    if (life) std::cout << "Да" << std::endl;
    else std::cout << "Нет" << std::endl;
}

std::string Planet::getDescription() {
    std::stringstream stream;
    stream << std::fixed << std::setprecision(1) << radius; // Устанавливаем точность 1 знак после запятой
    std::string radiusString = stream.str();
    return "Название планеты: " + name + ". Радиус = " + radiusString + " км.";
}

std::string Planet::getName() {
    return name;
}

void Planet::playAudio() {
    audioFile->play();
}
