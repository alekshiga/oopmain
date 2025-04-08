#include <iostream>
#include "SpaceObject.h"
#include "Planet.h"
#include "Star.h"
#include "Satelite.h"
#include "Scene.h"
#include "Excursion.h"
#include "LinearExcursion.h"
#include "Visitor.h"
#include "AudioFile.h"
#include "SpaceObjectProxy.h"
#include <vector>
#include <windows.h>
#include <locale>

int main() {

    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    //SpaceObject* sunProxy = new SpaceObjectProxy("������", 6000, SpaceObjectType::Star);
    SpaceObject* earthProxy = new SpaceObjectProxy("�����", SpaceObjectType::Planet, 6378);
    SpaceObject* marsProxy = new SpaceObjectProxy("����", SpaceObjectType::Planet, 3389);
    SpaceObject* moonProxy = new SpaceObjectProxy("����", "�����", SpaceObjectType::Satelite);

    std::vector<SpaceObject*> objects = { /*sunProxy ,*/ earthProxy, marsProxy, moonProxy};
    LinearExcursion* tour = new LinearExcursion(objects);

    while (!tour->isFinished()) {
        SpaceObject* current = tour->getCurrentObject();
        if (current != nullptr) {
            std::cout << "������ ������������: " << current->getName() << "\n";
            current->display();
            current->playAudio();
            std::cout << current->getDescription() << "\n";
        }
        tour->goToNextObject();
    }

    // ������� ������, � ��� ���� ������� �������� ������
    delete tour;
    //delete sunProxy;
    delete earthProxy;
    delete marsProxy;
    delete moonProxy;
    
    return 0;
}

