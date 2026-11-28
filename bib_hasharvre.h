#ifndef BIB_HASHARVRE_H
#define BIB_HASHARVRE_H
#include <stdio.h>
#include <stdlib.h>
#include "bib_struc.h"

// FUNÇÕES DE ÁRVORE
ABB* IniciaArvore()
{
    ABB *R = (ABB*) malloc(sizeof(ABB));
    R->raiz = NULL;
    return R;
}

int ArvoreVazia(ABB *R)
{
    return R->raiz == NULL;
}

IC* InsereFolha(IC *R, IC *novo)
{
    if (R == NULL)
        return novo;

    if (novo->nui > R->nui)
        R->esq = InsereFolha(R->esq, novo);
    else
        R->dir = InsereFolha(R->dir, novo);

    return R;
}

// FUNÇÕES TH
int MetodoDivisao(int cod)
{
    return cod % M;
}

void InsereEq(EQ *novo, EQ *TH[])
{
    int pos = MetodoDivisao(novo->cui);
    novo->prx = TH[pos];
    TH[pos] = novo;
}

void IniciaTH(EQ *TH[])
{
    for (int i = 0; i < M; i++)
        TH[i] = NULL;
}

EQ* BuscaEQ(EQ *TH[], int cod)
{
    int pos = MetodoDivisao(cod);
    EQ *aux = TH[pos];
    while (aux != NULL) {
        if (aux->cui == cod)
            return aux;
        aux = aux->prx;
    }
    return NULL;
}

#endif