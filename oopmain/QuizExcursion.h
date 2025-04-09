#pragma once
#ifndef QUIZEXCRUSION_H
#define QUIZEXCRUSION_H

#include <iostream>
#include <vector>
#include <string>
#include <random> 
#include <algorithm> 
#include "Excursion.h"

class QuizExcursion : public Excursion {
private:
    std::vector<SpaceObject*> route;
    int currentObjectIndex;
    int questionsPerObject;
    std::vector<std::pair<SpaceObject*, std::vector<std::string>>> questions; // ���� ��� ��������� �������� ��� ������� �������
    std::mt19937 random; // ��������� ��������� �����

public:
    QuizExcursion(const std::vector<SpaceObject*>& objects, int questionsPerObject)
        : route(objects), currentObjectIndex(0), questionsPerObject(questionsPerObject), random(std::random_device{}()) {
        // questions ����������� ����� � ������� setQuestions
        // ��� ����� �������� �� �����
        std::cout << "������� QuizExcursion � " << questionsPerObject << " ��������� �� ������" << std::endl;
    }

    ~QuizExcursion() {} // ����������

    SpaceObject* getCurrentObject() {
        if (currentObjectIndex < route.size()) {
            return route[currentObjectIndex];
        }
        else {
            return nullptr;
        }
    }

    void goToNextObject() {
        if (currentObjectIndex < route.size()) {
            currentObjectIndex++;
        }
    }

    bool isFinished() {
        return currentObjectIndex >= route.size();
    }

    // ����� ��� ��������� �������� ��� �������� �������
    std::vector<std::string> getQuestionsForCurrentObject() {
        SpaceObject* currentObject = getCurrentObject();
        if (currentObject) {
            // ������� ������� ��� �������� �������
            for (const auto& pair : questions) {
                if (pair.first == currentObject) {
                    // ���������� ������������ ������ ��������
                    return getRandomizedQuestions(pair.second);
                }
            }
            std::cout << "��� �������� ��� ������� " << currentObject->getName() << std::endl;
        }
        return {}; // ������ ������ ���� �������� ���
    }

    void setQuestions(const std::vector<std::pair<SpaceObject*, std::vector<std::string>>>& newQuestions) {
        questions = newQuestions;
    }

private:
    std::vector<std::string> getRandomizedQuestions(const std::vector<std::string>& questions) {
        std::vector<std::string> randomizedQuestions = questions;
        std::shuffle(randomizedQuestions.begin(), randomizedQuestions.end(), random);
        return randomizedQuestions;
    }
};

#endif