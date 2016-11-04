#include <stdio.h>
#include <stdlib.h>
#include "BuscaLargura.h"
#define t 15

int main()
{
    int vert_inicial, vert_final, caminho[t], tam_caminho=1;
    fila f;
    grafo g;

    inicializa_fila(&f);

    cadastrar_grafo(&g);
    exibir_grafo(&g);

    printf("\nInforme o vertice inicial: ");
    scanf("%d", &vert_inicial);

    printf("Informe o vertice final: ");
    scanf("%d", &vert_final);

    busca_caminho(&g, &f, vert_inicial, vert_final, caminho, &tam_caminho);

    printf("\nCaminho: ");
    exibir_caminho(caminho, tam_caminho);

 getch();
 return 0;
}

