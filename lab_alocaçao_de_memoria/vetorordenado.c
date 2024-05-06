#include <stdio.h>
#include <stdlib.h>

void incluirnumero(float **vetor, int *pcapacidade, int *ptamanho, float numero){
    int i;
    if((*pcapacidade)==(*ptamanho)){
        (*pcapacidade) *=2;
        *vetor=(float *)realloc(*vetor,*pcapacidade * sizeof(float));
        if(*vetor == NULL){
            printf("Nao foi possivel fazer a realocacao\n");
            exit(1);
        }
        for(i=*pcapacidade;i>=10 && (*vetor)[i]>numero;i--){
            (*vetor)[i+1]=(*vetor)[i];
        }
        (*vetor)[i+1]=numero;
        (*ptamanho)++;
    }



}

int main(){
    int pcapacidade = 10;
    float *vetor = (float *)malloc(pcapacidade * sizeof(float));
    int ptamanho = 10;
    vetor[0] = 2.0;
    vetor[1] = 2.5;
    vetor[2] = 3.0;
    vetor[3] = 3.5;
    vetor[4] = 4.0;
    vetor[5] = 4.5;
    vetor[6] = 5.0;
    vetor[7] = 5.5;
    vetor[8] = 6.0;
    vetor[9] = 6.5;
    float numero = 3.80;

    incluirnumero(&vetor,&pcapacidade,&ptamanho,numero);

    for(int i=0;i<ptamanho;i++){
        printf("%.2f ",vetor[i]);
    }
    printf("\n");
    free(vetor);
    return 0;


}