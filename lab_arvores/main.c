#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvores.h"


int main(){
    struct tree* arvore = NULL;
    arvore = instala(arvore,"janeiro");
    arvore = instala(arvore,"fevereiro");
    arvore = instala(arvore,"marco");
    arvore = instala(arvore,"abril");
    arvore = instala(arvore,"maio");
    arvore = instala(arvore,"junho");
    arvore = instala(arvore,"julho");
    arvore = instala(arvore,"agosto");
    arvore = instala(arvore,"setembro");
    arvore = instala(arvore,"outubro");
    arvore = instala(arvore,"novembro");
    arvore = instala(arvore,"dezembro");
    printarOrdem(arvore);
    printf("\n");
    arvore = deletarChar(arvore,"julho");
    arvore = deletarChar(arvore,"junho");
    arvore = deletarChar(arvore,"agosto");
    arvore = deletarChar(arvore,"novembro");
    arvore = deletarChar(arvore,"maio");
    printarOrdem(arvore);
    printf("\n");
}