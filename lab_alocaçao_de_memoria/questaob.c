#include <stdio.h>
#include <stdlib.h>

void adicionacaracter(char **pvetcar ,int *ptammax ,int *pqtde,char elemento){
    if(*ptammax == *pqtde){
       *ptammax *=2;
       *pvetcar =(char *)realloc(*pvetcar,*ptammax * sizeof(char));
       if(*pvetcar == NULL){
          printf("Nao foi possivel fazer a realocacao\n");
          exit(1);
       }
    }
    (*pvetcar)[*pqtde]=elemento;
    (*pqtde) ++;
}

void excluircaracter(char **pvetcar,int *pqtde,char elemento){
    int posicao = -1;
    for(int i=0;i<(*pqtde);i++){
        if(elemento == (*pvetcar)[i]){
            posicao = i;
        }
    }
    if(posicao == -1){
        printf("Caracter nao encontrado\n");
        exit(1);
    }
    for(int j=posicao ; j<(*pqtde -1); j++){
        (*pvetcar)[j] = (*pvetcar)[j+1];
    }
    (*pqtde)--;
    
   
}


int main(){
    int ptammax = 5;
    char *pvetcar =(char *)malloc(ptammax * sizeof(char));
    int pqtde = 0;
 
 
    printf("Informações do vetor antes\n");
    for(int i=0;i<pqtde;i++){
      printf("%c ",pvetcar[i]);
    }
    printf("\n%d %d \n",pqtde,ptammax);
    adicionacaracter(&pvetcar,&ptammax,&pqtde,'a');
    adicionacaracter(&pvetcar,&ptammax,&pqtde,'b');
    printf("Informações do vetor depois\n");
    for(int i=0;i<pqtde;i++){
        printf("%c ",pvetcar[i]);
    }
    printf("\n%d %d \n",pqtde,ptammax);
    excluircaracter(&pvetcar,&pqtde,'a');
    for(int i=0;i<pqtde;i++){
        printf("%c ",pvetcar[i]);
    }
    printf("\n%d %d \n",pqtde,ptammax);

   
    

  

    free(pvetcar);


}