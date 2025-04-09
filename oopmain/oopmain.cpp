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
    SpaceObject* earthProxy = new SpaceObjectProxy("Земля", SpaceObjectType::Planet, 6378);
    SpaceObject* marsProxy = new SpaceObjectProxy("Марс", SpaceObjectType::Planet, 3389);
    SpaceObject* moonProxy = new SpaceObjectProxy("Луна", "Земля", SpaceObjectType::Satelite);

    std::vector<SpaceObject*> objects = {sunProxy , earthProxy, marsProxy, moonProxy};
    LinearExcursion* tour = new LinearExcursion(objects);

    User* user1 = new User("alekshiga", tour);

    // теперь пользователь сам управляет экскурсией через свою сцену и может завершить её раньше или позже остальных
    while (!user1->getScene()->getCurrentExcursion()->isFinished() == true) {

        Scene* currentScene = user1->getScene();

        if (currentScene->getCurrentExcursion()->getCurrentObject() != nullptr) {

            SpaceObject* currentObject = currentScene->getCurrentExcursion()->getCurrentObject();

            std::cout << "Сейчас отображается: " << currentObject->getName() << "\n";
            currentObject->display();
            currentScene->requestMoreInfo(); // запрос дополнительной информации об объекте на сцене
            currentObject->playAudio();

            std::cout << "Нажмите Enter для перехода к следующему объекту...";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ожидаем нажатия Enter

        }
        else {
            std::cout << "Экскурсия завершена (нет больше объектов)." << std::endl;
            break; // выходим из цикла, если нет объектов
        }

        currentScene->getCurrentExcursion()->goToNextObject();
    }

    // удаляем прокси, а они сами удаляют реальный объект
    delete tour;
    delete sunProxy;
    delete earthProxy;
    delete marsProxy;
    delete moonProxy;
    delete user1;
    
    return 0;
}

