#include "QuizExcursion.h"
#include "SpaceObject.h"
#include "ExcursionRoute.h"
#include "Iterator.h"
#include <iostream>
#include <random>
#include <algorithm>
#include <limits>

QuizExcursion::QuizExcursion(ExcursionRoute* route, int questionsPerObject)
    : route(route), questionsPerObject(questionsPerObject), random(std::random_device{}()), iterator(route->createIterator()) {
}

QuizExcursion::~QuizExcursion() {
    delete iterator;
}

SpaceObject* QuizExcursion::getCurrentObject() {
    if (!iterator->isDone()) {
        return iterator->current();
    }
    return nullptr;
}

void QuizExcursion::goToNextObject() {
    iterator->next();
}

bool QuizExcursion::isFinished() {
    return iterator->isDone();
}

std::vector<std::pair<std::string, std::string>> QuizExcursion::getQuestionsForCurrentObject() {
    SpaceObject* currentObject = getCurrentObject();
    if (currentObject && questions.count(currentObject)) {
        return questions[currentObject];
    }
    else {
        std::cout << "Для данного объекта вопросов нет" << std::endl;
        return {};
    }
}

void QuizExcursion::setQuestions(const std::map<SpaceObject*, std::vector<std::pair<std::string, std::string>>>& newQuestions) {
    questions = newQuestions;
}

bool QuizExcursion::checkAnswer(SpaceObject* object, const std::string& userAnswer) {
    if (questions.count(object)) {
        for (const auto& questionAnswerPair : questions[object]) {
            if (questionAnswerPair.second == userAnswer) {
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
                std::string question = questionAnswerPairs[0].first;
                std::string correctAnswer = questionAnswerPairs[0].second;

                std::cout << "Вопрос: " << question << std::endl;
                std::string userAnswer;
                std::cout << "Ваш ответ: ";
                std::getline(std::cin, userAnswer);

                if (checkAnswer(currentObject, userAnswer)) {
                    std::cout << "Правильно!" << std::endl;
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
