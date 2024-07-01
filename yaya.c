#include <stdio.h>

int main()
{


    int n;
    scanf("%d", &n);

    int matriz[n][n];

    // transformar minha matriz comum em matriz ATETRIS

    int i, j;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &matriz[i][j]);
        }
    }


    for (i = 0; i < n; i++)
    {
        int todos_um = 1; // todos os elementos sao 1 (true)

        for (j = 0; j < n; j++)
        {
            if (matriz[i][j] != 1) // se acharmos algum elemento da linha que nao eh 1, todos_uns = 0; (false)
            {
                todos_um = 0;
                break;
            }
        }


        if (todos_um)
        {
            for (j = 0; j < n; j++)
            {
                matriz[i][j] = 0;
            }
        }

        // vamos verificar a proxima linha ao final desse loop.
    }

    

    printf("\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d ",matriz[i][j]);
        }
        printf("\n");
    }


    for (j = 0; j < n; j++)
    {
        int posicao_mais_baixa = n - 1;

        for (i = n - 1; i >= 0; i--)
        {
            if (matriz[i][j] == 1)
            {
                matriz[posicao_mais_baixa--][j] = 1;
            }
        }

        for (i = 0; i <= posicao_mais_baixa; i++)
        {
            matriz[i][j] = 0;
        }
    }

    printf("\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d ", matriz[i][j]);
        }

        printf("\n");
    }

    for (i = 0; i < n; i++)
    {
        int todos_um = 1;
        for (j = 0; j < n; j++)
        {
            if (matriz[i][j] != 1)
            {
                todos_um = 0;
                break;
            }

            if (todos_um)
            {
                for (j = 0; j < n; j++)
                {

                    matriz[i][j] = 0;
                }
            }
        }
    }

    printf("\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d ", matriz[i][j]);
        }

        printf("\n");
    }

    return 0;
}