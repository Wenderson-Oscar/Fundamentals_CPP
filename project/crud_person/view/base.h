#ifndef DATABASE_H

#include <iostream>
#include "../controller/logic.h"

#define DATABASE_H

class InterfaceRegister {
    public:
        void register_user() {
            ControllerDatabase file("./database.txt");
            std::string name, date;
            char sex;
            std::cout << "Digite o nome: ";
            std::cin >> name;
            std::cout << "Digite a data de nascimento: ";
            std::cin >> date;
            std::cout << "Digite o sexo: ";
            std::cin >> sex;
            OptionObject select_object;
            int option;
            std::cout << "Escolha uma das Opções\n";
            select_object.print_object();
            std::cin >> option;
            std::string result = select_object.select_option(option);
            CreateUser user(name, date, sex, result);
            std::cout << "Cadastro Realizado com Sucesso!\n";
            DataBaseFile db(file.getDatabasePath());
            db.create_user(user.getname(), user.getdate(), user.getsex(), user.getobject());
        }
};

class InterfaceUpdate {
    public:
        void update() {
            ControllerDatabase file("./database.txt");
            std::cout << "Atualizar Pessoa\n";
            std::cout << "Caso não deseje atualizar um campo, apenas deixe em branco\n";
            std::string name1, date1, id1;
            char sex1;
            std::string sex1_str(1, sex1);
            std::cout << "Digite o ID do usuário que deseja Atualizar: ";
            std::cin >> id1;
            std::cout << "Digite o nome: ";
            std::cin >> name1;
            std::cout << "Digite a data de nascimento: ";
            std::cin >> date1;
            std::cout << "Digite o sexo: ";
            std::cin >> sex1;
            OptionObject select_object1;
            int option1;
            std::cout << "Escolha uma das Opções\n";
            select_object1.print_object();
            std::cin >> option1;
            std::string result1 = select_object1.select_option(option1);
            UpdateUser update_user(file.getDatabasePath());
            update_user.update_user(id1, name1, date1, sex1_str, result1);
        }
        
};

class InterfaceDelete {
    public:
        void delete_user() {
            ControllerDatabase file("./database.txt");
            std::cout << "Deletar Pessoa\n";
            ReadUser user_r(file.getDatabasePath());
            user_r.read_users();
            DeleteUser id_user(file.getDatabasePath());
            int option;
            std::cout << "Digite o ID do usuário que deseja Deletar: ";
            std::cin >> option;
            id_user.delete_user(std::to_string(option));
            std::cout << "Usuário Deletado com Sucesso!\n";
        }
};

class InterfaceList {
    public:
        void list_user() {
            ControllerDatabase file("./database.txt");
            std::cout << "Listar Pessoas\n";
            ReadUser user_r2(file.getDatabasePath());
            user_r2.read_users();
        }
};

#endif
