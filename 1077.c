/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : <<<Fabrício Ribeiro Uchida>>>
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1077
Data        : 25/09/2026
Objetivo    : Traansformar notacao infixa em posfixa
Dificuldade : Resolver o erro "runtime error: command dumped core"
Uso de IA   : Usado para encontar o bug (tinha alterado a ordem de checar se havia uma celula quando fizeesse pop).
-------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> //usado para isalphanumeric

#define N 1000


typedef struct No{//pilha com cabeca
    char info;
    struct No *prox;
}No;

void push(No **topo, char info){//empilha
    No *novo = (No*)malloc(sizeof(No));
    novo->info = info;
    novo->prox = *topo;
    *topo = novo;
}

void pop(No **topo){//desempilha
    No *aux;
    char valor;
    aux = *topo;
    if (aux == NULL) {
        return;
    }
    valor = aux->info;
    *topo = aux->prox;
    free(aux);
}

char verTopo(No *topo){//so para ver o que atualmente esta no topo da pilha para colocar no vet resultado
    return topo->info;
}

int prioridade(char c){
    if (c == '+' || c == '-'){
        return 1;
    }
    else if (c == '*' || c == '/'){
        return 2;
    }
    else if (c == '^'){
        return 3;
    }
    return 0;
}


int main(){
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        char expressao[N];
        scanf("%s", expressao);

        No *topo = NULL; //inicializa a pilha
        char resultado[N];
        int j = 0;

        for(int k = 0; expressao[k] != '\0'; k++){
            char c = expressao[k];

            if(isalnum(c)){
                resultado[j++] = c;
            }else if(c == '('){
                push(&topo, c);
            }else if(c == ')'){
                while(topo != NULL && verTopo(topo) != '('){ //enquanto o topo no fechar os parenteses e nao abrir
                    resultado[j++] = verTopo(topo);
                    pop(&topo);
                }
                pop(&topo); //remove o '(' da pilha  
            }else{
                while(topo != NULL && prioridade(verTopo(topo)) >= prioridade(c)){
                    resultado[j++] = verTopo(topo);
                    pop(&topo);
                }
                push(&topo, c);
            }
        }

        while(topo != NULL){
            resultado[j++] = verTopo(topo);
            pop(&topo);
        }

        resultado[j] = '\0';
        printf("%s\n", resultado);
    }

    
    
}