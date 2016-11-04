#define t 15

typedef struct
{
    int memoria[t];
    int topo;
}pilha;


void inicializa_pilha(pilha *_p)
{
    _p->topo=0;
}


void empilhar(pilha *_p, int _elemento)
{
    if (!pilha_cheia(_p))
    {
        _p->memoria[_p->topo]=_elemento;
        _p->topo++;
    }
}


void desempilhar(pilha *_p)
{
    if (!pilha_vazia(_p))
        _p->topo--;
}


int topo_pilha(pilha *_p)
{
    if (!pilha_vazia(_p))
    return(_p->memoria[_p->topo-1]);
}


int pilha_cheia(pilha *_p)
{
    if(_p->topo > t-1)
        return(1);
    else
        return(0);
}


int pilha_vazia(pilha *_p)
{
    if(_p->topo == 0)
        return(1);
    else
        return(0);
}

typedef struct
{
    int mat[t][t];
    int tamanho;
}grafo;

void cadastrar_grafo(grafo *_g)
{
    int i, j, adjacente;

    printf("Informe a quantidade de vertices: ");
    scanf("%d", &_g->tamanho);

    inicializar_grafo(_g);

    for (i=0; i < _g->tamanho ; i++)
        for (j=0; j < _g->tamanho ; j++)
            if(i != j)
            {
                 printf("\nATENCAO: (1)SIM  (0)NAO\n%d eh adjacente a %d? ", i, j);
                 scanf("%d", &adjacente);
                 _g->mat[i][j]=adjacente;
            }
}

void inicializar_grafo(grafo *_g)
{
    int i, j;

    for (i=0; i < _g->tamanho ; i++)
        for (j=0; j < _g->tamanho ; j++)
            _g->mat[i][j] = 0;
}

void exibir_grafo(grafo *_g)
{
    int i, j;

    for (i=0; i < _g->tamanho ; i++)
    {
        printf("\n");
        for (j=0; j < _g->tamanho; j++)
            printf("%d ", _g->mat[i][j]);
        printf("\n");
    }
}

void busca_caminho(grafo *_g, pilha *_p, int _vert_inicial, int _vert_final, int *caminho, int *tam_caminho)
{
    int verti, vertj, flag;

    caminho[0] = _vert_inicial;
    empilhar(_p, _vert_inicial);


    for (verti = _vert_inicial, flag=0; flag != 1;)
        for (vertj=0 ; ; vertj++)
        {
            if (_g->mat[verti][vertj] == 1)
            {
                if(!vert_marcado(caminho, *tam_caminho, vertj))
                {
                    empilhar(_p, vertj);
                    caminho[*tam_caminho] = vertj;
                    (*tam_caminho)++;
                    verti = vertj;
                    vertj = 0;

                    if (verti == _vert_final)
                    {
                        flag = 1;
                        break;
                    }
                }
            }
            else if (vertj == _g->tamanho)
            {
                desempilhar(_p);
                verti = topo_pilha(_p);
                vertj = 0;
            }
        }


}

int vert_marcado(int *_caminho, int _tam_caminho, int _vertj)
{
    int i;

    for (i=0 ; i < _tam_caminho ; i++)
        if (_caminho[i] == _vertj)
            return (1);

    return (0);
}

void exibir_caminho(int *_caminho, int _tam_caminho)
{
    int i;

    for (i=0 ; i < _tam_caminho ; i++)
        printf("%d ", _caminho[i]);

    printf("\n");
}
