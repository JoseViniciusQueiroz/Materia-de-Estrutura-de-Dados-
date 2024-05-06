#include <stdio.h>

long int somaint(int *a, int qtde){
    if(qtde == 0 ){
        return 0;
    }
    return a[qtde-1]+somaint(a,qtde-1);

}

int main(){
    int a[10] = {1,2,3,4,5,6,7,8,9,10};
    printf("%ld\n",somaint(a,10));



}