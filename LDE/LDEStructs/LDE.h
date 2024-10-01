#include <stdio.h>
#include <stdlib.h>

typedef struct LDENode {
    struct LDENode* ant;
    int info;
    struct LDENode* prox;
} LDENode;

typedef struct lde {
    LDENode* inicio;
    LDENode* fim;
    int qtd;
} LDE;