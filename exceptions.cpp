# include <iostream>

int main() {
    try
    {
        int age = 16;
        if (age >= 18) {
            std::cout << "Alistamento Confirmado!\n";
        } else {
            throw (505);
        }
    }
    catch(int numb) // aceita (...) para qual quer tipo de erro
    {
        std::cout << "Não é possível se Alistar com idade menor de 18 anos!\n";
        std::cout << "Erro: " << numb << '\n';
    }
    
}