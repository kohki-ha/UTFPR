#define MAX 31


typedef struct
{
    int id;
    int nivel_classe;
    char nome_classe[MAX];
    char arma[MAX];
    char capacete[MAX];
    char manto[MAX];
    char peitoral[MAX];
    char calca[MAX]; //calça
    char bota[MAX];
} Classe;

typedef struct
{
    int id;
    int nivel_personagem;
    int chance_critico;
    int reputacao;
    int penetracao_armadura;
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
    char nick_name[MAX];
    char historia_personagem[700];
    char raca[MAX]; //raça
    Status status;
} Personagem;

void menu(Personagem* personagens);
void cirar_personagem(Personagem* personagens);
void editar_personagem(Personagem* personagens);
void listar_personagem(Personagem* personagens);
void excluir_personagem(Personagem* personagens);
void pesquisar_personagem(Personagem* personagens);
void exportar_personagem(Personagem* personagens);
