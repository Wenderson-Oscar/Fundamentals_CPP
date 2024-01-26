# include <iostream>
#include "../model/database.h"
# include <fstream>
#include <string>

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
        std::string path_file;
        std::ifstream database_file;

    ReadUser(const std::string& path) : path_file(path), database_file(path_file) {
        if (!database_file.is_open()) {
            throw std::runtime_error("Erro ao abrir o arquivo: " + path_file);
        }
    }

    void read_user_full() {
        std::string db;
        while (std::getline(database_file, db)) {
            std::cout << db << std::endl;
        }
        database_file.close();
    }
};

class Controler {

};


int main() {
    /* OptionObject select_object;
    int option;
    std::cout << "Escolha uma das Opções\n";
    select_object.print_object();
    std::cin >> option;
    std::string result = select_object.select_option(option);
    CreateUser user("Oscar", "01/01/2000", 'M', result);
    std::cout << "Cadastro Realizado com Sucesso!\n";
    DataBaseFile db("database.txt");
    db.create_user(user.getname(), user.getdate(), user.getsex(), user.getobject());
    std::cout << "Dados: " << user.getname() << " " << user.getdate() << " " << user.getsex() << " " << user.getobject() << '\n';
    std::cout << "Usuário Inserido no Banco de dados com sucesso!\n"; */
    return 0;
}
