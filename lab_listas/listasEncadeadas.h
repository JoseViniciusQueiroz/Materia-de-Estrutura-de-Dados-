#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct Tno {
    int numero;
    struct Tno *proximo;
};

void PrintarLista(struct Tno *plista){
    struct Tno *pAuxiliar;
    pAuxiliar = plista;
    while(pAuxiliar != NULL){
        printf("%d ",pAuxiliar->numero);
        pAuxiliar = pAuxiliar->proximo;
    }
    printf("\n");

}


bool Vazia(struct Tno *plista){
    if(plista == NULL)
        return true;
    else 
       return false;
}

struct Tno *IncluirCabeca(struct Tno *plista,int pValor){
    struct Tno *pAuxiliar;
    pAuxiliar = (struct Tno *)malloc(sizeof(struct Tno));
    pAuxiliar->numero = pValor;
    pAuxiliar->proximo = plista;
    plista = pAuxiliar;
    return plista; 
}

struct Tno *IncluirCalda(struct Tno *plista,int pValor){
    struct Tno *pNovoNo,*pAuxiliar;
    pNovoNo = (struct Tno *)malloc(sizeof(struct Tno));
    pNovoNo->numero = pValor;
    pNovoNo->proximo = NULL;
    pAuxiliar = plista;
    while(pAuxiliar->proximo != NULL)
        pAuxiliar = pAuxiliar->proximo;
    pAuxiliar->proximo = pNovoNo;
    return plista;
    
}

struct Tno *IncluirAntes(struct Tno *plista,int pChave, int pValor){
    struct Tno *pNovoNo, *pAuxiliar;
    pNovoNo = (struct Tno *)malloc(sizeof(struct Tno));
    pNovoNo->numero = pValor;
    if (plista == NULL || plista->numero == pChave) {
        pNovoNo->proximo = plista;
        return pNovoNo;
    }
    pAuxiliar = plista;
    while(pAuxiliar->proximo->numero != pChave){
        pAuxiliar = pAuxiliar->proximo;
    }
    pNovoNo->proximo = pAuxiliar->proximo;
    pAuxiliar->proximo = pNovoNo;
    return plista;
}


struct Tno *ExcluirCabeca(struct Tno *plista){
    struct Tno *pAuxiliar = plista;
    plista = plista->proximo;
    free(pAuxiliar);
    return plista;
}

struct Tno *ExcluirCalda(struct Tno *plista){
    struct Tno *pAuxiliar = plista;
    while (pAuxiliar->proximo->proximo != NULL){
        pAuxiliar = pAuxiliar->proximo;
    }
    free(pAuxiliar->proximo);
    pAuxiliar->proximo = NULL;
    return plista;
}

struct Tno *ExcluirChave(struct Tno *plista,int pChave){
    if (plista == NULL) 
        return NULL;
    if (plista->numero == pChave) {
        struct Tno *pAuxiliar = plista;
        plista = plista->proximo;
        free(pAuxiliar);
        return plista;
    }
    struct Tno *pAnterior = plista;
    while (pAnterior->proximo != NULL && pAnterior->proximo->numero != pChave) {
        pAnterior = pAnterior->proximo;
    }
    if (pAnterior->proximo != NULL) {
        struct Tno *pAuxiliar = pAnterior->proximo;
        pAnterior->proximo = pAuxiliar->proximo;
        free(pAuxiliar);
    }
    return plista;
}
