# include <iostream>
# include <cstdlib>

typedef struct no{
    int valor;
    struct no *direita, *esquerda;
} TypeArv;

void print_arv(TypeArv *raiz); //EXIBIR ARVORE
TypeArv* insert_arv(TypeArv *raiz, int numb); //ARVORE LENTA POR CAUSA DA RECURSÃO
void new_arv(TypeArv **raiz, int numb); //MELHORADA USANDO PONTEIRO PARA PONTEIRO (**)
void new_arv1(TypeArv **raiz, int numb); //MELHORADO
TypeArv* search_arv(TypeArv *raiz, int numb); //Busca de Elementos
TypeArv* search_arv1(TypeArv *raiz, int numb); //Busca Melhorada
int height_arv(TypeArv *raiz); // Tamanho da arvore
int count_no(TypeArv *raiz); // Quantidade de No
int count_sheet(TypeArv *raiz); // Quantidade de Folha
TypeArv* remove_sheet(TypeArv *raiz, int key);

int main() {
    TypeArv *search, *raiz = NULL;
    int option, valor;
    do {
        std::cout << "\t1 - Inserir Valor \n\t2 - Imprimir Arvore\n\t3 - Buscar Valor\n\t4 - Altura da Arvore\n\t5 - Quantidade de No\n\t6 - Quantidade de Folhas\n\t7 - Remover Folha\n\t0 - Sair\n";
        std::cin >> option;
        switch (option)
        {
        case 1:
            std::cout << "Digite um Valor: \n";
            std::cin >> valor;
            // raiz = insert_arv(raiz, valor);
            new_arv1(&raiz, valor);
            break;
        case 2:
            std::cout << "Imprimir Arvore" << "\n";
            print_arv(raiz);
            break;
        case 3:
            std::cout << "Digite um valor que precisa procurar: \n";
            std::cin >> valor;
            search = search_arv1(raiz, valor);
            if (search) {
                std::cout << "Valor encontrado: " << search->valor << '\n';
            } else {
                std::cout << "Número não encontrado!\n";
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
            std::cout << "Digite o Valor a ser Removido: ";
            std::cin >> valor;
            remove_sheet(raiz, valor);
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

TypeArv* remove_sheet(TypeArv *raiz, int key) {
    if (raiz == NULL) {
        std::cout << "Valor não encontrado\n";
        return NULL;
    } else {
        if (raiz->valor == key) {
            if (raiz->esquerda == NULL && raiz->direita == NULL) {
                free(raiz);
                std::cout << "Folha Removido da Arvore: " << key << '\n';
                return NULL;
            } else {
                if (raiz->esquerda != NULL && raiz->direita != NULL) {
                    TypeArv *pt = raiz->esquerda;
                    while (pt->direita != NULL) {
                        pt = pt->direita;
                    }
                    raiz->valor = pt->valor;
                    pt->valor = key;
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
            if (key < raiz->valor) {
                raiz->esquerda = remove_sheet(raiz->esquerda, key);
            } else {
                raiz->direita = remove_sheet(raiz->direita, key);
            }
            return raiz;
        }
    }
    return raiz;
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

int count_no(TypeArv *raiz) {
    if (raiz == NULL) {
        return 0;
    } else {
        return 1 + count_no(raiz->esquerda) + count_no(raiz->direita);
    }
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

TypeArv* search_arv1(TypeArv *raiz, int numb) {
    while (raiz) {
        if (numb < raiz->valor) {
            raiz = raiz->esquerda;
        } else if (numb > raiz->valor) {
            raiz = raiz->direita;
        } else {
            return raiz;
        }
    }
    return NULL;
}

TypeArv* search_arv(TypeArv *raiz, int numb) {
    if (raiz) {
        if (numb == raiz->valor) {
            return raiz;
        } else if (numb < raiz->valor) {
            return search_arv(raiz->esquerda, numb);
        } else {
            return search_arv(raiz->direita, numb);
        }
    }
    return NULL;
}

void new_arv1(TypeArv **raiz, int numb) {
    TypeArv *pt = *raiz;
    while (pt) {
        if (numb < pt->valor) {
            raiz = &pt->esquerda;
        } else {
            raiz = &pt->direita;
        }
        pt = *raiz;
    }
    pt = (TypeArv*) malloc(sizeof(TypeArv));
    pt->valor = numb;
    pt->esquerda = NULL;
    pt->direita = NULL;
    *raiz = pt;
}

void new_arv(TypeArv **raiz, int numb) {
    if (*raiz == NULL) {
        *raiz = (TypeArv*) malloc(sizeof(TypeArv));
        (*raiz)->valor = numb;
        (*raiz)->esquerda = NULL;
        (*raiz)->direita = NULL;
    } else {
        if (numb < (*raiz)->valor) {
            new_arv(&((*raiz)->esquerda), numb);
        } else {
            new_arv(&((*raiz)->direita), numb);
        }
    }
}

void print_arv(TypeArv *raiz) {
    if (raiz) {
        std::cout << raiz->valor << '\n';
        print_arv(raiz->esquerda);
        print_arv(raiz->direita);
    }
}

TypeArv* insert_arv(TypeArv *raiz, int numb) {
    if (raiz == NULL) {
        TypeArv *pt = (TypeArv*) malloc(sizeof(TypeArv));
        pt->valor = numb;
        pt->esquerda = NULL;
        pt->direita = NULL;
        return pt;
    } else {
        if (numb < raiz->valor) {
            raiz->esquerda = insert_arv(raiz->esquerda, numb);
        } else {
            raiz->direita = insert_arv(raiz->direita, numb);
        }
        return raiz;
    }
}
