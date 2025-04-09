#include <iostream>
#define NOMINMAX
#include <windows.h>
#include "SpaceObject.h"
#include "Planet.h"
#include "Star.h"
#include "Satelite.h"
#include "Scene.h"
#include "Excursion.h"
#include "LinearExcursion.h"
#include "User.h"
#include "AudioFile.h"
#include "SpaceObjectProxy.h"
#include <vector>
#include <locale>
#include <limits>

int main() {

    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    SpaceObject* sunProxy = new SpaceObjectProxy("������", 6000, SpaceObjectType::Star);
    SpaceObject* earthProxy = new SpaceObjectProxy("�����", SpaceObjectType::Planet, 6378);
    SpaceObject* marsProxy = new SpaceObjectProxy("����", SpaceObjectType::Planet, 3389);
    SpaceObject* moonProxy = new SpaceObjectProxy("����", "�����", SpaceObjectType::Satelite);

    std::vector<SpaceObject*> objects = {sunProxy , earthProxy, marsProxy, moonProxy};
    LinearExcursion* tour = new LinearExcursion(objects);

    User* user1 = new User("alekshiga", tour);

    // ������ ������������ ��� ��������� ���������� ����� ���� ����� � ����� ��������� � ������ ��� ����� ���������
    while (!user1->getScene()->getCurrentExcursion()->isFinished() == true) {

        Scene* currentScene = user1->getScene();

        if (currentScene->getCurrentExcursion()->getCurrentObject() != nullptr) {

            SpaceObject* currentObject = currentScene->getCurrentExcursion()->getCurrentObject();

            std::cout << "������ ������������: " << currentObject->getName() << "\n";
            currentObject->display();
            currentScene->requestMoreInfo(); // ������ �������������� ���������� �� ������� �� �����
            currentObject->playAudio();

            std::cout << "������� Enter ��� �������� � ���������� �������...";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ������� ������� Enter

        }
        else {
            std::cout << "��������� ��������� (��� ������ ��������)." << std::endl;
            break; // ������� �� �����, ���� ��� ��������
        }

        currentScene->getCurrentExcursion()->goToNextObject();
    }

    // ������� ������, � ��� ���� ������� �������� ������
    delete tour;
    delete sunProxy;
    delete earthProxy;
    delete marsProxy;
    delete moonProxy;
    delete user1;
    
    return 0;
}

