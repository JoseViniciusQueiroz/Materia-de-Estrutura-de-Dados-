#include <stdio.h>
#include <stdlib.h>

int main (){
    FILE *arquivo_copia,*arquivo_original;
    char ch;
    arquivo_original=fopen("texto.txt","r");
    if(arquivo_original==NULL){
        puts("arquivo nao encontrado\n");
        exit(0);
    }
    else{
        arquivo_copia=fopen("copia.txt","w");
        if(arquivo_copia==NULL){
            puts("impossivel gravar");
            exit(0);
        }
        while(1){
            ch=fgetc(arquivo_original);
            if(ch==EOF){
                break;
            }
            fputc(ch,arquivo_copia);
        }
    }
    fclose(arquivo_copia);
    fclose(arquivo_original);
    return 0;


}