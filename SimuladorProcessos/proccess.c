#include <stdlib.h>
#include <stdio.h>
#include "proccess.h"

int header(){
    int escolha;

    printf("\nQual funcao deseja utilizar:\n1 - Adicionar um novo processo\n2 - Visualizar a pilha atual\n3 - Visualizar o processo atual em execucao\n4 - Passar o ciclo de execucao\n5 - Resetar pilha\n0 - Sair\n");

    scanf("%d", &escolha);
    return escolha;

}

PILHA * pilPush(PILHA *topoPilha, PILHA **procAtivo){
    PILHA * novo = (PILHA *)malloc(sizeof(PILHA));
    PILHA * ativo = *procAtivo;

    printf("\nDigite o nome do processo: ");
    scanf("%s", &novo->processo.nome);
    
    do{                                                                         //caso o usuário digite um numero >5 <1 pede novamente
        printf("\nDigite a prioridade do processo (1-5): ");            
        scanf("%d", &novo->processo.prioridade);
    }while(novo->processo.prioridade<1 || novo->processo.prioridade>5);                 

    do{                                                                         //caso o usuário digite um numero >5 <1 pede novamente
        printf("\nDigite o tempo do processo (1-10): ");
        scanf("%d", &novo->processo.tempo);
    }while(novo->processo.tempo<1 || novo->processo.tempo>10);

    
    if(*procAtivo == NULL){                                                     //caso procedimento ativo não possuir nada, joga o processo pro ativo

        novo->ptrProximo = *procAtivo;   
        *procAtivo = novo;

        return topoPilha;
    }

    if (novo->processo.prioridade > ativo->processo.prioridade){                //prioriza o procedimento com mais prioridade

        novo->ptrProximo=NULL;
        ativo->ptrProximo=topoPilha;
        topoPilha = ativo;                                                      //passa o valor que estava no procAtivo para o topo da pilha
        *procAtivo = novo;
    
        return topoPilha;
    }
    
    novo->ptrProximo = topoPilha;                                               //caso nenhuma das outras opcoes se aplique, joga pro topo da pilha
    return novo;
}

void pilImprime(PILHA * topo){
    PILHA * nodo = topo;

    if(nodo == NULL){
        printf("\n--------Pilha vazia--------\n");
        return;
    }

    printf("\n--------Topo--------\n");
    while (nodo != NULL){
        printf("\nNome do processo: %s\nPrioridade do processo: %d\nTempo do processo: %d\n", nodo->processo.nome, nodo->processo.prioridade, nodo->processo.tempo);

        nodo = nodo->ptrProximo;
    }
    printf("\n--------Base--------\n");
}

PILHA * passaCiclo(PILHA * procAtivo, PILHA ** topoPilha){

    PILHA * ativo = procAtivo;
    PILHA * topo = *topoPilha;

    ativo->processo.tempo--;

    if (ativo->processo.tempo == 0){
        printf("Processo '%s' finalizado.\n", &ativo->processo.nome);

        if(topo!=NULL){
            ativo = topo;                                                       //passa o valor que estava topo da pilha para o procAtivo
            *topoPilha=topo->ptrProximo;
        
            if(ativo!=NULL){
                printf("Colocando '%s' para rodar!\n", &ativo->processo.nome);
            }

        }else{
            printf("Sem mais processos para rodar!\n");
            return NULL;                                                        //retorna nulo caso para o procAtivo caso nao tenha mais processos
        }
    }

    printf("\n|");
    for (int i = ativo->processo.tempo; i != 0; i--){                           //tela de loading
        printf("=");
    }
    printf("|\n");

    return ativo;
}

PILHA * pilhaReset(PILHA * topoPilha){
    PILHA * nodo = topoPilha;
    while (nodo != NULL){
        free(nodo);                                         //libera o espaço dos nodos
        nodo=nodo->ptrProximo;
    }
    
    return nodo;
}