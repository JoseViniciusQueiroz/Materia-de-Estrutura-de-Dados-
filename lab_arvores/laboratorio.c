#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//estrutura dos dados em forma de arvore
typedef struct dadosCancer{
    int age;
    char race;
    char maritalStatus;
    char tStage;
    char nStage;
    char thStage;
    char diferrentie;
    int grade;
    char aStage;
    int tumor;
    char estrogenStatus;
    char progesteroneStatus;
    int regionalNodeExamined;
    int reginolNodePositive;
    int survivalMonths;
    char status;
    int linha;
    struct dadosCancer *direita;
    struct dadosCancer *esquerda;

}dadosCancer;

//funçao para gerar um novo no na arvore
dadosCancer* novoNo(int age, char race, char maritalStatus,char tStage,char nStage,char thStage,char diferrentie,int grade,char aStage,int tumor,char estrogenStatus,char progesteroneStatus,int regionalNodeExamined,int reginolNodePositive,int survivalMonths,char status,int linha){ 
        dadosCancer *novo = (dadosCancer*)malloc(sizeof(dadosCancer));
        novo->age = age;
        novo->race = race;
        novo->maritalStatus = maritalStatus;
        novo->tStage = tStage;
        novo->nStage = nStage;
        novo->thStage = thStage;
        novo->diferrentie = diferrentie;
        novo->grade = grade;
        novo->aStage = aStage;
        novo->tumor = tumor;
        novo->estrogenStatus = estrogenStatus;
        novo->progesteroneStatus = progesteroneStatus;
        novo->regionalNodeExamined = regionalNodeExamined;
        novo->reginolNodePositive = reginolNodePositive;
        novo->survivalMonths = survivalMonths;
        novo->status = status;
        novo->linha = linha;
        novo->direita = NULL;
        novo->esquerda = NULL;
        return novo;
}

//funçao para inserir um no 
dadosCancer* inserirNo(dadosCancer *arvore,dadosCancer *novoNo){
     if (arvore == NULL) {
        return novoNo;
    }
    // Exemplo: Ordenar por 'age'
    if (novoNo->age < arvore->age) {
        arvore->esquerda = inserirNo(arvore->esquerda, novoNo);
    } else {
        arvore->direita = inserirNo(arvore->direita, novoNo);
    }
    return arvore;

}



//funçao para carregar o arquivo 
dadosCancer* carregarArquivo(char* nomeArquivo){
    FILE *arquivo = fopen(nomeArquivo,"r");
    if(arquivo == NULL){
        printf("erro ao abrir o arquivo\n");
        return NULL;
    }

    dadosCancer *arvore = NULL;
    int age,grade,tumor,regionalNodeExamined,reginolNodePositive,survivalMonths,linha = 0;
    char race,maritalStatus,tStage,nStage,thStage,diferrentie,aStage,estrogenStatus,progesteroneStatus,status;
    while(fscanf(arquivo,"%d %c %c %c %c %c %c %d %c %d %c %c %d %d %d %c",
                           &age,&race,&maritalStatus,&tStage,&nStage,&thStage,&diferrentie,
                           &grade,&aStage,&tumor,&estrogenStatus,&progesteroneStatus,&regionalNodeExamined,&reginolNodePositive,&survivalMonths,
                           &status)!= EOF){
        
        dadosCancer *novo = novoNo(age,race,maritalStatus,tStage,nStage,thStage,diferrentie,grade,aStage,tumor,estrogenStatus,progesteroneStatus,regionalNodeExamined,reginolNodePositive,survivalMonths,status,linha);
        arvore = inserirNo(arvore,novo);
        linha ++;

    }
    fclose(arquivo);
    return arvore;
}

void imprimirRelatorio(dadosCancer *arvore,char *nomeArquivo){
    if (arvore == NULL) {
        printf("Arquivo Vazio!!!\n");
        return;
    }
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    if (arvore->esquerda != NULL) {
        imprimirRelatorio(arvore->esquerda, nomeArquivo);
    }

    char linha[256];
    fseek(arquivo, 0, SEEK_SET); // Reset file pointer
    for (int i = 0; i <= arvore->linha; i++) {
        fgets(linha, sizeof(linha), arquivo);
    }
    printf("%s", linha);

    if (arvore->direita != NULL) {
        imprimirRelatorio(arvore->direita, nomeArquivo);
    }

    fclose(arquivo);
}

int main (){
   dadosCancer *arvore=NULL;
   int menu;
   char nomeArquivo[256];

   do{
     printf("---------------------------------\n");
     printf("1)Carregar Arquivos de dados\n");
     printf("2)Gerar relatorio\n");
     printf("3)Sair\n");
     scanf("%d",&menu);
     switch(menu){
      case 1:
        printf("Digite o nome do arquivo\n");
        scanf("%s",nomeArquivo);
        arvore = carregarArquivo(nomeArquivo);
        break;

      case 2:
         imprimirRelatorio(arvore,nomeArquivo);
         printf("\n");
         break;


     }

   }while(menu != 3);


}