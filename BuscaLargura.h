#define t 15

typedef struct
{
	int memoria[t];
	int fim;
	int inicio;
}fila;

void inicializa_fila(fila *_f)
{
    _f->fim=0;
    _f->inicio=0;
}

void enfilera(fila *_f, int _elemento)
{
    if(!fila_cheia(_f))
    {
        _f->memoria[_f->fim]=_elemento;
        _f->fim++;
    }
}

void desenfilera(fila *_f)
{
    int i;

    if(!fila_vazia(_f))
    {
        for(i=0 ; i < _f->fim ; i++)
            _f->memoria[i]=_f->memoria[i+1];

        _f->fim--;
    }
}

int fila_cheia(fila *_f)
{
    if(_f->fim > t-1)
        return(1);
    else
        return(0);
}

int fila_vazia(fila *_f)
{
    if(_f->fim == _f->inicio)
        return(1);
    else
        return(0);
}

int inicio_fila(fila *_f)
{
    if(!fila_vazia(_f))
        return (_f->memoria[_f->inicio]);
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

void busca_caminho(grafo *_g, fila *_f, int _vert_inicial, int _vert_final, int *caminho, int *tam_caminho)
{
    int verti, vertj, flag;

    caminho[0] = _vert_inicial;
    enfilera(_f, _vert_inicial);


    for (verti = _vert_inicial, flag=0; flag != 1;)
        for (vertj=0 ; ; vertj++)
        {
            if (_g->mat[verti][vertj] == 1)
            {
                if(!vert_marcado(caminho, *tam_caminho, vertj))
                {
                    enfilera(_f, vertj);
                    caminho[*tam_caminho] = vertj;
                    (*tam_caminho)++;

                    if (vertj == _vert_final)
                    {
                        flag = 1;
                        break;
                    }
                }
            }

            if (vertj == _g->tamanho-1)
            {
                desenfilera(_f);
                verti = inicio_fila(_f);
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
