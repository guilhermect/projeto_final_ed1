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


int coleta_cargo_cbo(){
    int codigo, codigos[15]={};
    char texto[20], cargo[20];
    int cod_cargo;
    FILE *f;

    printf("\n---------------- Lista de Cargos ----------------\n\n");
    printf("\t1 - Neurocirurgião \n");
    printf("\t2 - Chaveiro \n");
    printf("\t3 - Compositor \n");
    printf("\t4 - Advogado \n");
    printf("\t5 - Agrônomo \n");
    printf("\t6 - Economista \n");
    printf("\t7 - Encanador \n");
    printf("\t8 - Jardineiro \n");
    printf("\t9 - Joalheiro \n");
    printf("\t10 - Massagista \n");
    printf("\t11 - Matemático \n");
    printf("\t12 - Nutricionista \n");
    printf("\t13 - Padeiro \n");
    printf("\t14 - Radiologista \n");
    printf("\t15 - Urbanista \n");

    printf("\n\tDigite o cargo do funcionario:  ");
    scanf("%d",&cod_cargo);

    f = fopen("lista_cbo.txt", "r");
    if(f == NULL){
        printf("Erro na abertura!\n");
        system("pause");
        exit(1);
    }

    for(int i=0; i<15;i++){

        fscanf(f, "%s %s", texto, cargo);
        fscanf(f, "%s %d", texto, &codigo);

        codigos[i]=codigo;
    }

    fclose(f);
    //Aqui eu subtraio o cod_cargo por 1 pois o 'for' vai de 0 a 14
    //para pegar corretamente os codigos, assim subtraindo o valor
    //escolhido atraves do menu por 1 ele será igual a posicao no vetor
    return codigos[cod_cargo-1];
}

FUNC preenche_funcionario(){
    FUNC f;
    int cod_cargo,x;

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
    //Coleta codigo do cargo escolhido atraves de uma função de lê o arquivo txt,
    //pega somente o codigo do cargo e grava no campo 'cargo'
    f.cargo=coleta_cargo_cbo();
    printf("\n\n");
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
    //free(li);
    return 1;
}


// Exibe as informações do funcionario ordenadamente após fazer a consulta
int exibe_funcionario_orden(FUNC f){
    printf("\n\tID: %d",f.id);
    printf("\n\tNome: %s",f.nome);
    printf("\tSalario: %.2f",f.salario);
    printf("\n\tCargo: %d",f.cargo);
}

int consulta_funcionarios_orden(Lista *li, int posicao, FUNC *func){
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
        *func = no->dados;
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


void reajustar_salario(float *sal){
    //printf("Digite o novo salario: ");
    //scanf("%f",&f.salario);
    *sal=*sal=1500;
}

// Preenche as novas informaçoes do funcionario sem alteração do ID
FUNC edita_funcionario(int id){
    FUNC f;
    int cod_cargo,x;

    f.id=id;
    getchar();
    printf("\tDigite o nome do funcionario: ");
    fgets(f.nome, 29, stdin);
    printf("\tDigite o endereco do funcionario: ");
    fgets(f.endereco, 99, stdin);
    printf("\tDigite a idade do funcionario: ");
    scanf("%d",&f.idade);
    printf("\tDigite o salario do funcionario: ");
    scanf("%f",&f.salario);
    //Coleta codigo do cargo escolhido atraves de uma função de lê o arquivo txt,
    //pega somente o codigo do cargo e grava no campo 'cargo'
    f.cargo=coleta_cargo_cbo();
    printf("\n\n");
    return f;
}




