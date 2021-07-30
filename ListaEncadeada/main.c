#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "itemhistorico.h"

typedef struct {
    itemhistorico item;
    struct No *proximo;
}No;

No * criarNo(itemhistorico item);
No * inserirListaFinal(No *inicio, No *fim, No *novono);
No * inserirListaInicio(No *inicio, No *fim, No *novono);
void imprimirLista(No* inicio);
void localizarnaLista(No* inicio, char enderecoBusca[50]);
int listaVazia(No *inicio);

int main()
{
    char op;
    char enderecoBuscado[50];
    int i=0;
    itemhistorico item;
    No *inicio = NULL;
    No *fim = NULL;
    No *novo;


    do{
        system("cls");
        printf("Escolha uma opção:\n");
        printf("1 - INSERIR || 2 - LISTAR || 3 - CONSULTAR || 4 - SAIR\n");
        op = getchar();
        switch(op){
            case '1':
                printf("Site visitado:\n");
                scanf("%s",item.endereco);
                novo = criarNo(item);
                if (listaVazia(inicio)){
                    fim = inserirListaFinal(inicio, fim, novo);
                    inicio = fim;
                }
                else {
                    fim = inserirListaFinal(inicio, fim, novo);
                }
                break;
            case '2':
                imprimirLista(inicio);
                system("pause");
                break;
            case '3':
                printf("Informe o site a ser consultado:\n");
                scanf("%s",enderecoBuscado);
                localizarnaLista(inicio, enderecoBuscado);
                system("pause");
                break;
            case '4':
                printf("saindo....");
        }
    }while(op != '4');

    return 0;
}


No * criarNo(itemhistorico item){
    No *novoNo = (No *)malloc(sizeof(No));
    if (novoNo == NULL){
        printf("Não foi possível alocar memória\n");
        return NULL;
    }
    else{
        novoNo->item = item;
        novoNo->proximo = NULL;
        return novoNo;
    }
}

No * inserirListaFinal(No *inicio, No *fim, No *novono){
    if (fim == NULL){
        fim = novono;
    }
    else{
        fim->proximo = novono;
        fim = novono;
    }
    return fim;
}

No * inserirListaInicio(No *inicio, No *fim, No *novono){
    if (inicio == NULL){
        inicio = novono;
        fim = novono;
    }
    else{
        novono->proximo = inicio;
        inicio = novono;
    }
    return inicio;
}

void imprimirLista(No* inicio){
    No *percorrer;
    percorrer = inicio;
    while(percorrer != NULL){
        printf("Site Visitado: %s\n",percorrer->item.endereco);
        percorrer = percorrer->proximo;
    }
}

void localizarnaLista(No* inicio, char enderecoBusca[50]){
    No *percorrer;
    int resultadoComparacao = 1;

    percorrer = inicio;
    while(percorrer != NULL){
        resultadoComparacao = strncmp(enderecoBusca,percorrer->item.endereco,50);
        if(resultadoComparacao == 0){
            printf("Endereco |%s| localizado com sucesso.\n",enderecoBusca);
            break;
        }
        percorrer = percorrer->proximo;
    }
    if (resultadoComparacao != 0){
        printf("Endereco |%s| NAO localizado no Historico.\n",enderecoBusca);
    }
}

int listaVazia(No *inicio){
    if (inicio == NULL){
        return 1;
    }
    else{
        return 0;
    }
}
