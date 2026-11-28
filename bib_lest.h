#ifndef BIB_LEST_H
#define BIB_LEST_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bib_struc.h"
#include "bib_hasharvre.h"

void CadastroEQ(int cod, char *codeq, EQ *TH[])
{
    EQ *novo = (EQ *) malloc(sizeof(EQ));
    novo->cui = cod;
    novo->INC = NULL;
    novo->prx = NULL;
    strcpy(novo->neq, codeq);
    InsereEq(novo, TH);
}

void CadastroIC(int nud, int cud, int gra, ABB *R, EQ *TH[])
{
    IC *novo = (IC *) malloc(sizeof(IC));
    novo->cui = cud;
    novo->grv = gra;
    novo->nui = nud;
    novo->esq = NULL;
    novo->dir = NULL;

    // ordem corrigida: raiz primeiro, depois o nó novo
    R->raiz = InsereFolha(R->raiz, novo);

    int pos = MetodoDivisao(cud);
    EQ *aux = BuscaEQ(TH, pos, cud);
    if (aux == NULL) {
        printf("\nEquipamento %d não cadastrado.\n", cud);
        free(novo);
        return;
    }

    ICEQ *aux2 = (ICEQ *) malloc(sizeof(ICEQ));
    aux2->ni = nud;
    aux2->prox = aux->INC;
    aux->INC = aux2;
}

void ConsultaEQ(EQ *TH[], int cod)
{
    int pos = MetodoDivisao(cod);
    EQ *aux = BuscaEQ(TH, pos, cod);
    if (aux == NULL) {
        printf("\nEquipamento não encontrado.\n");
        return;
    }
    printf("\n%d", aux->cui);
    puts(aux->neq);

    int q = 0;
    for (ICEQ *aux2 = aux->INC; aux2 != NULL; aux2 = aux2->prox)
        q++;
    printf("\nForam encontrados %d incidentes relacionados.", q);
}

#endif