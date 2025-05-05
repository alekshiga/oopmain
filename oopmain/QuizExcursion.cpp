#include "QuizExcursion.h"
#include "SpaceObject.h"
#include <iostream>
#include <random>
#include <algorithm>
#include <limits>

QuizExcursion::QuizExcursion(const std::vector<SpaceObject*>& objects, int questionsPerObject)
    : route(objects), currentObjectIndex(0), questionsPerObject(questionsPerObject), random(std::random_device{}()) {
}

QuizExcursion::~QuizExcursion() {}

SpaceObject* QuizExcursion::getCurrentObject() {
    if (currentObjectIndex < route.size()) {
        return route[currentObjectIndex];
    }
    else {
        return nullptr;
    }
}

void QuizExcursion::goToNextObject() {
    if (currentObjectIndex < route.size()) {
        currentObjectIndex++;
    }
}

bool QuizExcursion::isFinished() {
    return currentObjectIndex >= route.size();
}

std::vector<std::pair<std::string, std::string>> QuizExcursion::getQuestionsForCurrentObject() {
    SpaceObject* currentObject = getCurrentObject();
    if (currentObject && questions.count(currentObject)) {
        return questions[currentObject];
    }
    else {
        std::cout << "��� ������� ������� �������� ���" << std::endl;
        return {}; // ���������� ������ ������, ���� ��� ��������
    }
}

void QuizExcursion::setQuestions(const std::map<SpaceObject*, std::vector<std::pair<std::string, std::string>>>& newQuestions) {
    questions = newQuestions;
}

bool QuizExcursion::checkAnswer(SpaceObject* object, const std::string& userAnswer) {
    if (questions.count(object)) {
        for (const auto& questionAnswerPair : questions[object]) {
            if (questionAnswerPair.second == userAnswer) { // ���������� � ���������� �������
                return true;
            }
        }
    }
    return false;
}

std::vector<std::string> QuizExcursion::getRandomizedQuestions(const std::vector<std::string>& questions) {
    std::vector<std::string> randomizedQuestions = questions;
    std::shuffle(randomizedQuestions.begin(), randomizedQuestions.end(), random);
    return randomizedQuestions;
}

void QuizExcursion::startExcursion() {
    while (!isFinished()) {
        SpaceObject* currentObject = getCurrentObject();
        if (currentObject) {
            std::cout << "������: " << currentObject->getName() << std::endl;
            auto questionAnswerPairs = getQuestionsForCurrentObject();

            if (!questionAnswerPairs.empty()) {
                std::string question = questionAnswerPairs[0].first; // ����� ������ ������
                std::string correctAnswer = questionAnswerPairs[0].second; // ����� ������ �����

                std::cout << "������: " << question << std::endl;
                std::string userAnswer;
                std::cout << "��� �����: ";
                std::getline(std::cin, userAnswer);

                // ��������� ����� � ����������� �������, ���� ���������
                if (checkAnswer(currentObject, userAnswer)) {
                    std::cout << "���������!" << std::endl;
                    // user->increaseRating();  // ����������� ������� ������������.  ��� ����� user?
                    // �����: ����� ��������� �� User, ����� ��������� �������!
                }
                else {
                    std::cout << "�����������. ���������� �����: " << correctAnswer << std::endl;
                }
            }

            goToNextObject();
        }
        else {
            std::cout << "��������� ��������." << std::endl;
            break;
        }
    }
}
