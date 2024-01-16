#include <iostream>
#include <string>

using namespace std;

string arrays_string();
int arrays_numbers();
int arrays_multdimension();
string array_olf();

int main() {
    // arrays_string();
    // arrays_numbers();
    // arrays_multdimension();
}

int arrays_multdimension() {
    int array_mult[2][5] = {{1,2,3,4,5},{5,4,3,2,1}};
    string array_mult_s[2][2][2] = {
        {
            {"Oscar", "Silva"},
            {"Solteiro", "Casado"}
        }, 
        {
            {"M", "M"},
            {"Programador", "Desenvolvedor"}
        }
    };
    for (int z = 0; z < 2; z++) {
        for (int x = 0; x < 2; x++) {
            for (int c = 0; c < 2; c++) {
                cout << array_mult_s[z][x][c] << "\n";
            }
        }
    }
    for (int x = 0; x < 2; x++) {
        for (int y = 0; y < 5; y++) {
            cout << array_mult[x][y] << "\n";
        }
    }
    return 0;
}

int arrays_numbers() {
    int number[] = {1,4,6,8};
    /* For Normal */
    for (int y = 0; y < 4; y++) {
        cout << number[y] << "\n";
    }
    /* Tamanho do Array */
    cout << "Tamanho do array em Bytes " << sizeof(number) << "\n";
    int get_array = sizeof(number) / sizeof(int);
    cout << "Tamanho do Array " << get_array << "\n";
    /* For sem especificar o tamanho */
    for (int x = 0; x < sizeof(number) / sizeof(int); x++) {
        cout << number[x] << "\n";
    }
    /* For para arrays */
    for (int z: number) {
        cout << z << "\n";
    }
    return 0;
}

string arrays_string() {
    string names[3] = {"Ana", "Eliza", "Bia"};
    for (string x: names) {
        cout << x << "\n";
    }
    for (string i: names) {
        cout << i << "\n";
        if (i == "Ana") {
            cout << "Dejesa Mudar de Nome ? [S/N] \n";
            char option;
            cin >> option;
            if (option == 'S') {
                cout << "Digite Seu novo Nome: \n";
                cin.ignore();
                string new_name;
                getline(cin, new_name);
                names[0] = new_name;
                cout << names[0] << "\n";
            }
        } 
        names[2] = "Wenderson";
    }
    return 0;
}