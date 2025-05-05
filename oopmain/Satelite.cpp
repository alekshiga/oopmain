#include "Satelite.h"
#include "SpaceObject.h"
#include <iostream>

Satelite::Satelite(std::string name, std::string parentPlanetName, AudioFile* audioFile) : name(name), parentPlanetName(parentPlanetName), SpaceObject(audioFile) {}

void Satelite::display() {
    std::cout << "����������� ��������: " << name << "\n";
}

std::string Satelite::getDescription() {
    return "�������� ��������: " + name + ". ��������� ������: " + parentPlanetName + "\n";
}

void Satelite::getAdditionalInfo() {
    std::cout << "�������������� ����������" << std::endl;
    std::cout << "���� ��� ��� �������������� ���������� � ��������" << std::endl;
}

std::string Satelite::getName() {
    return name;
}

void Satelite::playAudio() {
    audioFile->play();
}
