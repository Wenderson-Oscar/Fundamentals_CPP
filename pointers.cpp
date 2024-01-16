# include <iostream>
#include <variant>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

string ponteiro();
int number_sum(int x);
void school(string name, int idade);
void pointers_function(int &x, int &y);
void array_function(int numbers[5]);
int pointers_functions_array(int array[3]);
string mudantion_name(string &name);
string mudantion_array(string array[5]);
void type_array(const variant<int, double, string>* new_array);
int pointers_array_in_array();
int alocation_memory();
int alocation_memory1();

int main() {
    alocation_memory1();
    return 0;
}

int alocation_memory1() {
    int* array, len;
    cout << "Digite o tamanho da array: \n";
    scanf("%d", &len);
    srand(time(NULL));
    array = (int *) malloc(len * sizeof(int));
    if (array) {
        cout << "Memoria alocado com Sucesso! \n";
        for (int i =0; i < len; i++) {
            *(array + i) = rand() % 100;
        }
        for (int i = 0; i < len; i++) {
            cout << *(array + i) << endl;
        }
        cout << "DIgite o novo tamanho do array: \n";
        cin >> len;
        realloc(array, len);
        cout << "Array Realocado\n";
        for (int i = 0; i < len; i++) {
            *(array + i) = rand() % 100;
            cout << array[i] << endl;
        }
    } else {
        cout << "Erro ao alocar memoria!\n";
    }
    free(array);
}

int alocation_memory() {
    int* x;
    char* z;
    x = (int *) malloc(sizeof(int)); // tipo
    z = (char *) calloc(1, sizeof(char)); // dois parametros, quantidade e tipo

    if (x && z) {
        cout << "Memoria alocado / valor default " << *x << " Endereço " << x << endl;
        cout << "Memoria alocado / valor default " << *z << " Endereço " << z << endl; //Nulo
        *x = 90;
        *z = 'H';
        cout << "Valor da variavel " << *x << " Endereço " << x << endl;
        cout << "Valor da variavel " << *z << " Endereço " << z << endl;
    } else {
        printf("Memoria Não alocada\n");
    }
    free(x); // liberação de memoria / limpeza
    free(z);
    return 0;
}

int pointers_array_in_array() {
    int array_one[3] = {1,4,6};
    int array_two[3] = {9,8,7};
    int* pt = array_one;
    int* pt1 = array_two;
    int array_new[6];
    for (int i = 0; i < 3; i++) {
        array_new[i] = *pt;
        pt++;
    }
    for (int x = 3; x < 6; x++) {
        array_new[x] = *pt1;
        pt1++;
    }
    for (int z = 0; z < 6; z++) {
        cout << array_new[z] << " | " << &array_new[z] << endl;
    }
    cout << "Array 1: " << pt << " Array 2: " << pt1 << " Array ponteiro " << array_new << endl;
}

void type_array(const variant<int, double, string>* new_array) {
    string name;
    int idade = 0;
    double altura = 0;
    for (int x = 0; x < 3; x++) {
        if (holds_alternative<int>(new_array[x])) {
            idade = get<int>(new_array[x]);
        } else if (holds_alternative<double>(new_array[x])) {
            altura = get<double>(new_array[x]);
        } else if (holds_alternative<string>(new_array[x])) {
            name = get<string>(new_array[x]);
        }
    }
    cout << "Nome: " << name << " Idade: " << idade << " Altura: " << altura << endl;
}

string mudantion_array(string array[5]) {
    for (int x = 0; x < 5; x++) {
        cout << array[x] << " | " << &array[x] << endl;
    }
    string* pt = array;
    cout << "Endereço do array: " << pt << endl;
    cout << "Mudança de dados...\n";
    for (int z = 0; z < 5; z++) {
        array[0] = "Wanderson";
        array[2] = "Handerson";
        array[4] = "Uenderson";
        cout << array[z] << " | " << &array[z] << endl;
    }
}

string mudantion_name(string &name) {
    cout << name << endl;
    string* pt = &name;
    cout << "Ponteiro (Endereço de memorial da variavel): " << pt << endl;
    *pt = "Wenderson";
    cout << "Mudança da variavel pelo endereço. " << *pt << endl;
    cout << name << " | " << *pt << endl;
}

int pointers_functions_array(int array[3]) {
    int* pt;
    for (int i = 0; i < 3; i++) {
        cout << array[i] << endl;
    }
    pt = array;
    cout << pt << endl;
}

void array_function(int numbers[5]) {
    for (int i = 0; i < 5; i++) {
        cout << numbers[i] << endl;
    }
}

void pointers_function(int &x, int &y) {
    int z = x;
    x = y;
    y = z;
}

void school(string name, int idade) {
    cout << "Digite o Seu Nome: \n";
    cin >> name;
    cout << "Digite a sua Idade: \n";
    cin >> idade;
    cout << "Seu Nome: " << name << " Sua Idade: " << idade << endl;
}

int number_sum(int x) {
    return 9 + x;
}

string ponteiro() {
    string name = "Oscar";
    string* point = &name;
    cout << name << " " << &name << " " << point << endl;
    cout << name << " " << *point << endl; // * antes da variavel mostra o valor
    *point = "Wenderson";
    cout << name << " " << *point << endl; // Mudando o valor da varial original pelo endereço
}