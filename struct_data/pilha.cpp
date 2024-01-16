# include <iostream>
# include <stack>

int pilha();

int main() {
    pilha();
}

int pilha() {
    std::stack<int> pilha_sample;
    if (pilha_sample.empty()) { //pilha vazia
        std::cout << "Pilha vazia\n";
    } else {
        std::cout << "Pilha Não vazia\n";
    }
    pilha_sample.push(1);
    pilha_sample.push(2);
    pilha_sample.push(3);
    pilha_sample.push(4);
    pilha_sample.push(5);
    std:: cout << "Tamanho da Pilha: " << pilha_sample.size() << '\n';
    std:: cout << "Número do Topo: " << pilha_sample.top() << '\n';
    pilha_sample.pop();
    pilha_sample.pop();
    std:: cout << "Novo Número do Topo: " << pilha_sample.top() << '\n';
    return 0;
}