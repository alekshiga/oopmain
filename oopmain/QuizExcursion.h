#ifndef QUIZEXCRUSION_H
#define QUIZEXCRUSION_H

#include "SpaceObject.h"
#include "Excursion.h"
#include <string>
#include <vector>
#include <random>
#include <map>

class SpaceObject;

class QuizExcursion : public Excursion {
private:
    std::vector<SpaceObject*> route;
    int currentObjectIndex;
    int questionsPerObject;
    std::map<SpaceObject*, std::vector<std::pair<std::string, std::string>>> questions;
    std::mt19937 random;

    std::vector<std::string> getRandomizedQuestions(const std::vector<std::string>& questions);
    bool checkAnswer(SpaceObject* object, const std::string& userAnswer);

public:
    QuizExcursion(const std::vector<SpaceObject*>& objects, int questionsPerObject);
    ~QuizExcursion();
    SpaceObject* getCurrentObject();
    void goToNextObject();
    bool isFinished();
    std::vector<std::pair<std::string, std::string>> getQuestionsForCurrentObject();
    void setQuestions(const std::map<SpaceObject*, std::vector<std::pair<std::string, std::string>>>& newQuestions);
    void startExcursion();
};

#endif
