#ifndef BIB_TIPOS_H
#define BIB_TIPOS_H

#define M 43 // tamanho da tabela hash

typedef struct incequi {
    int ni;
    struct incequi *prox;
} ICEQ;

typedef struct equipamento {
    int cui;
    char neq[11];
    ICEQ *INC;
    struct equipamento *prx;
} EQ;

typedef struct incidente {
    int nui;
    int cui;
    int grv;
    struct incidente *esq;
    struct incidente *dir;
} IC;

typedef struct ABB {
    IC *raiz;
} ABB;

#endif