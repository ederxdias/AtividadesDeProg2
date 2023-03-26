#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MARCA -1
#define PROXIMO -2
#define ACHOU 9
/*Existe uma ordem de prioridad ex: BDEC
Criar um vetor que recorde as posicoes passadas
Nao repetir o mesma posicao mais que uma vez
Criar um algoritmo que mostre qual é a proxima posicao*/
typedef struct
{
    int x;
    int y;
    int f;
} tPosicao;

void PreencherMapa(int l, int c, int mapa[l][c]);
void ImprimirMapa(int l, int c, int mapa[l][c]);
tPosicao PrencherInicio(int l, int c, int mapa[l][c], tPosicao p);
void Caminhar(int l, int c, int mapa[l][c], tPosicao p, char prio[]);
tPosicao ProximoPonto(int l, int c, int mapa[l][c], tPosicao p, char prd);
void ImprimirPosicoes(int l, int c, int mapa[l][c]);

int main()
{
    int l, c;
    scanf("%d %d", &l, &c);
    int mapa[l][c];
    srand(time(NULL)); // use current time as seed for random generator
    PreencherMapa(l, c, mapa);
    ImprimirMapa(l, c, mapa);
    tPosicao ponto;
    ponto = PrencherInicio(l, c, mapa, ponto);
    char prio[5];
    // Lembrar que os padroes de scanf tem que ser cumpridos a risca
    scanf("%s", prio);
    printf("%s\n", prio);
    Caminhar(l, c, mapa, ponto, prio);
    printf("\n#\n");
    ImprimirPosicoes(l,c,mapa);
    return 0;
}
void PreencherMapa(int l, int c, int mapa[l][c])
{
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < c; j++)
        {
            mapa[i][j] = (rand() % 2);
        }
    }
}
void ImprimirMapa(int l, int c, int mapa[l][c])
{
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("%d ", mapa[i][j]);
        }
        printf("\n");
    }
}
tPosicao PrencherInicio(int l, int c, int mapa[l][c], tPosicao p)
{
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (mapa[i][j] == 1)
            {
                p.x = i;
                p.y = j;
                goto entrar;
            }
        }
    }
entrar:
    return p;
}

void Caminhar(int l, int c, int mapa[l][c], tPosicao p, char prio[])
{
    mapa[p.x][p.y] = MARCA;
    printf("(%d,%d)",p.x,p.y);
    while (p.x < l)
    {
        for (int i = 0; prio[i]; i++)
        {
            p = ProximoPonto(l, c, mapa, p, prio[i]);
            if (p.f == PROXIMO)
            {
                continue;
            }
            else{
             
                break;
            }
        }
        if (p.f == PROXIMO)
        {
            printf("\n##Caminho Bloqueado##\n");
            break;
        }
        mapa[p.x][p.y] = MARCA;
    }
}
tPosicao ProximoPonto(int l, int c, int mapa[l][c], tPosicao p, char prd)
{
    if (prd == 'B' && mapa[p.x + 1][p.y] == 1 && p.x<l-1)
    {
            ++p.x;
            p.f = ACHOU;
            return p;
        
    }
    else if (prd == 'C' && mapa[p.x - 1][p.y] == 1 && p.x>0)
    {
            --p.x; 
             p.f = ACHOU;
            return p;
    }
    else if (prd == 'E' && mapa[p.x][p.y - 1] == 1 && p.y>0)
    {
            --p.y;
            p.f = ACHOU;
            return p;
    }
    else if (prd == 'D' && mapa[p.x][p.y + 1] ==1 && p.y <c-1)
    {
            ++p.y;  
            p.f = ACHOU;
            return p;
    }
    else 
    {
        p.f = PROXIMO;
        return p;
    }
}
void ImprimirPosicoes(int l, int c, int mapa[l][c])
{
      printf("\n");
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < c; j++)
        {   
            if( mapa[i][j]==MARCA)
                printf("(%d,%d)",i,j);
        }
    }
      printf("\n");
}