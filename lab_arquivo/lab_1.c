#include <stdio.h>
#include <string.h>

int namefilepointposition(char *fullname) {
    int i;
    for (i = 0; i < strlen(fullname); i++) {
        if (fullname[i] == '.')
            break;
    }
    if (i >= strlen(fullname))
        return -1;
    else
        return i;
}

int contaLetra(char *palavra) {
    int i = 0;
    while (palavra[i] != '\0') {
        i++;
    }
    return i;
}

int eCaracterEspecial(char letra) {
    char allowedChars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789 ";

    return strchr(allowedChars, letra) != NULL;
}

void removerCaracterEspecial(char *palavra) {
    int tamanho = strlen(palavra);
    int i, j = 0;

    for (i = 0; i < tamanho; i++) {
        if (eCaracterEspecial(palavra[i])) {
            palavra[j] = palavra[i];
            j++;
        }
    }

    palavra[j] = '\0';
}

int verificarPalavraRepetida(char palavrasUnicas[][100], char *palavra) {
    for (int i = 0; i < 1000; i++) {
        if (strcmp(palavrasUnicas[i], palavra) == 0) {
            return 1; // A palavra já existe no array de palavras únicas
        }
    }
    return 0; // A palavra é única
}

int word2vec(char *pNomeTxtEntrada) {
    FILE *arqent, *arqsaida;
    char nomarq[40];
    int pointidx = namefilepointposition(pNomeTxtEntrada);
    int pp;

    // Gerando o nome do arquivo de saída
    if (pointidx >= 0) {
        for (pp = 0; pp < pointidx; pp++)
            nomarq[pp] = pNomeTxtEntrada[pp];
        nomarq[pp] = '\0'; // Fim da string
    } else
        strcpy(nomarq, pNomeTxtEntrada);

    strcat(nomarq, "_Vocabulo");
    strcat(nomarq, ".txt");
    printf("\nRecebi o nome do arquivo: %s", nomarq);

    // Abrindo o arquivo de entrada e saída
    arqent = fopen(pNomeTxtEntrada, "r");
    arqsaida = fopen(nomarq, "w+");

    if (arqent == NULL || arqsaida == NULL) {
        printf("\nErro na abertura do arquivo!");
        return 0;
    } else {
        char palavra[100];

        while (fscanf(arqent, "%s", palavra) != EOF) {
            removerCaracterEspecial(palavra);

            if (contaLetra(palavra) > 3) {
                fprintf(arqsaida, "%s\n", palavra);
            }
        }

        fclose(arqent);
        fclose(arqsaida);

        // Verificando palavras repetidas
        FILE *novoArqSaida;
        char palavrasUnicas[1000][100];
        int numPalavrasUnicas = 0;

        novoArqSaida = fopen(nomarq, "r");
        if (novoArqSaida == NULL) {
            printf("\nErro na abertura do arquivo de saída!");
            return 0;
        }

        while (fscanf(novoArqSaida, "%s", palavra) != EOF) {
            // Verificar palavras repetidas
            if (!verificarPalavraRepetida(palavrasUnicas, palavra)) {
                strcpy(palavrasUnicas[numPalavrasUnicas], palavra);
                numPalavrasUnicas++;
            }
        }

        fclose(novoArqSaida);

        // Reabrir o arquivo de saída para escrita
        novoArqSaida = fopen(nomarq, "w");
        if (novoArqSaida == NULL) {
            printf("\nErro na reabertura do arquivo de saída!");
            return 0;
        }

        // Escrever as palavras únicas no arquivo de saída
        for (int i = 0; i < numPalavrasUnicas; i++) {
            fprintf(novoArqSaida, "%s\n", palavrasUnicas[i]);
        }

        fclose(novoArqSaida);

        return 1;
    }
}


int main() {
    char nomearq[30];
    printf("Entre com o nome do arquivo: ");
    scanf("%s", nomearq);
    if (!word2vec(nomearq))
        printf("\nErro na geração do vocabulário!");
    else
        printf("\nGerei o vocabulário!");

    return 0;
}