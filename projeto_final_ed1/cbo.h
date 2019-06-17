typedef struct funcionario{
    int id;
    float n1,n2,n3;
}funcionario;

typedef struct elemento* Lista;

Lista *criaLista();

void libera_lista(Lista *li);

int tamLista(Lista *li);

int listaCheia(Lista *li);

int listaVazia(Lista *li);

int insere_funcionario_orden(Lista *li, funcionario func);

int remove_funcionario_id(Lista *li, int id_func);

int consulta_funcionarios_orden(Lista *li, int posicao, funcionario *al);

int consulta_funcionario_id(Lista *li, int id, funcionario *al);

