#ifndef BIB_LEST_H
#define BIB_LEST_H
#include <stdio.h>
#include <stdlib.h>

void CadastroEQ(int cod, char *codeq, EQ *TH[])
{
    EQ *novo;
    novo = (EQ *) malloc (sizeof(EQ));
    novo->cui = cod;
    novo -> prx = NULL;
    strcpy(novo->neq,codeq);
    InsereEq(novo,TH);
}
void CadastroIC(int nud, int cud, int gra) //insere arv
{
    IC *novo;
    novo = (IC *) malloc(sizeof(IC));
    novo-> cui = cud;
    novo -> grv = gra;
    novo -> nui = nud;
    novo -> esq = NULL;
    novo ->dir = NULL;
    //InsereArv(novo,arv);
}
#endif
