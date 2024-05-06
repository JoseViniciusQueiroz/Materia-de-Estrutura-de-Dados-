#include <stdio.h>

int compararstring(char *str1,char *str2){
    if(*str1=='\0' && *str2 == '\0'){
        return 1;
    }
    if(*str1=='\0' || *str2 == '\0'){
        return 0;
    }
    if(*str1 != *str2 ){
        return 0;
    }

    return compararstring(str1+1,str2+1);

}
int main(){
    char str1[10] , str2[10];
    printf("Digite uma palavra: ");
    scanf("%s",str1);
    printf("Digite outra palavra: ");
    scanf("%s",str2);
    if(compararstring(str1,str2)){
        printf("As duas palavras sao iguais\n");
    }
    else{
        printf("As duas palavras sao diferentes\n");
    }

}