#define NOMINMAX

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
#include "XMLToJSONAdapter.cpp"
#include "SpaceObjectDecorator.cpp"
#include "Composite.cpp"
#include "Iterator.h"

#include <iostream>
#include <windows.h>
#include <vector>
#include <locale>
#include <limits>

int main() {

    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    // пример использования Adapter
    XMLToJSONAdapter adapter;
    std::string jsonData = adapter.getSpaceObjectJSON("Солнце");
    std::cout << "JSON Data: " << jsonData << std::endl;

    // создаём космические объекты
    SpaceObject* sunProxy = new SpaceObjectProxy("Солнце", 6000, SpaceObjectType::Star);
    SpaceObject* earthProxy = new SpaceObjectProxy("Земля", SpaceObjectType::Planet, true, 6378);
    SpaceObject* marsProxy = new SpaceObjectProxy("Марс", SpaceObjectType::Planet, false, 3389);
    SpaceObject* moonProxy = new SpaceObjectProxy("Луна", "Земля", SpaceObjectType::Satelite);

    // пример использования Decorator
    // оборачиваем объект
    SpaceObject* highlightedSun = new HighlightDecorator(sunProxy);
    SpaceObject* highlightedRotatingSun = new RotationDecorator(highlightedSun);
    highlightedRotatingSun->display();

    std::vector<SpaceObject*> objects = { sunProxy , earthProxy, marsProxy, moonProxy };
    ExcursionRoute* route = new ExcursionRoute(objects);

    // составной объект Млечный путь
    SpaceObject* milkyWay = new Galaxy("Млечный путь");
    milkyWay->add(sunProxy);
    milkyWay->add(earthProxy);
    milkyWay->add(marsProxy);
    milkyWay->display();

    // Теперь создание вопросов происходит в конструкторе QuizExcursion
    Excursion* quizExcursion = new QuizExcursion(route, 1); // Больше не требует questions
    std::map<SpaceObject*, std::vector<std::pair<std::string, std::string>>> questions;

    questions[sunProxy] = { {"Какая температура поверхности солнца?", "6000"} };
    questions[earthProxy] = { {"Есть ли жизнь на земле?", "да"} };
    questions[marsProxy] = { {"Есть ли жизнь на Марсе?", "нет"} };

    std::cout << "Начнём квиз-экскурсию!" << std::endl;
    User* user1 = new User("alekshiga", quizExcursion);
    user1->getScene()->startExcursion();

    std::cout << "Начнём следующую случайную экскурсию!" << std::endl;
    Excursion* randomExcursion = new RandomExcursion(route);
    user1->getScene()->setCurrentExcursion(randomExcursion);
    user1->getScene()->startExcursion();

    // удаляем прокси, а они сами удаляют реальный объект если он был создан
    delete moonProxy;
    delete highlightedRotatingSun;
    delete highlightedSun;
    delete user1;
    delete quizExcursion;
    // когда вручную я удалял milkyWay, то он пытался удалить свои компоненты, которые уже были
    // удалены парой строчек выше. Поэтому там я удалю только moonProxy
    delete milkyWay;
    delete route;
    delete randomExcursion;

    return 0;
}