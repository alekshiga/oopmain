#include "Star.h"
#include "SpaceObject.h"
#include <iostream>
#include <sstream>
#include <iomanip>

Star::Star(std::string name, int temperature, AudioFile* audioFile) : name(name), temperature(temperature), SpaceObject(audioFile) {}

void Star::display() {
    std::cout << "����������� ������: " << name << "\n";
}

void Star::getAdditionalInfo() {
    std::cout << "�������������� ����������" << std::endl;
    std::cout << "���� ��� ��� �������������� ���������� � ������" << std::endl;
}

std::string Star::getDescription() {
    return "�������� ������ " + name + ". ����������� = " + std::to_string(temperature) + " C.";
}

std::string Star::getName() {
    return name;
}

void Star::playAudio() {
    audioFile->play();
}
