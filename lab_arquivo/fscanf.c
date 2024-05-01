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
     fp=fopen("empregados.txt","r");
     if(fp==NULL){
        printf("arquivo nao encontrado\n");
        system("pause");
        exit(0);

     }
     while(fscanf(fp,"%s %d %f",emp.nome,&emp.idade,&emp.salario)!=EOF){
        printf("%s %d %2.f\n",emp.nome,emp.idade,emp.salario);
     } 
     system("pause");
     fclose(0);

}