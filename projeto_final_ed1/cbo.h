typedef struct funcionario{
    int id;
    char nome[50];
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

int coleta_cargo_cbo();

// Coleta as informações do funcionario
FUNC preenche_funcionario();

int insere_funcionario_orden(Lista *li, FUNC func);

// Exibe as informações do funcionario após fazer a consulta
int exibe_funcionario_id(FUNC f, int id);

// Função que confirma a remoção do funcionario
int confirma_remocao_funcionario();

int remove_funcionario_id(Lista *li, int id_func);

// Exibe as informações do funcionario ordenadamente após fazer a consulta
int exibe_funcionario_orden(FUNC f);

int consulta_funcionarios_orden(Lista *li, int posicao, FUNC *al);

int consulta_funcionario_id(Lista *li, int id, FUNC *al);

FUNC reajustar_salario(int id, char nome[50], char endereco[100], int idade, int cargo);

// Preenche as novas informaçoes do funcionario sem alteração do ID
FUNC edita_funcionario(int id);


