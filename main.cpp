#include <stdio.h>
#include <stdlib.h>

//FILA
typedef struct No{
    int dado;
    No *proximo;

}No;

typedef struct Fila{
    No *inicio;
    No *final;
}Fila;

Fila * criarFila();

Fila * criarFila(){
    Fila *fila = new Fila();
    if(fila!=nullptr){
        fila->inicio = nullptr;
        fila->final = nullptr;
        return  fila;
    }
    else{
        printf("Erro na criacao da fila");
        return  nullptr;
    }
}

void deletarFila(Fila *fila){
     No *aux;

     while(fila->inicio!=nullptr){
         aux = fila->inicio;
         fila->inicio = fila->inicio->proximo;
         delete(aux);
     }
     delete(fila);
}

int tamanhoFila(Fila *fila){
    if(fila!=nullptr){
        int cont = 0;
        No *aux;
        for(aux = fila->inicio; aux!= nullptr; aux = aux->proximo){
             cont++;
        }
        return cont;
    }else{
        return 0;
    }
}

int filaCheia(Fila *fila){
    return 0; // como estamos alocando dinamicamente, a fila nunca estará cheia, pois sempre poderá caber mais itens nela
}

int filaVazia(Fila *fila){
    if(fila == nullptr || fila->inicio == nullptr){
        return 1; // fila vazia
    }
    else{
        return 0; //fila cheia
    }
}


int inserirFila(Fila *fila, int dado){
    if(fila == nullptr){
        printf("Lista nao existente");
        return 0;
    }
    No *novo = new No();
    if(novo == nullptr){
        return 0;
    }
    novo->dado = dado;
    novo->proximo = nullptr;
    if(fila->final == nullptr){
        fila->inicio = novo;
        fila->final = novo;
    }
    else{
        fila->final->proximo = novo;
        fila->final = novo;
        return 1;
    }


}

void imprimir(Fila *fila){
    printf("\n");
    if(fila->inicio!=nullptr){
        No *aux;

        for(aux = fila->inicio; aux!=nullptr; aux = aux->proximo){
            printf("Num end: %p || Dado: %d \n",aux,aux->dado);
        }
    }
    else{
        printf("Pilha nao encontrada");
    }
}

int removerFilaInicio(Fila *fila){
    No *aux;

     if(fila == nullptr || fila->inicio == nullptr){
         return 0;
     }
     aux = fila->inicio;
     fila->inicio = fila->inicio->proximo;
     if(fila->inicio == nullptr){
         fila->final = nullptr;
         delete(fila->inicio);
         delete(fila->final);
     }
     delete(aux);
     return 1;

}



int main() {

    Fila *fila;

    fila = criarFila();
    for(int i = 0; i<5; i++){
        inserirFila(fila,i);
    }
    imprimir(fila);
    removerFilaInicio(fila);
    imprimir(fila);

    return 0;
}
