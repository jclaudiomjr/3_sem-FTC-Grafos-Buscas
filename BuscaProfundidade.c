#include <stdio.h>
#include <stdlib.h>
#include "BuscaProfundidade.h"
#define t 15

int main()
{
    int vert_inicial, vert_final, caminho[t], tam_caminho=1;
    pilha p;
    grafo g;

    inicializa_pilha(&p);

    cadastrar_grafo(&g);
    exibir_grafo(&g);

    printf("\nInforme o vertice inicial: ");
    scanf("%d", &vert_inicial);

    printf("Informe o vertice final: ");
    scanf("%d", &vert_final);

    busca_caminho(&g, &p, vert_inicial, vert_final, caminho, &tam_caminho);

    printf("\nCaminho: ");
    exibir_caminho(caminho, tam_caminho);

 getch();
 return 0;
}
