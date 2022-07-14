// Arquivo header contendo as structs e funções usadas no projeto

// Constantes para selecionar cores
#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_BLUE "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN "\x1b[36m"
#define ANSI_COLOR_RESET "\x1b[0m"

// Structs usadas no projeto
typedef struct
{
    int id;
    int nivel_classe;
    char nome_classe[31];
    char arma[31];
    char capacete[31];
    char manto[31];
    char peitoral[31];
    char calca[31]; // calça
    char bota[31];
} Classe;

typedef struct
{
    int id;
    int nivel_personagem;
    int chance_critico;
    int reputacao;
    int penetracao_armadura;
    int penetracao_magica;
    float velocidade;
    float dano_fisico;
    float dano_magico;
    float armadura_fisica;
    float armadura_magica;
    Classe classe;
} Status;

typedef struct
{
    int id;
    int idade;
    int genero;
    float altura;
    char nick_name[31];
    char historia_personagem[700];
    char raca[31]; // raça
    Status status;
} Personagem;

// Funções
/**
 * @brief Criptografa a senha usando a Cifra de Cesar
 *
 * @param key Senha a ser criptografada
 */
void criptografar(char *key);

/**
 * @brief Descriptocrafa a senha
 *
 * @param key Senha a ser descriptografada
 */
void descriptografar(char *key);

/**
 * @brief Se for a primeira vez do usuario usando o programa,
 * será feito o cadastro do usuário, senão, irá logar o usuário
 * com a senha cadastrada
 *
 */
void login();

/**
 * @brief Inicia o programa, verificando se já foi salvo os dados
 * anteriormente ou não
 *
 * Se for a primeira vez rodando o programa, ao fechar, os dados
 * serão salvos em um arquivo, senão os dados serão carregados do
 * arquivo
 *
 * @param personagens
 */
void iniciar_programa(Personagem *personagens);

/**
 * @brief Menu onde está concentrado as operações possíveis do programa
 *
 * @param personagens
 * @param num_personagens
 */
void menu(Personagem *personagens, int *num_personagens);

/**
 * @brief Inicializa os valores dos personagens
 *
 * @param personagem
 */
void inicializar_personagem(Personagem *personagem);

/**
 * @brief Retorna o ponteiro do personagem
 * Cadastra os personagens e realoca o tamanho de seu vetor quando
 * necessário
 *
 * @param personagens
 * @param tamanho
 * @return Personagem*
 */
Personagem *inserir_personagem(Personagem *personagens, int *tamanho);

/**
 * @brief Retorna o numero de personagens cadastrados, retorna 0 quando
 * não há personagens cadastrados
 *
 * @param personagens
 * @param tamanho
 * @return
 */
int personagens_cadastrados(Personagem *personagens, int tamanho);

/**
 * @brief Edita os dados do personagem
 *
 * @param personagens
 * @param tamanho
 */
void editar_personagem(Personagem *personagens, int tamanho);

/**
 * @brief Lista todos os personagens cadastrados
 *
 * @param personagens
 * @param tamanho
 */
void listar_personagem(Personagem personagens, int tamanho);

/**
 * @brief Exclui o personagem escolhido pelo usuário
 *
 * @param personagens
 * @param tamanho
 */
void excluir_personagem(Personagem *personagens, int tamanho);

/**
 * @brief Mostra os dados de um personagem escolhido pelo usuário
 *
 * @param personagens
 * @param tamanho
 */
void pesquisar_personagem(Personagem *personagens, int tamanho);

/**
 * @brief Exporta os dados dos personagens à um arquivo CSV
 *
 * @param personagens
 * @param tamanho
 */
void exportar_personagem(Personagem *personagens, int tamanho);

/**
 * @brief Escreve na tela os dados do personagem
 *
 * @param personagens
 */
void escrever_personagem(Personagem *personagens);



