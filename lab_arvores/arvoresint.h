#ifndef ARVORES_H
#define ARVORES_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct tree {
    int numero;
    struct tree *esquerda;
    struct tree *direita;
};

void printarOrdem(struct tree* A) {
    if (A == NULL) {
        return;
    }
    printarOrdem(A->esquerda);
    printf("%d ", A->numero);
    printarOrdem(A->direita);
}

struct tree *alocarNo(int numero){
    struct tree *newTree = (struct tree*)malloc(sizeof(struct tree));
    newTree->numero = numero;
    newTree->esquerda = NULL;
    newTree->direita = NULL;
    return newTree;
}


void instalaInt(struct tree **A,int numero){
    if(*A == NULL){
        *A = alocarNo(numero);
    }
    else{
        if(numero <= (*A)->numero){
            instalaInt(&(*A)->esquerda, numero);
        }
        else{
            instalaInt(&(*A)->direita, numero);
        }
    }
}

bool buscaArvore(struct tree* A,int numero){
    if(A == NULL){
        return false;
    }
    else{
        if(numero == A->numero){
            return true;
        }
        else if(numero < A->numero){
            return buscaArvore(A->esquerda,numero);
        }
        else if(numero > A->numero){
            return buscaArvore(A->direita,numero);
        }
    }
}

struct tree* pricuraMinimo(struct tree  **A) {
    while ((*A)->esquerda != NULL)
      (*A) = (*A)->esquerda;
    return *A;
}

void deletarInt(struct tree **A,int numero){
    if(*A == NULL){
        return;
    }
    else if (numero <= (*A)->numero){
        deletarInt(&(*A)->esquerda,numero);
    }
    else if (numero > (*A)->numero){
        deletarInt(&(*A)->direita,numero);
    }
    else {
        if((*A)->esquerda == NULL && (*A)->direita == NULL){
            free(A);
            (*A) == NULL;
        }
        else if ((*A)->esquerda == NULL){
            struct tree *newTree = (struct tree*)malloc(sizeof(struct tree));
            (*A) = (*A)->direita;
            free(newTree);
        }
        else if ((*A)->direita == NULL){
            struct tree *newTree = (struct tree*)malloc(sizeof(struct tree));
            (*A) = (*A)->esquerda;
            free(newTree);
        }
        else{
            struct tree* temporaria = pricuraMinimo(&(*A)->direita);
            (*A)->numero = (temporaria)->numero;
            deletarInt(&(*A)->direita, (temporaria)->numero);
        }
    }
}

#endif 