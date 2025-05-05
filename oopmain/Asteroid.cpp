#include "Asteroid.h"
#include "SpaceObject.h"
#include <iostream>

Asteroid::Asteroid(std::string name, std::string composition, AudioFile* audioFile) : name(name), composition(composition), SpaceObject(audioFile) {}

void Asteroid::display() {
    std::cout << "����������� ���������: " << name << "\n";
}

void Asteroid::getAdditionalInfo() {
    std::cout << "�������������� ����������" << std::endl;
    std::cout << "���� ��� ��� �������������� ���������� �� ���������" << std::endl;
}

std::string Asteroid::getDescription() {
    return "�������� ���������: " + name + ". ������: " + composition;
}

std::string Asteroid::getName() {
    return name;
}

void Asteroid::playAudio() {
    audioFile->play();
}
