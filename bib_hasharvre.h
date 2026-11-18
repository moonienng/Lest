#ifndef BIB_HASH_H
#define BIB_HASH_H

typedef struct equipamento{
    int cui;
    char neq[11] ;
    struct equipamento *prx;
}EQ;

typedef struct lista
{
    EQ *inicio;
}

typedef struct incidente{
    int nui;
    int cui;
    int grv;
    struct incidente *esq;
    struct incidente *dir;
}IC;

typedef struct ABB{
    IC *raiz;
}

//TODO: arv IniciaArvore(): 
//TODO: int ArvoreVazia(arv Pai): Verifica se a arvore tá vazia
//TODO: BuscaDireta(): 
//TODO: InsereFolha(): Cria um novo incidente e coloca na posição certa na arvore. Inserção do maior na esquerda
//TODO: RemoveFolha(): Remove um incidente da arvore. Considere os 3 casos. A regra é o maior número da subarvore da esquerda
//TODO: CorreArvore(): Percorre a arvore inteira














#endif
