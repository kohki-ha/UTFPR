typedef struct
{
    int id;
    int nivel_classe;
    char nome_classe[31];
    char arma[31];
    char capacete[31];
    char manto[31];
    char peitoral[31];
    char calca[31]; //calça
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
    char raca[31]; //raça
    Status status;
} Personagem;

void menu(Personagem* personagens);
void escrever_personagem(Personagem* perso);
Personagem* criar_personagem(Personagem* personagens, int* tamanho);
void editar_personagem(Personagem* personagens, int tamanho);
void listar_personagem(Personagem * personagens, int tamanho);
void excluir_personagem(Personagem* personagens);
void pesquisar_personagem(Personagem* personagens);
void exportar_personagem(Personagem* personagens);
