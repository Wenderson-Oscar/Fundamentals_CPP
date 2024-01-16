# include <iostream>

using namespace std;

int alistamento();
void mudanda_nome();
int impa_par();
double calculadora_completa();
double bonus_salario();
int triangulo();
double area_terreno();
int operador_ternario();
int operador_ternario2();

int main() {
    operador_ternario2();
    operador_ternario();
    alistamento();
    mudanda_nome();
    impa_par();
    calculadora_completa();
    bonus_salario();
    triangulo();
    area_terreno();
}
int operador_ternario2() {
    cout << "Dias em Switch\n";
    int dia = 2;
    switch (dia)
    {
    case 1:
        cout << "Dia 1\n";
        break;
    case 2:
        cout << "Dia 2\n";
        break;
    case 3:
        cout << "Dia 3\n";
        break;
    case 4:
        cout << "Dia 4\n";
        break;
    default:
        cout << "Se não entrar nas condições entra no default";
        break;
    }
    return 0;
}

int operador_ternario() {
    int idade = 10;
    string result = (idade < 11) ? "Bom\n": "Não\n";
    cout << result;
    return 0;
}

double area_terreno() {
    cout << "Área do Terreno\n";
    cout << "Digite a Largura: \n";
    double largura;
    cin >> largura;
    cout << "Digite a Comprimento: \n";
    double comprimento;
    cin >> comprimento;
    double result = largura * comprimento;
    cout << "Área de um Terreno " << largura << "-" << comprimento << " é de " << result << "m² \n";
    return 0;
}

int triangulo() {
    cout << "Formação de Triângulo";
    int reta1;
    int reta2;
    int reta3;
    cout << "Primeiro Segmento: \n";
    cin >> reta1;
    cout << "Segundo Segmento: \n";
    cin >> reta2;
    cout << "Terceiro Segmento: \n";
    cin >> reta3;
    if (reta1 < reta2 + reta3 && reta2 < reta1 + reta3 && reta3 < reta1 + reta2) {
        cout << "Triângulo pode ser Formado!\n";
    } else {
        cout << "Triângulo Não pode ser Formado!\n";
    }
    return 0;
}

double bonus_salario() {
    cout << "Digite o seu Sálario: \n";
    double salario;
    cin >> salario;
    if (salario <= 1400) {
        double aumento = salario+(salario*5/100);
        cout << "Seu Sálario com Bonus de 5%: " << aumento << "\n";
    } else if (salario > 1400 && salario <= 2000 ) {
        double aumento = salario+(salario *10/100);
        cout << "Seu Sálario com Bonus de 10%: " << aumento << "\n";
    }
    return 0;
}

double calculadora_completa() {
    cout << "Calculadora\n";
    double number1;
    cout << "Digite o Primeiro Numero: \n";
    cin >> number1;
    cout << "Digite o Segundo Número: \n";
    double number2;
    cin >> number2;
    cout << "Digite o Operador [(+) | (-) | (*) | (/) ]: \n";
    char operador;
    cin >> operador;
    if (operador == '+') {
        cout << "Resultado: " << number1 + number2 << "\n";
    } else if (operador == '-') {
        cout << "Resultado: " << number1 - number2 << "\n";
    } else if (operador == '*') {
        cout << "Resultado: " << number1 * number2 << "\n";
    } else if (operador == '/') {
        cout << "Resultado: " << number1 / number2 << "\n";
    }
    return 0;
}

int impa_par() {
    cout << "Impa vc Par\n";
    cout << "Jogador 1: ";
    int player1;
    cin >> player1;
    cout << "Jogador 2: ";
    int player2;
    cin >> player2;
    int calculo = player1 + player2;
    if (calculo % 2 == 0) {
        cout << "Jogador 1 Ganhou!";
    } else {
        cout << "Jogador 2 Ganhou!";
    }
    return 0;
}

void mudanda_nome() {
    cout << "Qual o Seu nome ? ";
    string nome;
    cin >> nome;
    cout << "Seu nome é " << nome << "\n";
    cout << "Deseja Mudar de nome ? [S ou N] \n";
    char mudar;
    cin >> mudar;
    if (mudar == 'S') {
        string novo_nome;
        cout << "Qual o seu Novo nome ? \n";
        cin >> novo_nome;
        cout << "Seu novo nome é " << novo_nome << "\n";
    }
}

int alistamento() {
    cout << "Quantos Anos Você Tem ? ";
    int idade;
    cin >> idade;
    if (idade >= 18) {
        cout << "Pronto para o Alistamento ?";
    } else {
        cout << "Muito Jovem para se Alistar!\n";
    }
    return 0;
}