#include <stdio.h>

int fatorial(int numero){
    if(numero == 1){
        return 1;
    }
    else{
        return numero * (fatorial(numero-1));
    }
}

int main(){
    int d;
    printf("Digite um numero: ");
    scanf("%d",&d);
    int r = fatorial(d);
    printf("Sua fatorial e: %d\n", r);
}