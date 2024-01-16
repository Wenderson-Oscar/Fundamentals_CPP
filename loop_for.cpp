# include <iostream>

using namespace std;

int loop_infinito();
int loop_limitado();
int new_loop_do();
int loop_for1();
int loop_aninhado();
int for_one();
int for_break();
int for_continue();

int main() {
    // loop_infinito();
    // loop_limitado();
    // new_loop_do();
    // loop_for1();
    // loop_aninhado();
    // for_one();
    // for_break();
    // for_continue();
}

int for_continue() {
    for (int row = 1; row <= 9; row++) {
        if (row == 4) {
            continue;
        }
        cout << row << "\n";
    }
    return 0;
}

int for_break() {
    for (int line = 0; line < 10; line++) {
        if (line == 8) {
            break;
        }
        cout << line << "\n";
    }
    return 0;
}

int for_one() {
    int array[3] = {54, 11, 10};
    for (int i: array) {
        cout << i << "\n";
    }
    return 0;
}

int loop_aninhado() {
    for (int row2 = 1; row2 <= 2; ++row2) {
        cout << "for 1" << row2 << "\n";
    for (int row3 = 1; row3 <=3; ++row3) {
        cout << "for 2" << row3 << "\n";
    }
    }
    return 0;
}

int loop_for1() {
    for (int row1 = 1; row1 < 9; row1++) {
        cout << row1 << "\n";
    }
    return 0;
}

int new_loop_do() {
    int countrer = 0;
    do {
        cout << countrer << "\n";
        countrer++;
    }
    while (countrer < 11);
    return 0;
}

int loop_infinito() {
    int number = 0;
    while (number < 10) {
        cout << number << "\n";
        number++;
    }
    return 0;
}

int loop_limitado() {
    int i = 0;
    do {
    cout << i << "\n";
    i++;
    }
    while (i < 5);
    return 0;
}