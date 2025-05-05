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
        std::cout << "Для данного объекта вопросов нет" << std::endl;
        return {}; // Возвращаем пустой вектор, если нет вопросов
    }
}

void QuizExcursion::setQuestions(const std::map<SpaceObject*, std::vector<std::pair<std::string, std::string>>>& newQuestions) {
    questions = newQuestions;
}

bool QuizExcursion::checkAnswer(SpaceObject* object, const std::string& userAnswer) {
    if (questions.count(object)) {
        for (const auto& questionAnswerPair : questions[object]) {
            if (questionAnswerPair.second == userAnswer) { // Сравниваем с правильным ответом
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
            std::cout << "Объект: " << currentObject->getName() << std::endl;
            auto questionAnswerPairs = getQuestionsForCurrentObject();

            if (!questionAnswerPairs.empty()) {
                std::string question = questionAnswerPairs[0].first; // Берем первый вопрос
                std::string correctAnswer = questionAnswerPairs[0].second; // Берем первый ответ

                std::cout << "Вопрос: " << question << std::endl;
                std::string userAnswer;
                std::cout << "Ваш ответ: ";
                std::getline(std::cin, userAnswer);

                // Проверяем ответ и увеличиваем рейтинг, если правильно
                if (checkAnswer(currentObject, userAnswer)) {
                    std::cout << "Правильно!" << std::endl;
                    // user->increaseRating();  // Увеличиваем рейтинг пользователя.  Где взять user?
                    // ВАЖНО: Нужен указатель на User, чтобы увеличить рейтинг!
                }
                else {
                    std::cout << "Неправильно. Правильный ответ: " << correctAnswer << std::endl;
                }
            }

            goToNextObject();
        }
        else {
            std::cout << "Экскурсия окончена." << std::endl;
            break;
        }
    }
}
