#ifndef DATABASE_H

# include <iostream>
#include "../model/database.h"
# include <fstream>
#include <string>
#include <vector>


#define DATABASE_H

class OptionObject {

    private:
        std::string object;

    protected:
        std::string object_choices[4] = {
        "Emagrecer",
        "Definir Musculo", 
        "Ganhar Massa Muscular", 
        "Manter a Saúde"};

    public:
        OptionObject() {
            this->object = "";
        }

        void print_object() {
            for (int x = 0; x < 4; ++x) {
                std::cout << x + 1 << ": " << object_choices[x] << " \n";
            }
        }

        std::string select_option(int& option) {
            std::string aux;
            switch (option)
            {
            case 1:
                aux = object_choices[0];
                break;
            case 2:
                aux = object_choices[1];
                break;
            case 3:
                aux = object_choices[2];
                break;
            case 4:
                aux = object_choices[3];
                break;
            default:
                std::cout << "Opção Invalido!\n";
                return "";
            }
            object = aux;
            std::cout << "Opção Escolhida: " << object << '\n';
            return object;
        }
};

class CreateUser {

    private:
        std::string name;
        std::string date;
        char sex;
        std::string object;

    public: 

        CreateUser(std::string name, std::string date, char sex, std::string object) {
            this->name = name;
            this->date = date;
            this->sex = sex;
            this->object = object;
        }

        void setname(std::string name) {
            this->name = name;
        }

        std::string getname() {
            return name;
        }

        void setdate(std::string date) {
            this->date = date;
        }

        std::string getdate() {
            return  date;
        }

        void setsex(char sex) {
            this->sex = sex;
        }

        char getsex() {
            return  sex;
        }

        void setobject(std::string object) {
            this->object = object;
        }

        std::string getobject() {
            return  object;
        }    
        
};

class ReadUser {

    private:
        std::ifstream file;

    public:
    ReadUser(const std::string& path) {
        file.open(path);
        if (!file.is_open()) {
            throw std::runtime_error("Erro ao abrir o arquivo");
        }
    }

    void read_users() {
        std::string line;
        while (std::getline(file, line)) {
            std::cout << line << '\n';
        }
        file.close();
    }
};

class UpdateUser {

    private:
        std::string databasePath;

    public:
        UpdateUser(const std::string& DatabasePath):
            databasePath(DatabasePath) {}
            
    void update_user(const std::string& id, const std::string& name = "", const std::string& dob = "", const std::string& sex = "", const std::string& object = "") {
        std::vector<std::string> lines;
        std::ifstream file(databasePath);
        std::string line;
        while (std::getline(file, line)) {
            if (line.find("ID: " + id + ",") != std::string::npos) {
                std::stringstream ss(line);
                std::string field;
                std::getline(ss, field, ':'); 
                std::getline(ss, field, ',');  
                std::string newLine = "ID: " + field + ",";
                std::getline(ss, field, ':'); 
                std::getline(ss, field, ','); 
                newLine += " Name: " + (name.empty() ? field : name) + ",";
                std::getline(ss, field, ':');
                std::getline(ss, field, ',');  
                newLine += " Date of Birth : " + (dob.empty() ? field : dob) + ",";
                std::getline(ss, field, ':');  
                std::getline(ss, field, ',');
                newLine += " Sex: " + (sex.empty() ? field : sex) + ",";
                std::getline(ss, field, ':');  
                std::getline(ss, field, ',');
                newLine += " Object: " + (object.empty() ? field : object);
                line = newLine;
            }
            lines.push_back(line);
        }
        file.close();
        std::ofstream fileOut(databasePath);
        for (const auto& line : lines) {
            fileOut << line << '\n';
        }
    }
            
};

class DeleteUser {

    private:
        std::string databasePath;

    public:
        DeleteUser(const std::string& DatabasePath):
            databasePath(DatabasePath) {}
            
    void delete_user(const std::string& id) {
        std::vector<std::string> lines;
        std::ifstream file(databasePath);
        std::string line;
        while (std::getline(file, line)) {
            if (line.find("ID: " + id + ",") != std::string::npos) {
                continue;
            }
            lines.push_back(line);
        }
        file.close();
        std::ofstream fileOut(databasePath);
        for (const auto& line : lines) {
            fileOut << line << '\n';
        }
    }
       
};

#endif