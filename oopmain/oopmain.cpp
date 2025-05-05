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

    // создаём космические объекты
    SpaceObject* sunProxy = new SpaceObjectProxy("Солнце", 6000, SpaceObjectType::Star);
    SpaceObject* earthProxy = new SpaceObjectProxy("Земля", SpaceObjectType::Planet, true, 6378);
    SpaceObject* marsProxy = new SpaceObjectProxy("Марс", SpaceObjectType::Planet, false, 3389);
    SpaceObject* moonProxy = new SpaceObjectProxy("Луна", "Земля", SpaceObjectType::Satelite);

    std::vector<SpaceObject*> objects = { sunProxy , earthProxy, marsProxy, moonProxy };

    QuizExcursion* quizExcursion = new QuizExcursion(objects, 1);
    RandomExcursion* randomExcursion = new RandomExcursion(objects);

    //создаём список вопросов
    std::map<SpaceObject*, std::vector<std::pair<std::string, std::string>>> questions;

    questions[sunProxy] = { {"Какая температура поверхности солнца?", "6000"} };
    questions[earthProxy] = { {"Есть ли жизнь на земле?", "да"} };
    questions[marsProxy] = { {"Есть ли жизнь на Марсе?", "нет"} };

    quizExcursion->setQuestions(questions);

    std::cout << "Начнём квиз-экскурсию!" << std::endl;
    User* user1 = new User("alekshiga", quizExcursion);
    user1->getScene()->startExcursion();

    std::cout << "Начнём следующую случайную экскурсию!" << std::endl;

    user1->setExcursion(randomExcursion);
    user1->getScene()->startExcursion();

    // удаляем прокси, а они сами удаляют реальный объект если он был создан
    delete sunProxy;
    delete earthProxy;
    delete marsProxy;
    delete moonProxy;
    delete user1;
    delete randomExcursion;
    delete quizExcursion;

    return 0;
}
