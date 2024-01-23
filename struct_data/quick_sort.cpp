#include <iostream>

int parti(int* vettor, int init, int end) {
    int pivot = vettor[(init + end) / 2];
    while (init <= end) {
        while (vettor[init] < pivot) {
            init++;
        }
        while (vettor[end] > pivot) {
            end--;
        }
        if (init <= end) {
            int temp = vettor[init];
            vettor[init] = vettor[end];
            vettor[end] = temp;
            init++;
            end--;
        }
    }
    return init;
}

void quick_sort(int *vettor, int init, int end) {
    if (init < end) {
        int pos = parti(vettor, init, end);
        quick_sort(vettor, init, pos - 1);
        quick_sort(vettor, pos, end);
    }
}

void print(int *vettor, int len) {
    for (int i = 0; i < len; i++) {
        std::cout << vettor[i] << '\n';
    }
}

int main() {
    int vettor[] = {4, 56, 29, 876, 90, 645, 23, 66, 53, 122, 9};
    print(vettor, 11);
    quick_sort(vettor, 0, 10);
    std::cout << "Ordenação correta: \n";
    print(vettor, 11);
    return 0;
}
