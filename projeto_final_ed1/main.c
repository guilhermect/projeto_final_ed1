//main
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "cbo.h"

int main()
{
    setlocale(LC_ALL,"Portuguese");

    Lista *li;
    int x,id;
    struct funcionario func;
    struct funcionario dados_funcionario;
    int opc_menu=1; //Variavel declarada com o valor 1 pois a aplicacao rodara enquanto ela for diferente de 0.
    int opc_menu_editar=0; //Variavel que recebe as opcoes do menu de edição do funcionário

    li = criaLista();

    while(opc_menu!=0){

        printf("\n\nEscolha uma opcao do menu:\n\n");
        printf("\t0 - Sair da aplicação \n");
        printf("\t1 - Inserir funcionario \n");
        printf("\t2 - Excluir funcionario \n");
        printf("\t3 - Exibir funcionarios ordenadamente por ID \n");
        printf("\t4 - Editar funcionario \n");

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

                //Consulta as informações do funcionario antes de excluir
                consulta_funcionario_id(li, id, &func);

                //Caso o funcionario com o ID digitado exista ocorre a confirmação, caso contrario exibe a msg "Funcionario inexistente"
                x = exibe_funcionario_id(func,id);
                if(x){
                    // Função que confirma a remoção do funcionario
                    confirma_remocao_funcionario(li, id);
                }
                break;

            case 3:
                printf("\n\n\t---------- LISTA DE FUNCIONÁRIOS ----------");

                x =tamLista(li);
                //printf("%d",x);
                for(int i=1; i<=x; i++){
                    consulta_funcionarios_orden(li, i, &func);
                    printf("\n\n\tFuncionario %d: \n",i);
                    // Exibe as informações do funcionario ordenadamente após fazer a consulta
                    exibe_funcionario_orden(func);
                    printf("\n\n\t---------------------------------------------");
                }

                break;

            case 4:
                printf("Digite o ID do funcionario a ser editado: ");
                scanf("%d",&id);

                //Consulta as informações do funcionario que será editado
                consulta_funcionario_id(li, id, &func);
                //Caso o funcionario com o ID digitado exista ocorre a confirmação, caso contrario exibe a msg "Funcionario inexistente"
                exibe_funcionario_id(func,id);

                printf("\n\nEscolha uma opção:\n\n");
                printf("\n\t1 - Editar informações \n");
                printf("\t2 - Reajustar salario \n");
                printf("\t3 - Somente visualizar dados \n");
                printf("\n\tOpcao:  ");
                scanf("%d", &opc_menu_editar);

                switch(opc_menu_editar){
                    case 1:
                        //Deleta o funcionario e insere na mesma posicao com o mesmo ID com as novas informações
                        remove_funcionario_id(li, id);
                        func = edita_funcionario(id);
                        x = insere_funcionario_orden(li,func);
                        if(x){
                            printf("\n\nFuncionario atualizado com sucesso!");
                        }else{
                            printf("\nNao foi possivel atualizar o funcionario!");
                        }
                        break;
                    case 2:
                        consulta_funcionario_id(li, id, &func);
                        reajustar_salario(&func.salario);
                    case 3:
                        //Consulta as informações do funcionario
                        consulta_funcionario_id(li, id, &func);
                        //Caso o funcionario com o ID digitado exista ocorre a confirmação, caso contrario exibe a msg "Funcionario inexistente"
                        exibe_funcionario_id(func,id);
                        break;
                }



                break;


        }
    }


}
