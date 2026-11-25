#ifndef BIB_HASH_H
#define BIB_HASH_H
#include <stdio.h>
#include <stdlib.h>

#define M 43 // tamanho da tabela hash

typedef struct equipamento
{
    int cui;
    char neq[11];
    REL *INC;
    struct equipamento *prx;
} EQ;

typedef struct incidente
{
    int nui;
    int cui;
    int grv;
    struct incidente *esq;
    struct incidente *dir;
}IC;

typedef struct ABB
{
    IC *raiz;
}ABB;
typedef struct relacao
{
    ICEQ *inicio;
}REL;
typedef struct incequi
{
    int ni;
    struct incequi *prox;
}ICEQ;

/*
    Será necessário:
        1. Funções de Arvore
        2. Funções de Lista
        3. Funções de Tabela Hash
*/
// FUNÇÕES DE ÁRVORE
//arv IniciaArvore():
    ABB* IniciaArvore()
    {
        ABB *R = (ABB*) malloc(sizeof(ABB));
        R->raiz=NULL;
        return R;
    }
 
// int ArvoreVazia(arv raiz): Verifica se a arvore tá vazia
int ArvoreVazia (ABB* R)
{
    if (R->raiz==NULL) return 1;
    return 0;

}
//TODO: BuscaDireta(): Recebe número de identificação e retorna o endereço correspondente ou null 
//TODO: ImprimeFolha(): Recebe um endereço e imprime as informações daquela folha
//TODO: InsereFolha(): Recebe um endereço e insere na árvore. Inserção do maior na esquerda
    IC* InsereFolha(IC *R, IC *novo)
    {
        if(R == NULL) //arvore vazia
        {
            return novo;
        }
        else //arvore com gente
        {
            if(novo->nui > R->nui)
            {
                R->esq = InsereFolha(R->esq, novo);
            }
            else
            {
                R->dir = InsereFolha(R->dir, novo);
            }
            return R;
        }
    }
//TODO: RemoveFolha(): Recebe o número de identificação, chama a Busca direta e remove um incidente da arvore. Considere os 3 casos. A regra é o maior número da subarvore da esquerda
//TODO: ImprimeArvore(): Recebe raiz da árvore, percorre (In Order) imprimindo 

// FUNÇÕES DE LISTA


//FUNÇÕES TH
int MetodoDivisao(int cod)
{
    int i;
    i = cod%M;
    return i;
}
void InsereEq(EQ *novo, EQ *TH[])
{
    int pos = MetodoDivisao(novo->cui);
    EQ *ant = NULL;
    if(TH[pos] == NULL)
    {
        TH[pos] = novo;
    }
    else
    {
        EQ *aux = TH[pos];
        while(aux!=NULL)
        {
            ant = aux;
            aux = aux->prx;
        }
        ant->prx = novo;
    }
}
void IniciaTH(EQ *TH[])
{
    for(int i=0; i<M; i++)
    {
        TH[i] = NULL;
    }
}

EQ* BuscaEQ(EQ *TH[], int pos, int cod)
{
    EQ *aux = TH[pos];
    while(aux !=NULL)
    {
        if(aux->cui == cod)
        {
            return aux;
        }
        aux = aux->prx;
    } 
    return aux;
}







#endif
