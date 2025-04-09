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
#include "QuizExcursion.h"
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
    SpaceObject* earthProxy = new SpaceObjectProxy("�����", SpaceObjectType::Planet, true, 6378);
    SpaceObject* marsProxy = new SpaceObjectProxy("����", SpaceObjectType::Planet, false, 3389);
    SpaceObject* moonProxy = new SpaceObjectProxy("����", "�����", SpaceObjectType::Satelite);

    std::vector<SpaceObject*> objects = {sunProxy , earthProxy, marsProxy, moonProxy};

    //LinearExcursion* tour = new LinearExcursion(objects);
    QuizExcursion* quizExcursion = new QuizExcursion(objects, 1);

    //������ ������ ��������
    std::vector<std::pair<SpaceObject*, std::vector<std::string>>> questions;

    questions.push_back({ sunProxy, {"����� ����������� ����������� ������?"}});
    questions.push_back({ earthProxy, {"���� �� ����� �� �����?"} });
    questions.push_back({ marsProxy, {"���� �� ����� �� �����?"} });

    quizExcursion->setQuestions(questions);

    User* user1 = new User("alekshiga", quizExcursion);

    while (!quizExcursion->isFinished()) {
        SpaceObject* currentObject = quizExcursion->getCurrentObject();

        if (currentObject != nullptr) {
            std::cout << "������� ��� " << currentObject->getName() << ":" << std::endl;
            std::vector<std::string> currentQuestions = quizExcursion->getQuestionsForCurrentObject();

            if (!currentQuestions.empty()) {
                for (size_t i = 0; i < currentQuestions.size(); ++i) { // ���������� size_t ��� ��������
                    std::cout << "- " << currentQuestions[i] << std::endl;
                }

                std::string answer;
                std::cout << "��� �����: ";
                std::getline(std::cin, answer); // ������ ������ ������� (������� �������)

                // �����: ��������� � ���������� ������� ������ ����� ������ �� ������
                quizExcursion->goToNextObject();

            }
            else {
                quizExcursion->goToNextObject(); // ��� ����� ��������� � ���������� �������
            }
        }
        else {
            std::cout << "��������� ���������." << std::endl;
            break; // ������� �� �����
        }
    }

    std::cout << "��������� ���������!" << std::endl;

    //// ������ ������������ ��� ��������� ���������� ����� ���� ����� � ����� ��������� � ������ ��� ����� ���������
    //while (!user1->getScene()->getCurrentExcursion()->isFinished() == true) {

    //    Scene* currentScene = user1->getScene();

    //    if (currentScene->getCurrentExcursion()->getCurrentObject() != nullptr) {

    //        SpaceObject* currentObject = currentScene->getCurrentExcursion()->getCurrentObject();

    //        std::cout << "������ ������������: " << currentObject->getName() << "\n";
    //        currentObject->display();
    //        currentScene->requestMoreInfo(); // ������ �������������� ���������� �� ������� �� �����
    //        currentObject->playAudio();

    //        std::cout << "������� Enter ��� �������� � ���������� �������...";
    //        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ������� ������� Enter

    //    }
    //    else {
    //        std::cout << "��������� ��������� (��� ������ ��������)." << std::endl;
    //        break; // ������� �� �����, ���� ��� ��������
    //    }

    //    currentScene->getCurrentExcursion()->goToNextObject();
    //}

    // ������� ������, � ��� ���� ������� �������� ������
    //delete tour;
    delete sunProxy;
    delete earthProxy;
    delete marsProxy;
    delete moonProxy;
    delete user1;
    
    return 0;
}

