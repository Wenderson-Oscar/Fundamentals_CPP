#ifndef DATABASE_H
#define DATABASE_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

class DataBaseFile {

    private:
        std::ofstream file;
        int auto_id;

        int findLastId() {
            std::ifstream infile("database.txt");
            std::string line;
            int maxid = 0;

            while (std::getline(infile, line)) {
                std::stringstream iss(line);
                std::string token;
                int id;
                if (iss >> token >> id) {
                    if (token == "ID:") {
                        if (id > maxid) {
                            maxid = id;
                        }
                    }
                }
            }
            return maxid;
        }

    public:
        DataBaseFile(const std::string& filename) : auto_id(1) {
            file.open(filename, std::ios::out | std::ios::app);
            if (!file.is_open()) {
                throw std::runtime_error("Erro ao abrir o arquivo");
            }
            auto_id = findLastId();
        }

        ~DataBaseFile() {
            if (file.is_open()) {
                file.close();
            }
        }

        void create_user(const std::string& name, const std::string& date, char sex, const std::string& object) {
            auto_id ++;
            file << "ID: " << auto_id << ", Name: " << name << ", Date of Birth : " << date << ", Sex: " << sex << ", Object: " << object << '\n';
        }

};

#endif