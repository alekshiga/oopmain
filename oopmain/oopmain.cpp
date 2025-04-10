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
#include "RandomExcursion.h"
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
    std::map<SpaceObject*, std::vector<std::pair<std::string, std::string>>> questions;

    questions[sunProxy] = { {"����� ����������� ����������� ������?", "6000"} };
    questions[earthProxy] = { {"���� �� ����� �� �����?", "��"} };
    questions[marsProxy] = { {"���� �� ����� �� �����?", "���"} };

    quizExcursion->setQuestions(questions);

    std::cout << "����� ����-���������!" << std::endl;
    User* user1 = new User("alekshiga", quizExcursion);

    while (!quizExcursion->isFinished()) {
        SpaceObject* currentObject = quizExcursion->getCurrentObject();
        if (currentObject) {
            std::cout << "������: " << currentObject->getName() << std::endl;
            auto questionAnswerPairs = quizExcursion->getQuestionsForCurrentObject();

            if (!questionAnswerPairs.empty()) {
                std::string question = questionAnswerPairs[0].first; // ����� ������ ������
                std::string correctAnswer = questionAnswerPairs[0].second; // ����� ������ �����

                std::cout << "������: " << question << std::endl;
                std::string userAnswer;
                std::cout << "��� �����: ";
                std::getline(std::cin, userAnswer);

                // ��������� ����� � ����������� �������, ���� ���������
                if (quizExcursion->checkAnswer(currentObject, userAnswer)) {
                    std::cout << "���������!" << std::endl;
                    user1->increaseRating();  // ����������� ������� ������������
                }
                else {
                    std::cout << "�����������. ���������� �����: " << correctAnswer << std::endl;
                }
            }

            quizExcursion->goToNextObject();
        }
        else {
            std::cout << "��������� ��������." << std::endl;
            break;
        }
    }
    std::cout << "�������� �������: " << user1->getRating() << std::endl; // ������� �������� �������

    std::cout << "����� ��������� ��������� ���������!" << std::endl;

    RandomExcursion* randomExcursion = new RandomExcursion(objects);
    user1->setExcursion(randomExcursion);
    char choice;
    while (!randomExcursion->isFinished()) {
        SpaceObject* currentObject = randomExcursion->getCurrentObject();
        if (currentObject) {
            std::cout << user1->getUsername() << " �����������: " << currentObject->getName() << std::endl;
        }
        else {
            std::cout << "��������� ���������." << std::endl;
            break;
        }

        std::cout << "�������� ������ ������? (y/n): ";
        std::cin >> choice;

        if (choice == 'n') {
            randomExcursion->finishExcursion();
        }
        else if (choice == 'y') {
            continue;
        }
        else {
            std::cout << "������������ ����." << std::endl;
            randomExcursion->finishExcursion();
        }
    }

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
    delete randomExcursion;
    delete quizExcursion;
    
    return 0;
}

