#include <stdio.h>
#include <stdlib.h>
#include "listasEncadeadas.h"



int main (){

    struct Tno *plista = NULL;
    if(Vazia(plista))
       printf("A lista esta vazia \n");
    plista = IncluirCabeca(plista,10);
    plista = IncluirCabeca(plista,30);
    if(Vazia(plista))
       printf("A lista esta vazia \n");
    PrintarLista(plista);
    plista = IncluirCalda(plista,2);
    plista = IncluirCalda(plista,8);
    PrintarLista(plista);
    plista = IncluirAntes(plista,2,6);
    plista = IncluirAntes(plista,8,20);
    PrintarLista(plista);
    plista = ExcluirCabeca(plista);
    PrintarLista(plista);
    plista = ExcluirCalda(plista);
    PrintarLista(plista);
    plista = ExcluirChave(plista,6);
    PrintarLista(plista);


    free(plista);

}