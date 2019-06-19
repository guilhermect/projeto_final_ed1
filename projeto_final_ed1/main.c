//main

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "cbo.h"

int main()
{
    setlocale(LC_ALL,"Portuguese");

    Lista *li;
    int x, id = 110, posicao = 1;
    struct funcionario func, dados_funcionario;
    int opc_menu=1;

    li = criaLista();

     while(opc_menu!=0){

        printf("\n\nEscolha uma opcao do menu:\n\n");
        printf("\t1 - Inserir funcionario \n");
        printf("\t0 - Sair da aplicação \n");
        printf("\n\tOpcao:  ");
        scanf("%d", &opc_menu);
        printf("\n\n");
        switch(opc_menu){
            case 0:
                printf("\nObrigado por utilizar a aplicação!\n\n");
                libera_lista(li);
                break;
            case 1:
                preenche_funcionario();
                x = insere_funcionario_orden(li,func);
                if(x){
                    printf("\nInserido ordenadamente com sucesso!");
                }else{
                    printf("\nNao foi possivel inserir ordenadamente");
                }

                break;
        }
    }

    /*


    x = tamLista(li);
    printf("O tamanho da lista eh: %d ",x);

    if(listaCheia(li)){
        printf("\nLista esta cheia!\n");
    }else{
        printf("\nLista esta vazia! \n");
    }

    if(listaVazia(li)){
        printf("\nLista esta vazia");
    }else{
        printf("\nLista nao esta vazia!");
    }



    x = remove_funcionario_id(li, id);
    if(x){
        printf("\nRemovido elemento com sucesso");
    }else{
        printf("\nNao foi possivel remover o elemento");
    }

    x = consulta_funcionarios_orden(li, posicao, &al);
    printf("\n\nConteudo na posicao %d: ", posicao);
    printf("\n%d",al.id);
    printf("\n%.2f",al.n1);
    printf("\n%.2f",al.n2);
    printf("\n%.2f",al.n3);

    x = consulta_funcionario_id(li, id, &al);
    printf("\n\nid encontrada na posicao %d: ", posicao);
    printf("\n%d",al.id);
    printf("\n%.2f",al.n1);
    printf("\n%.2f",al.n2);
    printf("\n%.2f",al.n3);

    libera_lista(li);*/

}
