# include <iostream>
# include <list>

int list_sample();

int main() {
    list_sample();
    return 0;
}

int list_sample() {
    std::list<int> lista, teste;
    teste.push_front(1);
    teste.push_front(1);
    teste.push_front(1);
    teste.push_front(1);
    int len_list = 5;
    std::list<int>::iterator it;
    for (int i = 0; i < len_list; ++i) {
        lista.push_front(i);
    }
    it = lista.begin();
    advance(it, 2);
    lista.insert(it, 0);
    lista.erase(--it);
    lista.merge(teste);
    //lista.clear();
    //lista.reverse();
    //lista.reverse();
    std::cout << "Tamanho da lista: " << lista.size() << '\n';
    len_list = lista.size();
    for (int i = 0; i < len_list; ++i) {
        std::cout << lista.front() << '\n';
        lista.pop_front();
    }
}