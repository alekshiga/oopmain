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

    // ������ ������������� Adapter
    XMLToJSONAdapter adapter;
    std::string jsonData = adapter.getSpaceObjectJSON("������");
    std::cout << "JSON Data: " << jsonData << std::endl;

    // ������ ����������� �������
    SpaceObject* sunProxy = new SpaceObjectProxy("������", 6000, SpaceObjectType::Star);
    SpaceObject* earthProxy = new SpaceObjectProxy("�����", SpaceObjectType::Planet, true, 6378);
    SpaceObject* marsProxy = new SpaceObjectProxy("����", SpaceObjectType::Planet, false, 3389);
    SpaceObject* moonProxy = new SpaceObjectProxy("����", "�����", SpaceObjectType::Satelite);

    // ������ ������������� Decorator
    // ����������� ������
    SpaceObject* highlightedSun = new HighlightDecorator(sunProxy);
    SpaceObject* highlightedRotatingSun = new RotationDecorator(highlightedSun);
    highlightedRotatingSun->display();

    std::vector<SpaceObject*> objects = { sunProxy , earthProxy, marsProxy, moonProxy };
    ExcursionRoute* route = new ExcursionRoute(objects);

    // ��������� ������ ������� ����
    SpaceObject* milkyWay = new Galaxy("������� ����");
    milkyWay->add(sunProxy);
    milkyWay->add(earthProxy);
    milkyWay->add(marsProxy);
    milkyWay->display();

    QuizExcursion* quizExcursion = new QuizExcursion(route, 1);

    //������ ������ ��������
    std::map<SpaceObject*, std::vector<std::pair<std::string, std::string>>> questions;

    questions[sunProxy] = { {"����� ����������� ����������� ������?", "6000"} };
    questions[earthProxy] = { {"���� �� ����� �� �����?", "��"} };
    questions[marsProxy] = { {"���� �� ����� �� �����?", "���"} };

    quizExcursion->setQuestions(questions);

    std::cout << "����� ����-���������!" << std::endl;
    User* user1 = new User("alekshiga", quizExcursion);
    user1->getScene()->startExcursion();

    std::cout << "����� ��������� ��������� ���������!" << std::endl;
    RandomExcursion* randomExcursion = new RandomExcursion(route);
    user1->getScene()->setCurrentExcursion(randomExcursion);
    user1->getScene()->startExcursion();

    // ������� ������, � ��� ���� ������� �������� ������ ���� �� ��� ������
    delete moonProxy;
    delete highlightedRotatingSun;
    delete highlightedSun;
    delete user1;
    delete quizExcursion;
    // ����� ������� � ������ milkyWay, �� �� ������� ������� ���� ����������, ������� ��� ����
    // ������� ����� ������� ����. ������� ��� � ����� ������ moonProxy
    delete milkyWay;
    delete route;
    delete randomExcursion;

    return 0;
}
