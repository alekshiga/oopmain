#include <iostream>
#include <string>

// Старый класс (Old System)
class XMLSpaceObjectSource {
public:
    std::string getSpaceObjectXML(std::string objectName) {
        if (objectName == "Солнце") {
            return "<spaceObject><name>Солнце</name><temperature>6000</temperature></spaceObject>";
        }
        if (objectName == "Земля") {
            return "<spaceObject><name>Земля</name><radius>6378</radius></spaceObject>";
        }
        if (objectName == "Марс") {
            return "<spaceObject><name>Марс</name><radius>3389</radius></spaceObject>";
        }
        return "<spaceObject><name>Неизвестный Объект</name></spaceObject>";
    }
};

// Нужный интерфейс
class SpaceObjectDataSource {
public:
    virtual std::string getSpaceObjectJSON(std::string objectName) = 0;
};

// Адаптер
class XMLToJSONAdapter : public SpaceObjectDataSource {
private:
    XMLSpaceObjectSource xmlSource;

    std::string convertXMLToJSON(const std::string& xmlData) {
        //  существует реальная логика преобразования, но для наглядности приведу упрощённый пример
        if (xmlData.find("<name>Солнце</name>") != std::string::npos) {
            return "{ \"name\": \"Солнце\", \"temperature\": 6000 }";
        }
        if (xmlData.find("<name>Земля</name>") != std::string::npos) {
            return "{ \"name\": \"Солнце\", \"radius\": 6378 }";
        }
        if (xmlData.find("<name>Марс</name>") != std::string::npos) {
            return "{ \"name\": \"Солнце\", \"radius\": 3389 }";
        }
        return "{ \"name\": \"Неизвестный Объект\" }";
    }

public:
    std::string getSpaceObjectJSON(std::string objectName) override {
        std::string xmlData = xmlSource.getSpaceObjectXML(objectName);
        return convertXMLToJSON(xmlData);
    }
};