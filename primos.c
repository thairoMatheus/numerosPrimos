#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef unsigned long long u64;

struct node_s {
    u64 valor;
    struct node_s *next;
};

typedef struct node_s node;

int verificaPrimo_nr(node *head, node *tail, u64 v){
    u64 raiz = sqrt(v) + 1;
    node *ptr = head;
    node *aux;
    while(ptr != NULL){
        aux = ptr;
        if(v % (ptr->valor) == 0){
            return 0;
        }

        if(raiz < (ptr->valor)){
            break;
        }
        ptr = (ptr -> next);

    }

    ptr = (node *) malloc(sizeof(node)*1);
    if (ptr == NULL){
        return -1;
    }

    (ptr -> valor) = v;
    (ptr -> next) = NULL;
    (tail -> next) = ptr;

    return 1;
}

int verificaPrimo(node *n, u64 v){
    if (v % (n -> valor) == 0) {
        return 0;
    } else if((n -> next == NULL)){
        node *aux = (node *) malloc(sizeof(node)*1);
        if(aux == NULL){
            return -1;
        }

        (n -> next) = aux;
        (aux -> valor) = v;
        (aux ->next) = NULL;

        return 1;
    } else {
        return verificaPrimo((n->next),v);
    }
}

void imprimeLista_nr(node *p){
    while(p != NULL){
        printf("%llu ", (p->valor));
        p = (p->next);
    }
    return;
}

node *inicializaLista(){
    node *ptr = (node *) malloc(sizeof(node)*1);
    if(ptr == NULL){
        printf("Alocacao de memoria falhou.");
        return NULL;
    }
    (ptr -> valor) = 2;
    (ptr -> next)  = NULL;

    return ptr;
}

void imprimeLista(node *p){
    if(p == NULL){
        return;
    } else {
        printf("%llu ",(p -> valor));
        imprimeLista((p->next));
    }
    return;
}

void freeLista_nr(node *p){
    node *aux;
    while(p != NULL){
        aux = p;
        p = (p -> next);
        free(aux);
    }
}

void freeLista(node *p){
    if(p == NULL){
        return;
    }
    node *aux = (p -> next);
    //printf("%llu ", (p ->valor));
    free(p);
    freeLista(aux);
    return;
}

void imprimeNPrimos(u64 N, node *ptr){
    u64 i = 1, p = 3;
    node *tail = ptr;

    while (i<N){
        int r = verificaPrimo_nr(ptr, tail, p);
        if(r == -1){
            break;
        }
        if(r == 1){
            tail = (tail -> next);
            i++;
        }
        p+=2;
    }

    imprimeLista_nr(ptr);
}

u64 encontraPrimo(u64 N, node *ptr){
    u64 i = 1, p = 3;
    node *tail = ptr;

    while (i<N){
        int r = verificaPrimo_nr(ptr, tail, p);
        if(r == -1){
            break;
        }
        if(r == 1){
            tail = (tail -> next);
            i++;
        }
        p+=2;
    }

    return tail -> valor;
}

int main(){
    u64 N = 100; 

    node *ptr = inicializaLista();
    if(ptr == NULL){
        return -1;
    }
    node *tail = ptr;

    printf("Digite quantos numeros primos deseja encontrar:\n");
    scanf("%llu", &N);
    /*
    imprimeNPrimos(N,ptr);
    freeLista_nr(ptr);

    ptr = inicializaLista();
    if(ptr == NULL){
        return -1;
    }
    tail = ptr;
    */
    printf("\n%llu\n",encontraPrimo(N,ptr));
    freeLista_nr(ptr);

    return 0;
}