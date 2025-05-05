#include "Planet.h"
#include "SpaceObject.h"
#include <iostream>
#include <sstream>
#include <iomanip>

Planet::Planet(std::string name, float radius, bool life, AudioFile* audioFile) : name(name), radius(radius), life(life), SpaceObject(audioFile) {}

void Planet::display() {
    std::cout << "����������� �������: " << name << "\n";
}

void Planet::getAdditionalInfo() {
    std::cout << "�������������� ����������" << std::endl;
    std::cout << "�� ������� ���� �����? ";
    if (life) std::cout << "��" << std::endl;
    else std::cout << "���" << std::endl;
}

std::string Planet::getDescription() {
    std::stringstream stream;
    stream << std::fixed << std::setprecision(1) << radius; // ������������� �������� 1 ���� ����� �������
    std::string radiusString = stream.str();
    return "�������� �������: " + name + ". ������ = " + radiusString + " ��.";
}

std::string Planet::getName() {
    return name;
}

void Planet::playAudio() {
    audioFile->play();
}
