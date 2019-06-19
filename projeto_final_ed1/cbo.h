typedef struct funcionario{
    int id;
    char nome[30];
    char endereco[100];
    int idade;
    float salario;
    int cargo;
}FUNC;

typedef struct elemento* Lista;

Lista *criaLista();

void libera_lista(Lista *li);

int tamLista(Lista *li);

int listaCheia(Lista *li);

int listaVazia(Lista *li);

// Coleta as informações do funcionario
FUNC preenche_funcionario();

int insere_funcionario_orden(Lista *li, FUNC func);

// Exibe as informações do funcionario após fazer a consulta
int exibe_funcionario();

// Função que confirma a remoção do funcionario
int confirma_remocao_funcionario();

int remove_funcionario_id(Lista *li, int id_func);

int consulta_funcionarios_orden(Lista *li, int posicao, FUNC *al);

int consulta_funcionario_id(Lista *li, int id, FUNC *al);

