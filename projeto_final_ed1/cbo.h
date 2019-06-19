typedef struct funcionario{
    int id;
    char nome[30];
    int idade;
    float salario;
}FUNC;

typedef struct elemento* Lista;

Lista *criaLista();

void libera_lista(Lista *li);

int tamLista(Lista *li);

int listaCheia(Lista *li);

int listaVazia(Lista *li);

FUNC preenche_funcionario();

int insere_funcionario_orden(Lista *li, FUNC func);

int remove_funcionario_id(Lista *li, int id_func);

int consulta_funcionarios_orden(Lista *li, int posicao, FUNC *al);

int consulta_funcionario_id(Lista *li, int id, FUNC *al);

