#include <iostream>
#include <queue>

int sample_fila();

int main () {
    sample_fila();
}

int sample_fila() {
    std::queue <int> fila_number;
    fila_number.push(2);
    fila_number.push(10);
    fila_number.push(90);
    fila_number.push(4);
    fila_number.push(3);
    std::cout << "Tamanho da fila: " << fila_number.size() << '\n';
    std::cout << "Primeira da fila: " << fila_number.front() << '\n';
    std::cout << "Ultimo da fila: " << fila_number.back() << '\n';
    while (!fila_number.empty()) {
        std::cout << "fila: " << fila_number.front() << '\n';
        fila_number.pop();
    }
    return 0;
}