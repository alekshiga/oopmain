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
    std::vector<std::pair<SpaceObject*, std::vector<std::string>>> questions; // один или несколько вопрсоов для каждого объекта
    std::mt19937 random; // генератор случайных чисел

public:
    QuizExcursion(const std::vector<SpaceObject*>& objects, int questionsPerObject)
        : route(objects), currentObjectIndex(0), questionsPerObject(questionsPerObject), random(std::random_device{}()) {
        // questions заполняется позже с помощью setQuestions
        // или через загрузку из файла
        std::cout << "Создана QuizExcursion с " << questionsPerObject << " вопросами на объект" << std::endl;
    }

    ~QuizExcursion() {} // деструктор

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

    // Метод для получения вопросов для текущего объекта
    std::vector<std::string> getQuestionsForCurrentObject() {
        SpaceObject* currentObject = getCurrentObject();
        if (currentObject) {
            // Находим вопросы для текущего объекта
            for (const auto& pair : questions) {
                if (pair.first == currentObject) {
                    // возвращаем перемешанный список вопросов
                    return getRandomizedQuestions(pair.second);
                }
            }
            std::cout << "Нет вопросов для объекта " << currentObject->getName() << std::endl;
        }
        return {}; // пустой вектор если вопросов нет
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