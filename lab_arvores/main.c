#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvoresint.h"


int main(){
    struct tree *arvore = NULL;
    instalaInt(&arvore,3);
    instalaInt(&arvore,50);
    instalaInt(&arvore,60);
    printarOrdem(arvore);
    printf("\n");
    deletarInt(&arvore,60);
    printarOrdem(arvore);
}