#include <stdio.h>
///funçao de trocar numeros 
void troca_numeros(int *a,int *b){
    ///esta funçao recebe dois endereços de memoria 
    ///e criado uma variavel aux que armazena o valor contido no endereço que *a armazena 
    int aux = *a;
    ///o valor contido no endereço de memoria *a e trocado pelo valor contido no endereço de *b
    *a=*b;
    //o valor contido no endereço de memoria *b recebe o valor de aux
    *b=aux;
}

int main(){
    //declarada duas variaveis 
    int a,b;
    printf("Digite dois valores: ");
    ///leitura das variaveis 
    scanf("%d %d",&a,&b);
    printf("Numeros antes da troca: a = %d b = %d\n",a,b);
    ///chama a funçao e passa o endereço de a e b 
    troca_numeros(&a,&b);
    printf("Numeros depois da troca: a = %d b = %d\n",a,b);


}