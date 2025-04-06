#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include <string>
#include "Excursion.h"

class Scene {
private:
    static Scene* instance;
    Excursion* currentExcursion;
    Scene(Excursion* excursion); // ��������� ����������� 

public:
    ~Scene();  // ����������

    static Scene* getInstance(Excursion* excursion);

    void displayScene();

    std::string getDescription() const;

    Excursion* getCurrentExcursion() const;

    void setCurrentExcursion(Excursion* excursion);
};

#endif