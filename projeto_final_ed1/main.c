//main
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "cbo.h"

int main()
{
    setlocale(LC_ALL,"Portuguese");

    Lista *li;
    Lista *li_cbo;
    int x,id,i;
    struct funcionario func;
    struct lista_cbo c;
    int opc_menu=1; //Variavel declarada com o valor 1 pois a aplicacao rodara enquanto ela for diferente de 0.
    int opc_menu_editar=0; //Variavel que recebe as opcoes do menu de edição do funcionário

    li = criaLista(); //Lista de funcionarios
    li_cbo = criaLista(); //Lista de cargos CBO

    //Le arquivo e grava os dados dos cargos na lista CBO.
    preenche_lista_cbo(li_cbo);

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
                x =tamLista(li);

                if(x>0){
                    // Gera arquivo txt com todos os funcionarios e suas informações ao encerrar o programa
                    cria_arquivo_funcionarios(li);
                }

                libera_lista(li);

                break;
            case 1:
                //Função que coleta os dados do funcionario
                func = preenche_funcionario(li_cbo);
                x = insere_funcionario_orden(li,func);
                if(x){
                    printf("\n\nFuncionario inserido com sucesso!");
                }else{
                    printf("\nNao foi possivel inserir o funcionario!");
                }
                break;

            case 2:
                x =tamLista(li);

                if(x>0){
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
                } else {
                    printf("Não há funcionários inseridos!");
                }
                break;

            case 3:
                x =tamLista(li);

                if(x>0){
                    printf("\n\n\t---------- LISTA DE FUNCIONÁRIOS ----------");

                    for(int i=1; i<=x; i++){
                        consulta_funcionarios_orden(li, i, &func);
                        printf("\n\n\tFuncionario %d: \n",i);
                        // Exibe as informações do funcionario ordenadamente após fazer a consulta
                        exibe_funcionario_orden(func);
                        printf("\n\n\t---------------------------------------------");
                    }
                } else {
                    printf("Não há funcionários inseridos!");
                }

                break;

            case 4:
                x=tamLista(li);

                if(x>0){

                    printf("Digite o ID do funcionario a ser editado: ");
                    scanf("%d",&id);
                    //Consulta as informações do funcionario que será editado
                    consulta_funcionario_id(li, id, &func);
                    //Caso o funcionario com o ID digitado exista ocorre a confirmação, caso contrario exibe a msg "Funcionario inexistente"
                    x = exibe_funcionario_id(func,id);

                    if(x){

                        printf("\n\nEscolha uma opção:\n\n");
                        printf("\n\t1 - Editar informações \n");
                        printf("\t2 - Reajustar salario \n");
                        printf("\t3 - Somente visualizar dados \n");
                        printf("\n\tOpcao:");
                        scanf("%d", &opc_menu_editar);

                        switch(opc_menu_editar){
                            case 1:
                                //Deleta o funcionario e insere na mesma posicao com o mesmo ID com as novas informações
                                remove_funcionario_id(li, id);
                                func = edita_funcionario(id, li_cbo);
                                x = insere_funcionario_orden(li,func);
                                if(x){
                                    printf("\n\nFuncionario atualizado com sucesso!");
                                }else{
                                    printf("\nNao foi possivel atualizar o funcionario!");
                                }
                                break;
                            case 2:
                                //Deleta o funcionario e insere na mesma posicao com o mesmo ID com o novo salario
                                remove_funcionario_id(li, id);
                                // Reajusta o salario a partir da porcentagem digitada pelo usuario
                                func = reajustar_salario(id, func.nome, func.endereco, func.idade, func.salario, func.cargo);
                                x = insere_funcionario_orden(li,func);
                                if(x){
                                    printf("\n\nSalario do funcionario reajustado com sucesso!");
                                }else{
                                    printf("\nNão foi possivel reajusta o  salario do funcionario!");
                                }

                            case 3:
                                //Consulta as informações do funcionario
                                consulta_funcionario_id(li, id, &func);
                                //Caso o funcionario com o ID digitado exista ocorre a confirmação, caso contrario exibe a msg "Funcionario inexistente"
                                exibe_funcionario_id(func,id);
                                break;
                        }
                    }
                } else {
                    printf("Não há funcionários inseridos!");
                }

                break;
                default:
                    printf("Opção inválida!");
                    break;
        }
    }

}
