#include <stdio.h>
int main()
{
    int tamanho = 0;
    scanf("%d", &tamanho);

    int matriz_atetris[tamanho][tamanho];

//loop para ler a matriz atetris
    for (int i = 0; i < tamanho; i++)
    {
        for (int c = 0; c < tamanho; c++)
        {
            scanf("%d", &matriz_atetris[i][c]);
        }
    }

    int LinhaComUm;

    do
    {
    //  (1) identificar linha que contém apenas 1's e substitui-los por 0's
        int i = 0;
        for (i = 0; i < tamanho; i++)
        {
            int soh_um = 1;

            for (int c = 0; c < tamanho; c++)
            {
                if (matriz_atetris[i][c] != 1)
                {
                    LinhaComUm = 0;
                    soh_um = 0;
                    break;
                }
            }

            if (soh_um == 1)
            {
                LinhaComUm = 1;
                for (int c = 0; c < tamanho; c++)
                {
                    matriz_atetris[i][c] = 0;
                }
            }
        }

    //  (2) imprimir matriz resultante de (1)
        for (int i = 0; i < tamanho; i++)
        {
            for (int c = 0; c < tamanho; c++)
            {
                printf("%d ", matriz_atetris[i][c]);
            }

            printf("\n");   
        }

        printf("\n");

    //  (3) eliminar linhas que contém apenas 0's
        for (int c = 0; c < tamanho; c++) //percorre as colunas da matriz
        {
            for (int i = tamanho - 1; i >= 0; i--) //da linha mais abaixo até a mais acima
            {
                if (matriz_atetris[i][c] == 0) //qnd encontrar um 0 na posição i
                {
                    for (int j = i - 1; j >= 0; j--) //verifica acima dessa posição ('j')
                    {
                        if (matriz_atetris[j][c] == 1) //se encontrar, troca o 0 da posição i com o 1 da posição j
                        {
                            matriz_atetris[i][c] = 1;
                            matriz_atetris[j][c] = 0;
                            break;
                        }
                    }
                }
            }
        }

    //  (4) imprimir matriz resultante de (3)
        for (int i = 0; i < tamanho; i++)
        {
            for (int c = 0; c < tamanho; c++)
            {
                printf("%d ", matriz_atetris[i][c]);
            }

            printf("\n");   
        }

        printf("\n");

    //  (5) se a matriz possui linhas com apenas 1’s, volta ao passo 1
        for (i = 0; i < tamanho; i++)
        {
            int soh_um = 1;

            for (int c = 0; c < tamanho; c++)
            {
                if (matriz_atetris[i][c] != 1)
                {
                    LinhaComUm = 0;
                    soh_um = 0;
                    break;
                }
            }

            if (soh_um == 1)
            {
                LinhaComUm = 1;
                for (int c = 0; c < tamanho; c++)
                {
                    matriz_atetris[i][c] = 0;
                }
            }
        }
        
    } while (LinhaComUm == 1);
    
    return 0;
}