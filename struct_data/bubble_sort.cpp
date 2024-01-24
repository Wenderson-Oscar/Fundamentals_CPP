# include <iostream>

void bubble_sort(int *v, int len) {
    int troc = 1;
    std::cout << "Vetor: ";
    for (int y = 0; y < len; ++y) {
        std::cout << v[y];
    }
    while (troc) {
        troc = 0;
        for (int i = 0; i < len-1; i++) {
            if (v[i] > v[i+1]) {
                int aux = v[i];
                v[i] = v[i+1];
                v[i+1] = aux;
                troc = 1;
            }
        }
    }
    std::cout << "\nVetor com Bubble Sort: ";
    for (int y = 0; y < len; ++y) {
        std::cout << v[y];
    }
    std::cout << '\n';
}

int main() {
    int troc = 1;
    int n = 7;
    int vettor1[7] = {0,9,2,1,4,3,7};
    std::cout << "Vetor: ";
    for (int y = 0; y < n; ++y) {
        std::cout << vettor1[y];
    }
    while (troc) {
        troc = 0;
        for (int i = 0; i < n-1; i++) {
            if (vettor1[i] > vettor1[i+1]) {
                int aux = vettor1[i];
                vettor1[i] = vettor1[i+1];
                vettor1[i+1] = aux;
                troc = 1;
            }
        }
    }
    std::cout << "\nVetor com Bubble Sort: ";
    for (int y = 0; y < n; ++y) {
        std::cout << vettor1[y];
    }
    std::cout << '\n';
    /* Melhorado */
    std::cout << "Melhorado" << '\n';
    int vettor[] = {0,9,2,1,4,3,7};
    bubble_sort(vettor, 7);
    return 0;
}