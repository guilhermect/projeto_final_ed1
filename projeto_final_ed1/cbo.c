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
    printf("\nDigite o id do funcionario: ");
    scanf("%d",&f.id);
    getchar();
    printf("Digite o nome do funcionario: ");
    fgets(f.nome, 29, stdin);
    printf("Digite a idade do funcionario: ");
    scanf("%d",&f.idade);
    printf("Digite o salario do funcionario: ");
    scanf("%f",&f.salario);
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
    free(no);
    return 1;
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


int consulta_funcionario_id(Lista *li, int id, FUNC *al){
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
        *al = no->dados;
        return 1;
    }
}

