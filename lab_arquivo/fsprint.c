#include <stdio.h>
#include <stdlib.h>

struct emp{
    char nome[40];
    int idade;
    float salario;
};

int main(){
    FILE *fp;
    struct emp emp;
    char outro='Y';
    fp=fopen("empregados.txt","w");
    if(fp==NULL){
        puts("impossivel gravar");
        exit(0);
    }
    while(outro=='Y' || outro == 'y'){
        printf("Escreva dados de um empregado\n");
        scanf("%s %d %f",emp.nome,&emp.idade,&emp.salario);
        fprintf(fp,"%s %d %2.f\n",emp.nome,emp.idade,emp.salario);
        printf("Deseja digitar outro empregado, Y para sim e N para nao ");
        fflush(stdin);
        scanf("%c",&outro);
    }
    fclose(fp);
    return 0;

}