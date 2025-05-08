#include <iostream>
#include <string>

// ������ ����� (Old System)
class XMLSpaceObjectSource {
public:
    std::string getSpaceObjectXML(std::string objectName) {
        if (objectName == "������") {
            return "<spaceObject><name>������</name><temperature>6000</temperature></spaceObject>";
        }
        if (objectName == "�����") {
            return "<spaceObject><name>�����</name><radius>6378</radius></spaceObject>";
        }
        if (objectName == "����") {
            return "<spaceObject><name>����</name><radius>3389</radius></spaceObject>";
        }
        return "<spaceObject><name>����������� ������</name></spaceObject>";
    }
};

// ������ ���������
class SpaceObjectDataSource {
public:
    virtual std::string getSpaceObjectJSON(std::string objectName) = 0;
};

// �������
class XMLToJSONAdapter : public SpaceObjectDataSource {
private:
    XMLSpaceObjectSource xmlSource;

    std::string convertXMLToJSON(const std::string& xmlData) {
        //  ���������� �������� ������ ��������������, �� ��� ����������� ������� ���������� ������
        if (xmlData.find("<name>������</name>") != std::string::npos) {
            return "{ \"name\": \"������\", \"temperature\": 6000 }";
        }
        if (xmlData.find("<name>�����</name>") != std::string::npos) {
            return "{ \"name\": \"������\", \"radius\": 6378 }";
        }
        if (xmlData.find("<name>����</name>") != std::string::npos) {
            return "{ \"name\": \"������\", \"radius\": 3389 }";
        }
        return "{ \"name\": \"����������� ������\" }";
    }

public:
    std::string getSpaceObjectJSON(std::string objectName) override {
        std::string xmlData = xmlSource.getSpaceObjectXML(objectName);
        return convertXMLToJSON(xmlData);
    }
};