#include <iostream>

using namespace std;

int main() {
    string referencia = "Referencia variavel";
    string &extensao = referencia;
    string extensao_a = referencia;
    cout << referencia << " " << extensao << " " << extensao_a << endl;
    extensao_a = "nome";
    cout << referencia << " " << extensao << " " << extensao_a << endl;
    extensao = "nome1";
    cout << referencia << " " << extensao << " " << extensao_a << endl;
    cout << "ENDEREÇO DE MEMORIAL DA VARIAVEL: " << &extensao_a << endl;
    cout << "ENDEREÇO DE MEMORIAL DE VARIAVEL REFERENCIA: " << &extensao << " " << &referencia << endl;
    struct struct_nomeada {
        int idade;
        string curso;
    };
    struct_nomeada pessoa ;
    cout << "Quantos Anos vc Tem ? \n";
    cin >> pessoa.idade;
    cout << "Qual seu curso ? \n";
    cin >> pessoa.curso;
    cout << "Idade: " << pessoa.idade << " Curso: " << pessoa.curso << endl;
    struct {
        int numbers;
        string names;
    } conjunto, conjunto1, conjunto2;
    conjunto1.names = "Silva";
    conjunto2.names = "Wenderson";
    conjunto.names = "Oscar";
    conjunto.numbers = 21;
    conjunto1.numbers = 10;
    conjunto2.numbers = 30;
    cout << conjunto.names << "-" << conjunto.numbers << endl;
    cout << conjunto1.names << "-" << conjunto1.numbers << endl;
    cout << conjunto2.names << "-" << conjunto2.numbers << endl;
    return 0;
}