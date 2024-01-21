# include <iostream>
# include <cstdlib>

typedef struct{
    char name[50];
    int id;
}Client;

typedef struct no{
    Client client;
    struct no *direita, *esquerda;
} TypeArv;


Client char_arv() {
    Client p;
    std::cout << "Digite o nome da Pessoa: ";
    std::cin >> p.name;
    std::cout << "Digite o id: ";
    std::cin >> p.id;
    return p;
}

void print_person(Client p) {
    std::cout << "Nome da Pessoa: " << p.name << '\n';
    std::cout << "Id: " << p.id << '\n';
}

void print_arv(TypeArv *raiz) {
    if (raiz) {
        print_person(raiz->client);
        print_arv(raiz->esquerda);
        print_arv(raiz->direita);
    }
}

void insert_arv(TypeArv **raiz, Client p) {
    TypeArv *pt = *raiz;
    while (pt) {
        if (p.id < pt->client.id) { 
            raiz = &pt->esquerda;
        } else {
            raiz = &pt->direita;
        }
        pt = *raiz;
    }
    pt = (TypeArv*) malloc(sizeof(TypeArv));
    pt->client = p;
    pt->esquerda = NULL;
    pt->direita = NULL;
    *raiz = pt;
}

TypeArv* search_arv(TypeArv *raiz, int id) {
    if (raiz) {
        if (id == raiz->client.id) {
            return raiz;
        } else if (id < raiz->client.id) {
            return search_arv(raiz->esquerda, id);
        } else {
            return search_arv(raiz->direita, id);
        }
    }
    return NULL;
}

int height_arv(TypeArv *raiz) {
    if (raiz == NULL) {
        return -1;
    } else {
        int esq = height_arv(raiz->esquerda);
        int dir = height_arv(raiz->direita);
        if (esq > dir) {
            return esq +1;
        } else {
            return dir +1;
        }
    }
}

int count_no(TypeArv *raiz) {
    if (raiz == NULL) {
        return 0;
    } else {
        return 1 + count_no(raiz->esquerda) + count_no(raiz->direita);
    }
}

int count_sheet(TypeArv *raiz) {
    if (raiz == NULL) {
        return 0;
    } else if (raiz->esquerda == NULL && raiz->direita == NULL) {
        return 1;
    } else {
        return count_sheet(raiz->esquerda) + count_sheet(raiz->direita);
    }
}

TypeArv* remove_sheet(TypeArv *raiz, int key) {
    if (raiz == NULL) {
        std::cout << "Valor não encontrado\n";
        return NULL;
    } else {
        if (raiz->client.id == key) {
            if (raiz->esquerda == NULL && raiz->direita == NULL) {
                free(raiz);
                std::cout << "Folha Removido da Arvore: " << key << '\n';
                return NULL;
            } else {
                if (raiz->esquerda != NULL && raiz->direita != NULL) {
                    Client p;
                    TypeArv *pt = raiz->esquerda;
                    while (pt->direita != NULL) {
                        pt = pt->direita;
                    }
                    p = raiz->client;
                    raiz->client = pt->client;
                    pt->client = p;
                    std::cout << "Elemento Trocado: " << key << '\n';
                    raiz->esquerda = remove_sheet(raiz->esquerda, key);
                    return raiz;
                } else {
                    TypeArv *pt;
                    if (raiz->esquerda != NULL) {
                        pt = raiz->esquerda;
                    } else {
                        pt = raiz->direita;
                    }
                    free(raiz);
                    std::cout << "Valor com 1 Filho Removido da Arvore: " << key << '\n';
                    return pt;
                }
            }
        } else {
            if (key < raiz->client.id) {
                raiz->esquerda = remove_sheet(raiz->esquerda, key);
            } else {
                raiz->direita = remove_sheet(raiz->direita, key);
            }
            return raiz;
        }
    }
    return raiz;
   }


int main() {
    TypeArv *search, *raiz = NULL;
    int option, valor;
    do {
        std::cout << "\t1 - Inserir Valor \n\t2 - Imprimir Arvore\n\t3 - Buscar Valor\n\t4 - Altura da Arvore\n\t5 - Quantidade de No\n\t6 - Quantidade de Folhas\n\t7 - Remover Folha\n\t0 - Sair\n";
        std::cin >> option;
        switch (option)
        {
        case 1:
            insert_arv(&raiz, char_arv());
            break;
        case 2:
            std::cout << "Imprimir Arvore" << "\n";
            print_arv(raiz);
            break;
        case 3:
            std::cout << "Digite o id que precisa procurar: \n";
            std::cin >> valor;
            search = search_arv(raiz, valor);
            if (search) {
                std::cout << "Pessoa encontrado: " << search->client.name << '\n';
            } else {
                std::cout << "Pessoa não encontrado!\n";
            }
            break;
        case 4:
            std::cout << "Altura da Arvore: " << height_arv(raiz) << '\n';
            break;
        case 5:
            std::cout << "Quantidade de No: " << count_no(raiz) << '\n';
            break;
        case 6:
            std::cout << "Quantidade de Folhas: "  << count_sheet(raiz) << '\n';
            break;
        case 7:
            print_arv(raiz);
            std::cout << "Digite o id a ser Removido: ";
            std::cin >> valor;
            raiz = remove_sheet(raiz, valor);
            break;
        default:
            if (option != 0) {
                std::cout << "Opção Invalida!\n";
            }
            break;
        }
    } while (option != 0);
    return 0;
}