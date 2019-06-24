// .h
typedef struct funcionario{
    int id;
    char nome[50];
    char endereco[100];
    int idade;
    float salario;
    int cargo;
}FUNC;

typedef struct lista_cbo{
    int id;
    int codigo;
    char cargo[30];
}CBO;

typedef struct elemento* Lista;

Lista *criaLista();

void libera_lista(Lista *li);

int tamLista(Lista *li);

int tamListaCBO(Lista *li);

int listaCheia(Lista *li);

int listaVazia(Lista *li);

CBO preenche_lista_cbo(Lista *li_cbo);

int insere_cbo_orden(Lista *li, CBO cargo);

// Coleta as informações do funcionario
FUNC preenche_funcionario(Lista *li_cbo);

int insere_funcionario_orden(Lista *li, FUNC func);

int consulta_cbo_orden(Lista *li, int posicao, CBO *cargo);

int consulta_cbo_id(Lista *li, int id, CBO *cargo);

// Exibe as informações do funcionario após fazer a consulta
int exibe_funcionario_id(FUNC f, int id);

// Função que confirma a remoção do funcionario
int confirma_remocao_funcionario();

int remove_funcionario_id(Lista *li, int id_func);

// Exibe as informações do funcionario ordenadamente após fazer a consulta
int exibe_funcionario_orden(FUNC f);

int consulta_funcionarios_orden(Lista *li, int posicao, FUNC *func);

int consulta_funcionario_id(Lista *li, int id, FUNC *func);

FUNC reajustar_salario(int id, char nome[50], char endereco[100], int idade, float salario, int cargo);

// Preenche as novas informaçoes do funcionario sem alteração do ID
FUNC edita_funcionario(int id, Lista *li_cbo);

// Gera arquivo txt com todos os funcionarios e suas informações ao encerrar o programa
int cria_arquivo_funcionarios(Lista *li);
