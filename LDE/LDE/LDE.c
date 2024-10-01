#include <stdio.h>
#include <stdlib.h>
#include "LDE/LDEStructs/LDE.h"

void inicializar(LDE* l){
    l->inicio = NULL;
    l->fim = NULL;
    l->qtd = 0;
}

int isEmpty(LDE l){
    return l.qtd == 0;
}

void inserirInicio(LDE* l, int valor){
    LDENode* novo;
    novo = (LDENode *) malloc(sizeof(LDENode));
    novo->info = valor;
    novo->prox = NULL;
    novo->ant = NULL;
    
    if(isEmpty(*l)){
        l->inicio = novo;
        l->fim = novo;
    } else {
        novo->prox = l->inicio;
        l->inicio->ant = novo;
        l->inicio = novo;
    }
    l->qtd++;
}

void deTrasPraFrente(LDE l){
    
    LDENode* aux;
    
    if(isEmpty(l)){
        printf("Lista vazia");
    } else {
        for(aux = l.fim; aux != NULL; aux = aux->ant){
            printf("%d", aux->info);
        }
    }
}

int buscar(LDE l, int valor){
    LDENode* aux;
    if(isEmpty(l)){
        return 1;
    }
    for(aux = l.inicio; aux != NULL; aux = aux->prox){
        if(valor == aux->info){
            return 0;
        }
    }
    return 1;
}

void removerUltimo(LDE* l){
    LDENode* aux;
    aux = l->fim;

    if(isEmpty(*l)){
        printf("A lista está vazia.");
    } else{
        aux = l->fim;
        if(l->qtd == 1){
            l->fim = NULL;
            l->inicio = NULL;
        } else{
            l->fim = l->fim->ant;
            l->fim->prox = NULL;
        }
        free(aux);
    }
    l->qtd--; 
}
