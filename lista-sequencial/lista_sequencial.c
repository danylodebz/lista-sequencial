#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int elementos[MAX];
    int tamanho;
} ListaSequencial;

// Criação da lista vazia
void criarListaVazia(ListaSequencial* lista) {
    lista->tamanho = 0;
}

// Verificar se a lista está vazia
int listaEstaVazia(ListaSequencial* lista) {
    return lista->tamanho == 0;
}

// Verificar se a lista está cheia
int listaEstaCheia(ListaSequencial* lista) {
    return lista->tamanho == MAX;
}

// Obter o tamanho da lista
int obterTamanho(ListaSequencial* lista) {
    return lista->tamanho;
}

// Obter o valor do elemento de uma determinada posição na lista
int obterElemento(ListaSequencial* lista, int posicao) {
    if (posicao < 1 || posicao > lista->tamanho) {
        printf("Posição inválida.\n");
        return -1;
    }
    return lista->elementos[posicao - 1];
}

// Modificar o valor do elemento de uma determinada posição na lista
void modificarElemento(ListaSequencial* lista, int posicao, int valor) {
    if (posicao < 1 || posicao > lista->tamanho) {
        printf("Posição inválida.\n");
        return;
    }
    lista->elementos[posicao - 1] = valor;
}

// Inserir um elemento em uma determinada posição
void inserirElemento(ListaSequencial* lista, int posicao, int valor) {
    if (listaEstaCheia(lista)) {
        printf("Lista cheia.\n");
        return;
    }
    if (posicao < 1 || posicao > lista->tamanho + 1) {
        printf("Posição inválida.\n");
        return;
    }
    for (int i = lista->tamanho; i >= posicao; i--) {
        lista->elementos[i] = lista->elementos[i - 1];
    }
    lista->elementos[posicao - 1] = valor;
    lista->tamanho++;
}

// Retirar um elemento de uma determinada posição
void retirarElemento(ListaSequencial* lista, int posicao) {
    if (listaEstaVazia(lista)) {
        printf("Lista vazia.\n");
        return;
    }
    if (posicao < 1 || posicao > lista->tamanho) {
        printf("Posição inválida.\n");
        return;
    }
    for (int i = posicao - 1; i < lista->tamanho - 1; i++) {
        lista->elementos[i] = lista->elementos[i + 1];
    }
    lista->tamanho--;
}

int main() {
    ListaSequencial lista;
    criarListaVazia(&lista);

    inserirElemento(&lista, 1, 10);
    inserirElemento(&lista, 2, 20);
    inserirElemento(&lista, 3, 30);
    printf("Elemento na posição 2: %d\n", obterElemento(&lista, 2));
    modificarElemento(&lista, 2, 25);
    printf("Elemento na posição 2 após modificação: %d\n", obterElemento(&lista, 2));
    retirarElemento(&lista, 2);
    printf("Elemento na posição 2 após remoção: %d\n", obterElemento(&lista, 2));
    printf("Tamanho da lista: %d\n", obterTamanho(&lista));
    
    return 0;
}
