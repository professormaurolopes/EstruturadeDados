#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "itemhistorico.h"
#define TAM_MAX 5

itemhistorico itens[TAM_MAX];
void adicionarItemHistorico(int *ptr_indice);
void listarItensdoHistorico(int indice);
void consultarItensdoHistorico(char enderecoBuscado[50], int indice);

int main(void) {
  char op, char enderecoBuscado[50];
  int i=0;

  do{
    system("cls");
    printf("Escolha uma opção:\n");
    printf("1 - INSERIR || 2 - LISTAR || 3 - CONSULTAR || 4 - SAIR\n");
    op = getchar();
    switch(op){
      case '1':
        adicionarItemHistorico(&i);
        break;
      case '2':
        listarItensdoHistorico(i);
        system("pause");
        break;
      case '3':
        printf("Informe o site a ser consultado:\n");
        scanf("%s",enderecoBuscado);
        consultarItensdoHistorico(enderecoBuscado,i);
        system("pause");
        break;
      case '4':
        printf("saindo....");
    }
  }while(op != '4');
  return 0;
}

void adicionarItemHistorico(int *ptr_indice){

    //Verifica se já chegamos ao nosso limite do histórico
    if (*ptr_indice == TAM_MAX){
        printf("Chegou no limite....Armazenamento limite:%d sites.\n",TAM_MAX);
        system("pause");
    }
    else {
        printf("Site visitado:\n");
        scanf("%s",itens[*ptr_indice].endereco);
        *ptr_indice = *ptr_indice + 1;
    }
}

void listarItensdoHistorico(int indice){
    int j;
    printf("**** Sites Visitados ****\n");
    for(j=0;j<indice;j++){
        printf("Site: %s\n",itens[j].endereco);
    }
}

void consultarItensdoHistorico(char enderecoBuscado[50],int indice){
    int j,retorno=1;

    for(j=0;j<indice;j++){
        retorno = strncmp(itens[j].endereco,enderecoBuscado,50);
        if (retorno == 0){
            //Site encontrado, sair do laço
            printf("Endereco |%s| Localizado no Historico\n",enderecoBuscado);
            break;
        }
     }
     if (retorno != 0){
        printf("Endereco |%s| NAO Localizado no Historico\n",enderecoBuscado);
     }
}
