#include <stdio.h>


int buscaSequencialOrdenada(int *vetor,int tamanho,int chave){
    int posicao = 0 , resultado = -1;
    while(posicao < tamanho && chave <= vetor[posicao]){
        if (vetor[posicao]==chave){
            resultado = posicao;
            break
        }
        p++;
    }
    return resultado;
}



int buscaBinaria(int *vetor,int tamanho,int chave){
    int inicio,final,meio;
    inicio = 0;
    final = tamanho-1;
    while(inicio<=final){
        meio=(inicio+final)/2;
        if(chave == vetor[meio]){
            return meio;
        }
        if(chave < vetor[meio])
            final = meio - 1;
        else 
            inicio = meio + 1;
    }
    return -1;

}

