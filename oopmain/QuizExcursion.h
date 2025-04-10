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
    std::map<SpaceObject*, std::vector<std::pair<std::string, std::string>>> questions; //  Вопрос и ответ
    std::mt19937 random;

public:
    QuizExcursion(const std::vector<SpaceObject*>& objects, int questionsPerObject)
        : route(objects), currentObjectIndex(0), questionsPerObject(questionsPerObject), random(std::random_device{}()) {
        // пишем вопросы вручную или загружаем через файл
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
    std::vector<std::pair<std::string, std::string>> getQuestionsForCurrentObject() {
        SpaceObject* currentObject = getCurrentObject();
        if (currentObject && questions.count(currentObject)) {
            return questions[currentObject];
        }
        else {
            std::cout << "Для данного объекта вопросов нет" << std::endl;
            return {}; // Возвращаем пустой вектор, если нет вопросов
        }
        
    }

    void setQuestions(const std::map<SpaceObject*, std::vector<std::pair<std::string, std::string>>>& newQuestions) {
        questions = newQuestions;
    }

    // Метод для проверки ответа
    bool checkAnswer(SpaceObject* object, const std::string& userAnswer) {
        if (questions.count(object)) {
            for (const auto& questionAnswerPair : questions[object]) {
                if (questionAnswerPair.second == userAnswer) { // Сравниваем с правильным ответом
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
};

#endif