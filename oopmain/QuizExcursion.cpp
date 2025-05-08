#include "QuizExcursion.h"
#include "SpaceObject.h"
#include "ExcursionRoute.h"
#include "Iterator.h"
#include <iostream>
#include <random>
#include <algorithm>
#include <limits>

QuizExcursion::QuizExcursion(ExcursionRoute* route, int questionsPerObject)
    : Excursion(route),
    questionsPerObject(questionsPerObject),
    random(std::random_device{}()),
    iterator(route->createIterator()) {
    createQuestions();
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

void QuizExcursion::createQuestions() {
    questions.clear();

    // Находим нужные объекты на маршруте
    SpaceObject* sun = nullptr;
    SpaceObject* earth = nullptr;
    SpaceObject* mars = nullptr;

    Iterator* tempIterator = route->createIterator(); // Используем route, который является членом Excursion
    while (!tempIterator->isDone()) {
        SpaceObject* obj = tempIterator->current();
        if (obj->getName() == "Солнце") {
            sun = obj;
        }
        else if (obj->getName() == "Земля") {
            earth = obj;
        }
        else if (obj->getName() == "Марс") {
            mars = obj;
        }
        tempIterator->next();
    }
    delete tempIterator;

    // Создаем вопросы для найденных объектов
    if (sun) {
        questions[sun] = { {"Какая температура поверхности солнца?", "6000"} };
    }
    if (earth) {
        questions[earth] = { {"Есть ли жизнь на земле?", "да"} };
    }
    if (mars) {
        questions[mars] = { {"Есть ли жизнь на Марсе?", "нет"} };
    }
}
