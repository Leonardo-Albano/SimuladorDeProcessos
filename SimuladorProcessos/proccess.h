typedef struct processo{
    char nome[15];
    int prioridade;
    int tempo;
} PROCESSO;


typedef struct pilha {
    PROCESSO processo;
    struct pilha * ptrProximo;
} PILHA;


int header();
PILHA * pilPush(PILHA * topoPilha, PILHA **procAtivo);
void pilImprime(PILHA * topo);
PILHA * passaCiclo(PILHA * procAtivo, PILHA ** topoPilha);
PILHA * pilhaReset(PILHA * topoPilha);