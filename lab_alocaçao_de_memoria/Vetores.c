#include <stdio.h>
#include <stdlib.h>

int* CriaVetint(int tamanho){
    int *vetor=(int *)malloc(tamanho*sizeof(int));
    if(vetor==NULL){
        printf("nao foi possivel criar o vetor\n");
        exit(EXIT_FAILURE);
    }
    return vetor;
}

float* CriaVetFloat(int tamanho){
    float *vetor=(float *)malloc(tamanho*sizeof(float));
    if(vetor==NULL){
        printf("Nao foi possivel criar o vetor\n");
        exit(EXIT_FAILURE);
    }
    return vetor;
}

int main(){
    int tamanho;
    printf("Qual o tamanho da seu vetor: ");
    scanf("%d",&tamanho);
    int *meuVetor=CriaVetint(tamanho);
    for(int i=0;i<tamanho;i++){
        meuVetor[i]=i+1;
    }
    
    for(int i=0;i<tamanho;i++){
        printf("%d ",meuVetor[i]);
    } 
    printf("\n");
    printf("Digite o tamanho do vetor de float: ");
    scanf("%d",&tamanho);
    float *meuVetor2=CriaVetFloat(tamanho);
    for(int i=0;i<tamanho;i++){
        meuVetor2[i]=2.0*i;
    }
    for(int i=0;i<tamanho;i++){
        printf("%.2f ",meuVetor2[i]);
    }
    printf("\n");




}