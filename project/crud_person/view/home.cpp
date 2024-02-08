# include <iostream>
# include "./base.h"

class Interface {
public:
    void print_menu() {
        while (true) {
            std::cout << "1: Cadastrar\n";
            std::cout << "2: Atualizar\n";   
            std::cout << "3: Deletar\n";
            std::cout << "4: Listar\n";
            std::cout << "5: Sair\n";
            std::cout << "Escolha uma das Opções\n";
            int option;
            std::cin >> option;
            switch (option)
            {
            case 1:
                InterfaceRegister interface1;
                interface1.register_user();
                break;
            case 2:
                InterfaceUpdate interface2;
                interface2.update();
                break;
            case 3:
                InterfaceDelete interface3;
                interface3.delete_user();
                break;
            case 4:
                InterfaceList interface4;
                interface4.list_user();
                break;
            case 5:
                std::cout << "Saindo...\n";
                return;
            default:
                break;
            }
        }
    }
};
int main() {
    Interface interface;
    interface.print_menu();
    return 0;
}
