# include <iostream>

using namespace std;

int soma();
void pergunta_resposta();
void calculate();

int main() {
    char a = 65, b = 66, c = 67; // vai exibir o default (ABC) caso não receba o esperado 
    cout << a;
    cout << b;
    cout << c; 
    float f1 = 35e3;//adicione 0 a pos a casa 3 é a quantidade
    double d1 = 12E4; //Mesma coisa
    cout << f1 << "\n";
    cout << d1;
   soma();
   pergunta_resposta();
   calculate();
}

int soma() {
     int number1, number2;
    cout << "Digite o Primeiro Número: ";
    cin >> number1;
    cout <<  "Digite o Segundo Número: ";
    cin >> number2;
    int sum = number1 + number2;
    cout << sum << "\n";
    return 0;
}

void pergunta_resposta() {
    cout << "Quantos Anos Você Tem ? ";
    int pergunta;
    cin >> pergunta;
    cout << "Qual o seu nome ? ";
    string nome;
    cin >> nome;
    cout << "Nome: " << nome << "\nIdade: " << pergunta << "\n";
}

void calculate() {
    float number_one;
    float number_two;
    cout << "Digite o Primeiro Número: ";
    cin >> number_one;
    cout << "Digite o Segundo Número: ";
    cin >> number_two;
    cout << "Soma: " << (number_one + number_two) << "\nDiminuição: " << (number_one - number_two) << "\n"
    << "Mutiplicação: " << (number_one * number_two) << "\n Divisão: " << (number_one / number_two) << "\n";
}