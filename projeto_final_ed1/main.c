//main

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "cbo.h"

int main()
{
    setlocale(LC_ALL,"Portuguese");

    Lista *li;
    int x,id;
    struct funcionario func, dados_funcionario;
    int opc_menu=1; //Variavel declarada com o valor 1 pois a aplicacao rodara enquanto ela for diferente de 0.

    li = criaLista();

    while(opc_menu!=0){

        printf("\n\nEscolha uma opcao do menu:\n\n");
        printf("\t1 - Inserir funcionario \n");
        printf("\t2 - Excluir funcionario \n");
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
                //Função que coleta os dados do funcionario
                func = preenche_funcionario();
                x = insere_funcionario_orden(li,func);
                if(x){
                    printf("\n\nFuncionario inserido com sucesso!");
                }else{
                    printf("\nNao foi possivel inserir o funcionario!");
                }

                break;

            case 2:
                printf("Digite o ID do funcionario a ser excluido: ");
                scanf("%d",&id);

                //Exibe as informações do funcionario antes de excluir
                consulta_funcionario_id(li, id, &func);

                //Caso o funcionario com o ID digitado exista ocorre a confirmação, caso contrario exibe a msg "Funcionario inexistente"
                x = exibe_funcionario(func,id);
                if(x){
                    // Função que confirma a remoção do funcionario
                    confirma_remocao_funcionario(li, id);
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
