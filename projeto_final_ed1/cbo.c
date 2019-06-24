// .c
#include <stdio.h>
#include <stdlib.h>
#include "cbo.h"

// Elemento da estrutura funcionario
struct elemento{
    FUNC dados;
    struct elemento *prox;
};

typedef struct elemento ELEM;

// Elemento da estrutura cbo
struct elemento_cbo{
    CBO dados;
    struct elemento *prox;
};

typedef struct elemento_cbo ELEM_CBO;

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

int tamListaCBO(Lista *li){
    if(li == NULL){
        return 0;
    }
    int acum = 0;
    ELEM_CBO *no = *li;
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


int insere_cbo_orden(Lista *li, CBO cargo){
    if(li == NULL){
        return 0;
    }

    ELEM_CBO *no = (ELEM_CBO*) malloc(sizeof(ELEM_CBO));

    if(no == NULL){
        return 0;
    }

    no->dados = cargo;

    if(listaVazia(li)){
        no->prox = (*li);
        *li = no;
        return 1;
    }else{
        ELEM_CBO *ant, *atual = *li;

        while(atual != NULL && atual->dados.id < cargo.id){
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



int consulta_cbo_orden(Lista *li, int posicao, CBO *cargo){
    if(li == NULL || posicao <= 0){
        return 0;
    }
    ELEM_CBO *no = *li;
    int i=1;
    while(no != NULL && i < posicao){
        no = no->prox;
        i++;
    }
    if (no == NULL){
        return 0;
    }else{
        *cargo = no->dados;
        return 1;
    }
}


int consulta_cbo_id(Lista *li, int id, CBO *cargo){
    if(li == NULL){
        return 0;
    }
    ELEM_CBO *no = *li;
    while(no != NULL && no->dados.id != id){
        no = no->prox;
    }
    if(no == NULL){
        return 0;
    }else{
        *cargo = no->dados;
        return 1;
    }
}

CBO preenche_lista_cbo(Lista *li_cbo){
    int codigo, id_cargo;
    char texto[20],cargo[30];
    CBO c;
    FILE *f;

    f = fopen("lista_cbo.txt", "r");
    if(f == NULL){
        printf("Erro na abertura!\n");
        system("pause");
        exit(1);
    }

    for(int i=0; i<15;i++){
        fscanf(f, "%s %d",texto, &id_cargo);
        fscanf(f, "%s %d",texto, &codigo);
        fscanf(f, "%s %s",texto, cargo);

        c.id=id_cargo;
        c.codigo=codigo;
        strcpy(c.cargo,cargo);

        insere_cbo_orden(li_cbo,c);
    }

    fclose(f);
}

FUNC preenche_funcionario(Lista *li_cbo){
    FUNC f;
    CBO c;
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
    printf("Digite o salario do funcionario: R$");
    scanf("%f",&f.salario);

    // Caso a opção de cargo escolhida seja menor que 1 ou maior que 15 o usuario deve digitar novamente
    while (cod_cargo<=0 || cod_cargo>15){
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

        if(cod_cargo<=0 || cod_cargo>15){
            printf("\n\n\tOpção Inválida!\n\n");
        }

    }

    //Consulta o cargo da lista CBO atraves do ID
    consulta_cbo_id(li_cbo, cod_cargo, &c);
    //Atribui o valor do campo "codigo" da estrutura CBO ao campo cargo da estrutura FUNC
    f.cargo=c.codigo;

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
        printf("\n\tSalario: R$%.2f",f.salario);
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
    } else {
        printf("Funcionário não excluído.");
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


// Exibe as informações do funcionario ordenadamente após fazer a consulta
int exibe_funcionario_orden(FUNC f){
    printf("\n\tID: %d",f.id);
    printf("\n\tNome: %s",f.nome);
    printf("\tSalario: R$%.2f",f.salario);
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


FUNC reajustar_salario(int id, char nome[50], char endereco[100], int idade, float salario, int cargo){
    FUNC f;
    int cod_cargo,x;
    float porc;//Valor da porcentagem para reajuste escolhida pelo usuario

    f.id=id;
    strcpy(f.nome, nome);
    strcpy(f.endereco, endereco);
    f.idade=idade;
    f.cargo=cargo;

    printf("\tDigite a porcentagem de reajuste do salario do funcionario: ");
    scanf("%f",&porc);

    //porcentagem = f.salario*((float)porc/100);
    f.salario = salario + (salario * (porc/100.0));

    printf("\n\n");
    return f;
}

// Preenche as novas informaçoes do funcionario sem alteração do ID
FUNC edita_funcionario(int id, Lista *li_cbo){
    FUNC f;
    CBO c;
    int cod_cargo,x;

    f.id=id;
    getchar();
    printf("\tDigite o nome do funcionario: ");
    fgets(f.nome, 49, stdin);
    printf("\tDigite o endereco do funcionario: ");
    fgets(f.endereco, 99, stdin);
    printf("\tDigite a idade do funcionario: ");
    scanf("%d",&f.idade);
    printf("\tDigite o salario do funcionario: R$");
    scanf("%f",&f.salario);

    // Caso a opção de cargo escolhida seja menor que 1 ou maior que 15 o usuario deve digitar novamente
    while (cod_cargo<=0 || cod_cargo>15){
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

        if(cod_cargo<=0 || cod_cargo>15){
            printf("\n\n\tOpção Inválida!\n\n");
        }

    }

    //Consulta o cargo da lista CBO atraves do ID
    consulta_cbo_id(li_cbo, cod_cargo, &c);

    //Atribui o valor do campo "codigo" da estrutura CBO ao campo cargo da estrutura FUNC
    f.cargo=c.codigo;

    printf("\n\n");

    return f;
}

int cria_arquivo_funcionarios(Lista *li){
    FUNC func;
    FILE *file;
    file = fopen("lista_funcionarios.txt", "w");
    if(file == NULL){
        printf("Erro na abertura\n");
        system("pause");
        exit(1);
    }
    int i,x;

    x =tamLista(li);
    fprintf(file,"---------------- Lista de Funcionários ----------------\n\n");

    for(int i=1; i<=x; i++){
        consulta_funcionarios_orden(li, i, &func);

        fprintf(file, "\t- Funcionario %d:\n",i);
        fprintf(file, "\t\t- ID: %d\n", func.id);
        fprintf(file, "\t\t- Nome: %s", func.nome);
        fprintf(file, "\t\t- Endereço: %s", func.endereco);
        fprintf(file, "\t\t- Idade: %d\n", func.idade);
        fprintf(file, "\t\t- Salario: R$%.2f\n", func.salario);
        fprintf(file, "\t\t- Cargo: %d\n", func.cargo);
        fprintf(file, "\t----------------------------\n\n");
    }

    fclose(file);
}





