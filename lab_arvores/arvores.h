#ifndef ARVORES_H
#define ARVORES_H
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct tree{
    char mes[100];
    struct tree *esquerda;
    struct tree *direita; 
};

void printarOrdem(struct tree* A) {
    if (A == NULL) {
        return;
    }
    printarOrdem(A->esquerda);
    printf("%s ", A->mes);
    printarOrdem(A->direita);
}


struct tree* instala(struct tree* A, char* palavra) {
    if (A == NULL) {
        struct tree *newTree = (struct tree*)malloc(sizeof(struct tree));
        strcpy(newTree->mes, palavra);
        newTree->esquerda = NULL;
        newTree->direita = NULL;
        return newTree;
    }
    if (strcmp(palavra, A->mes) < 0) {
        A->esquerda = instala(A->esquerda, palavra);
    } else {
        A->direita = instala(A->direita, palavra);
    }
    return A;
}

bool buscaArvore(struct tree* A, char* palavra){
    if(A == NULL){
        return false;
    }
    else{
        if(strcmp(palavra,A->mes)==0){
            return true;
        }
        else if(strcmp(palavra,A->mes)<0){
            return buscaArvore(A->esquerda,palavra);
        }
        else{
            return buscaArvore(A->direita,palavra);
        }
    }
}


struct tree* pricuraMinimo(struct tree* A) {
    while (A->esquerda != NULL)
      A = A->esquerda;
    return A;
}

struct tree* deletarChar(struct tree* A, char* palavra){
    if(A == NULL){
        return A;
    }
    else if(strcmp(palavra,A->mes)<0){
        A->esquerda = deletarChar(A->esquerda,palavra);
    }
    else if(strcmp(palavra,A->mes)>0){
        A->direita = deletarChar(A->direita,palavra);
    }
    else{
        if(A->esquerda == NULL && A->direita == NULL){
            free(A);
            A == NULL;
        }
        else if(A->esquerda == NULL){
            struct tree* temporaria = A;
            A = A->direita;
            free(temporaria);
        }
        else if (A->direita == NULL){
            struct tree* temporaria = A;
            A = A->esquerda;
            free(temporaria);
        }
        else{
            struct tree* temporaria = pricuraMinimo(A->direita);
            strcpy(A->mes,temporaria->mes);
            A->direita = deletarChar(A->direita, temporaria->mes);
        }
    }
    return A;
}



#endif 