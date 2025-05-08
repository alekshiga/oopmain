#include "SpaceObject.h"
#include <vector>
#include <iostream>

class Galaxy : public SpaceObject {
private:
    std::string name;
    std::vector<SpaceObject*> children;
    AudioFile* audioFile;
public:
    Galaxy(std::string name) : name(name), SpaceObject(nullptr) {}
    ~Galaxy() {
        for (auto& child : children) {
            delete child;
        }
    }

    void add(SpaceObject* child) override {
        children.push_back(child);
    }

    void remove(SpaceObject* child) override {
        for (size_t i = 0; i < children.size(); ++i) {
            if (children[i] == child) {
                children.erase(children.begin() + i);
                return;
            }
        }
    }

    std::vector<SpaceObject*> getChildren() override {
        return children;
    }

    void display() override {
        std::cout << "Галактика: " << name << std::endl;
        for (auto& child : children) {
            child->display();
        }
    }

    void getAdditionalInfo() override {
        std::cout << "Информация: " << name << std::endl;
        for (auto& child : children) {
            child->getAdditionalInfo();
        }
    }

    std::string getDescription() override {
        std::string desc = "Название галактики: " + name + ". Состоит из: ";
        for (auto& child : children) {
            desc += child->getName() + ", ";
        }
        return desc;
    }

    std::string getName() override {
        return name;
    }
    void playAudio() override {
        this->audioFile->play();
    }
};

class StarSystem : public SpaceObject {
private:
    std::string name;
    std::vector<SpaceObject*> children;
    AudioFile* audioFile;
public:
    StarSystem(std::string name) : name(name), SpaceObject(nullptr) {}
    ~StarSystem() {
        for (auto& child : children) {
            delete child;
        }
    }

    void add(SpaceObject* child) override {
        children.push_back(child);
    }

    void remove(SpaceObject* child) override {
        for (size_t i = 0; i < children.size(); ++i) {
            if (children[i] == child) {
                children.erase(children.begin() + i);
                return;
            }
        }
    }

    std::vector<SpaceObject*> getChildren() override {
        return children;
    }

    void display() override {
        std::cout << "Система: " << name << std::endl;
        for (auto& child : children) {
            child->display();
        }
    }

    void getAdditionalInfo() override {
        std::cout << "Подробная информация: " << std::endl;
        for (auto& child : children) {
            child->getAdditionalInfo();
        }
    }

    std::string getDescription() override {
        std::string desc = "Имя системы: " + name + ". Состоит из: ";
        for (auto& child : children) {
            desc += child->getName() + ", ";
        }
        return desc;
    }

    std::string getName() override {
        return name;
    }

    void playAudio() override {
        this->audioFile->play();
    }
};