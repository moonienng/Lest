#ifndef BIB_LEST_H
#define BIB_LEST_H
#include <stdio.h>
#include <stdlib.h>

void CadastroEQ(int cod, char *codeq, EQ *TH[])
{
    EQ *novo;
    novo = (EQ *) malloc (sizeof(EQ));
    novo->cui = cod;
    novo -> INC = NULL;
    novo -> prx = NULL;
    strcpy(novo->neq,codeq);
    InsereEq(novo,TH);
}
void CadastroIC(int nud, int cud, int gra, ABB *R, EQ *TH[]) //insere arv
{
    IC *novo;
    novo = (IC *) malloc(sizeof(IC));
    novo-> cui = cud;
    novo -> grv = gra;
    novo -> nui = nud;
    novo -> esq = NULL;
    novo ->dir = NULL;
    R->raiz = InsereArv(novo,R->raiz);
    
    int pos = MetodoDivisao(cud);
    EQ *aux = BuscaEQ(TH,pos,cud);

    //Acessa a lista de incidentes do equipamento
    /*
    1. Se vazio, coloca o incidente no primeiro lugar da lista
    2. se não vazio coloca no começo (não tem que percorrer)
    */
}
#endif
