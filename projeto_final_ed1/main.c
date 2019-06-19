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
        printf("\t3 - Editar funcionario \n");
        printf("\t4 - Exibir funcionarios \n");
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
                x = exibe_funcionario_id(func,id);
                if(x){
                    // Função que confirma a remoção do funcionario
                    confirma_remocao_funcionario(li, id);
                }
                break;

            case 3:

                break;

            case 4:
                printf("\n\n\t---------- LISTA DE FUNCIONÁRIOS ----------");

                x =tamLista(li);
                for(int i=1; i<=x; i++){
                    consulta_funcionarios_orden(li, i, &func);
                    printf("\n\n\tFuncionario %d: \n",i);
                    // Exibe as informações do funcionario ordenadamente após fazer a consulta
                    exibe_funcionario_orden(func);
                    printf("\n\n\t---------------------------------------------");
                }
                break;


        }
    }



}
