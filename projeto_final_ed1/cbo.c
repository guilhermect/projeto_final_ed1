// .c
#include <stdio.h>
#include <stdlib.h>
#include "cbo.h"

struct elemento{
    FUNC dados;
    struct elemento *prox;
};

typedef struct elemento ELEM;

Lista *criaLista(){
    Lista *li;
    li = (Lista*) malloc(sizeof(Lista));
    if(li != NULL){
        *li = NULL;
    }
    return li;
}

void libera_lista(Lista *li){
    if(li != NULL){
        ELEM *no;
        while((*li) != NULL){
            no = *li;
            *li = (*li)->prox;
            free(no);
        }
        free(li);
    }
}

int tamLista(Lista *li){
    if(li == NULL){
        return 0;
    }
    int acum = 0;
    ELEM *no = *li;
    while(no != NULL){
        acum++;
        no = no->prox;
    }
    return acum;
}

int listaCheia(Lista *li){
    return 0;
}

int listaVazia(Lista *li){
    if(li == NULL){
        return 1;
    }
    if(*li == NULL){
        return 1;
    }
    return 0;
}

FUNC preenche_funcionario(){
    FUNC f;
    printf("\nDigite o ID do funcionario: ");
    scanf("%d",&f.id);
    getchar();
    printf("Digite o nome do funcionario: ");
    fgets(f.nome, 29, stdin);
    printf("Digite o endereco do funcionario: ");
    fgets(f.endereco, 99, stdin);
    printf("Digite a idade do funcionario: ");
    scanf("%d",&f.idade);
    printf("Digite o salario do funcionario: ");
    scanf("%f",&f.salario);
    printf("Digite o cargo do funcionario: ");
    scanf("%d",&f.cargo);
    return f;
}

int insere_funcionario_orden(Lista *li, FUNC func){
    if(li == NULL){
        return 0;
    }

    ELEM *no = (ELEM*) malloc(sizeof(ELEM));

    if(no == NULL){
        return 0;
    }

    no->dados = func;

    if(listaVazia(li)){
        no->prox = (*li);
        *li = no;
        return 1;
    }else{
        ELEM *ant, *atual = *li;

        while(atual != NULL && atual->dados.id < func.id){
            ant = atual;
            atual = atual->prox;
        }

        if(atual == *li){
            no->prox = (*li);
            *li = no;
        }else{
            no->prox = ant->prox;
            ant->prox = no;
        }

        return 1;
    }
}


// Exibe as informações do funcionario após fazer a consulta
int exibe_funcionario_id(FUNC f, int id){

    //Verifica se o ID digitado existe na lista
    if(id != f.id){
        printf("\nFuncionário inexistente!");
        return 0;
    } else {

        printf("\n\nInformações do Funcionario: \n");
        printf("\n\tID: %d",f.id);
        printf("\n\tNome: %s",f.nome);
        printf("\tEndereço: %s",f.endereco);
        printf("\tIdade: %d",f.idade);
        printf("\n\tSalario: %.2f",f.salario);
        printf("\n\tCargo: %d",f.cargo);
    }
}

int confirma_remocao_funcionario(li, id){
    int remover=0,x;
    printf("\n\nTem certeza que deseja remover este funcionario?\n\n");
    printf("\t1 - Sim \n");
    printf("\t2 - Não \n");
    printf("Escolha uma opção: ");
    scanf("%d",&remover);

    if(remover==1){
        x = remove_funcionario_id(li, id);
        if(x){
            printf("\nFuncionário removido com sucesso!");
        }else{
            printf("\nNao foi possivel remover o funcionário");
        }
    }

}


int remove_funcionario_id(Lista *li, int id_func){
    if(li == NULL){
        return 0;
    }
    ELEM *ant, *no = *li;
    while(no != NULL && no->dados.id != id_func){
        ant = no;
        no = no->prox;
    }
    if(no == NULL){
        return 0;
    }
    if(no == *li){
        *li = no->prox;
    }else{
        ant->prox = no->prox;
    }
    libera_lista(li);
    return 1;
}


// Exibe as informações do funcionario ordenadamente após fazer a consulta
int exibe_funcionario_orden(FUNC f){
    printf("\n\tID: %d",f.id);
    printf("\n\tNome: %s",f.nome);
    printf("\tSalario: %.2f",f.salario);
    printf("\n\tCargo: %d",f.cargo);
}

int consulta_funcionarios_orden(Lista *li, int posicao, FUNC *al){
    if(li == NULL || posicao <= 0){
        return 0;
    }
    ELEM *no = *li;
    int i=1;
    while(no != NULL && i < posicao){
        no = no->prox;
        i++;
    }
    if (no == NULL){
        return 0;
    }else{
        *al = no->dados;
        return 1;
    }
}


int consulta_funcionario_id(Lista *li, int id, FUNC *func){
    if(li == NULL){
        return 0;
    }
    ELEM *no = *li;
    while(no != NULL && no->dados.id != id){
        no = no->prox;
    }
    if(no == NULL){
        return 0;
    }else{
        *func = no->dados;
        return 1;
    }
}

