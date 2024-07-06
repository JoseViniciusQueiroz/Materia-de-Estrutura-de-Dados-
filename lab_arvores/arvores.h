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

#endif 