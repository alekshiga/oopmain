#pragma once
#ifndef QUIZEXCRUSION_H
#define QUIZEXCRUSION_H

#include <iostream>
#include <vector>
#include <string>
#include <random> 
#include <algorithm> 
#include <map>
#include "Excursion.h"

class QuizExcursion : public Excursion {
private:
    std::vector<SpaceObject*> route;
    int currentObjectIndex;
    int questionsPerObject;
    std::map<SpaceObject*, std::vector<std::pair<std::string, std::string>>> questions; //  ������ � �����
    std::mt19937 random;

public:
    QuizExcursion(const std::vector<SpaceObject*>& objects, int questionsPerObject)
        : route(objects), currentObjectIndex(0), questionsPerObject(questionsPerObject), random(std::random_device{}()) {
        // ����� ������� ������� ��� ��������� ����� ����
    }

    ~QuizExcursion() override {} // ����������

    SpaceObject* getCurrentObject() override {
        if (currentObjectIndex < route.size()) {
            return route[currentObjectIndex];
        }
        else {
            return nullptr;
        }
    }

    void goToNextObject() override {
        if (currentObjectIndex < route.size()) {
            currentObjectIndex++;
        }
    }

    bool isFinished() override {
        return currentObjectIndex >= route.size();
    }

    // ����� ��� ��������� �������� ��� �������� �������
    std::vector<std::pair<std::string, std::string>> getQuestionsForCurrentObject() {
        SpaceObject* currentObject = getCurrentObject();
        if (currentObject && questions.count(currentObject)) {
            return questions[currentObject];
        }
        else {
            std::cout << "��� ������� ������� �������� ���" << std::endl;
            return {}; // ���������� ������ ������, ���� ��� ��������
        }
    }

    void setQuestions(const std::map<SpaceObject*, std::vector<std::pair<std::string, std::string>>>& newQuestions) {
        questions = newQuestions;
    }

    // ����� ��� �������� ������
    bool checkAnswer(SpaceObject* object, const std::string& userAnswer) {
        if (questions.count(object)) {
            for (const auto& questionAnswerPair : questions[object]) {
                if (questionAnswerPair.second == userAnswer) { // ���������� � ���������� �������
                    return true;
                }
            }
        }
        return false;
    }

private:
    std::vector<std::string> getRandomizedQuestions(const std::vector<std::string>& questions) {
        std::vector<std::string> randomizedQuestions = questions;
        std::shuffle(randomizedQuestions.begin(), randomizedQuestions.end(), random);
        return randomizedQuestions;
    }

public:
    void startExcursion() override {
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
};

#endif