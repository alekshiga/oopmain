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

    SpaceObject* sunProxy = new SpaceObjectProxy("Солнце", 6000, SpaceObjectType::Star);
    SpaceObject* earthProxy = new SpaceObjectProxy("Земля", SpaceObjectType::Planet, true, 6378);
    SpaceObject* marsProxy = new SpaceObjectProxy("Марс", SpaceObjectType::Planet, false, 3389);
    SpaceObject* moonProxy = new SpaceObjectProxy("Луна", "Земля", SpaceObjectType::Satelite);

    std::vector<SpaceObject*> objects = {sunProxy , earthProxy, marsProxy, moonProxy};

    //LinearExcursion* tour = new LinearExcursion(objects);
    QuizExcursion* quizExcursion = new QuizExcursion(objects, 1);

    //создаём список вопросов
    std::map<SpaceObject*, std::vector<std::pair<std::string, std::string>>> questions;

    questions[sunProxy] = { {"Какая температура поверхности солнца?", "6000"} };
    questions[earthProxy] = { {"Есть ли жизнь на земле?", "да"} };
    questions[marsProxy] = { {"Есть ли жизнь на Марсе?", "нет"} };

    quizExcursion->setQuestions(questions);

    std::cout << "Начнём квиз-экскурсию!" << std::endl;
    User* user1 = new User("alekshiga", quizExcursion);

    while (!quizExcursion->isFinished()) {
        SpaceObject* currentObject = quizExcursion->getCurrentObject();
        if (currentObject) {
            std::cout << "Объект: " << currentObject->getName() << std::endl;
            auto questionAnswerPairs = quizExcursion->getQuestionsForCurrentObject();

            if (!questionAnswerPairs.empty()) {
                std::string question = questionAnswerPairs[0].first; // Берем первый вопрос
                std::string correctAnswer = questionAnswerPairs[0].second; // Берем первый ответ

                std::cout << "Вопрос: " << question << std::endl;
                std::string userAnswer;
                std::cout << "Ваш ответ: ";
                std::getline(std::cin, userAnswer);

                // Проверяем ответ и увеличиваем рейтинг, если правильно
                if (quizExcursion->checkAnswer(currentObject, userAnswer)) {
                    std::cout << "Правильно!" << std::endl;
                    user1->increaseRating();  // Увеличиваем рейтинг пользователя
                }
                else {
                    std::cout << "Неправильно. Правильный ответ: " << correctAnswer << std::endl;
                }
            }

            quizExcursion->goToNextObject();
        }
        else {
            std::cout << "Экскурсия окончена." << std::endl;
            break;
        }
    }
    std::cout << "Итоговый рейтинг: " << user1->getRating() << std::endl; // Выводим итоговый рейтинг

    std::cout << "Начнём следующую случайную экскурсию!" << std::endl;

    RandomExcursion* randomExcursion = new RandomExcursion(objects);
    user1->setExcursion(randomExcursion);
    char choice;
    while (!randomExcursion->isFinished()) {
        SpaceObject* currentObject = randomExcursion->getCurrentObject();
        if (currentObject) {
            std::cout << user1->getUsername() << " осматривает: " << currentObject->getName() << std::endl;
        }
        else {
            std::cout << "Экскурсия закончена." << std::endl;
            break;
        }

        std::cout << "Посетить другой объект? (y/n): ";
        std::cin >> choice;

        if (choice == 'n') {
            randomExcursion->finishExcursion();
        }
        else if (choice == 'y') {
            continue;
        }
        else {
            std::cout << "Некорректный ввод." << std::endl;
            randomExcursion->finishExcursion();
        }
    }

    //// теперь пользователь сам управляет экскурсией через свою сцену и может завершить её раньше или позже остальных
    //while (!user1->getScene()->getCurrentExcursion()->isFinished() == true) {

    //    Scene* currentScene = user1->getScene();

    //    if (currentScene->getCurrentExcursion()->getCurrentObject() != nullptr) {

    //        SpaceObject* currentObject = currentScene->getCurrentExcursion()->getCurrentObject();

    //        std::cout << "Сейчас отображается: " << currentObject->getName() << "\n";
    //        currentObject->display();
    //        currentScene->requestMoreInfo(); // запрос дополнительной информации об объекте на сцене
    //        currentObject->playAudio();

    //        std::cout << "Нажмите Enter для перехода к следующему объекту...";
    //        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ожидаем нажатия Enter

    //    }
    //    else {
    //        std::cout << "Экскурсия завершена (нет больше объектов)." << std::endl;
    //        break; // выходим из цикла, если нет объектов
    //    }

    //    currentScene->getCurrentExcursion()->goToNextObject();
    //}

    // удаляем прокси, а они сами удаляют реальный объект
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

