#include <stdlib.h>
#include <stdio.h>
#include "proccess.h"

int main(/*int argc, char const *argv[]*/){
    PILHA * topoPilha = NULL;
    PILHA * procAtivo = NULL;
    int sair = 0;

    printf("Seja bem vindo ao simulador de processos!\n");

    do{

        switch (header()){
        case 1:                                                 //insere o nome, prioridade, e tempo do processo 
            topoPilha = pilPush(topoPilha, &procAtivo);
            break;

        case 2:                                                 //imprime os stats de todos os processos ativos
            pilImprime(topoPilha);
            break;

        case 3:                                                 //imprime os stats do processo ativo
            pilImprime(procAtivo);
            break;
            
        case 4:                                                 //passa o ciclo de execucao
            procAtivo = passaCiclo(procAtivo, &topoPilha);
            break;

        case 5:
            topoPilha = pilhaReset(topoPilha);
            break;

        case 0:
            printf("\nObrigado por usar o simulador de processos!");
            sair = 1;
            break;
        }

    }while(sair == 0);

    free(topoPilha);
    return 0;
}
