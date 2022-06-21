#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"

void menu(Personagem *personagens)
{
    int tamanho = 0;
    char opcao;

    while (1)
    {
        printf("\n\t\tRPG");
        printf("\n\tMENU - PERSONAGENS\n");
        printf("\n\t1 - Criar");
        printf("\n\t2 - Editar");
        printf("\n\t3 - Listar");
        printf("\n\t4 - Excluir");
        printf("\n\t5 - Pesquisar");
        printf("\n\t6 - Exportar dados");
        printf("\n\t0 - Sair do programa\n\t");
        scanf("%c", &opcao);

        if (opcao == '1')
            personagens = criar_personagem(personagens, &tamanho);
        else if (opcao == '2')
            editar_personagem(personagens, tamanho);
        else if (opcao == '3')
            listar_personagem(personagens);
        else if (opcao == '4')
            excluir_personagem(personagens);
        else if (opcao == '5')
            pesquisar_personagem(personagens);
        else if (opcao == '6')
            exportar_personagem(personagens);
        else if (opcao == '0')
            break;
        else
            printf("\n\n\tOpcao invalida!!!\n");
    }
}

Personagem *criar_personagem(Personagem *personagens, int *tamanho)
{
    int tam_acrescentado = 0, sair = 0;
    while (1)
    {
        // para sair da criação do presonagem, sair precisa ser 1
        if (sair == 1)
        {
            personagens = realloc(personagens, (*tamanho) * sizeof(Personagem));
            break;
        }

        for (size_t i = (*tamanho); i < tam_acrescentado + 10; i++)
        {
            printf("\n\n\n\tNome do personagem: ");
            setbuf(stdin, NULL);
            fgets(personagens[i].nick_name, 31, stdin);
            personagens[i].nick_name[strcspn(personagens[i].nick_name, "\n")] = '\0';

            // sair da criação do personagem, atribui valor 1 em sair
            if (strcmp(personagens[i].nick_name, "sair") == 0)
            {
                sair = 1;
                (*tamanho) = i;
                break;
            }

            printf("\n\n\tIdade: ");
            scanf("%d", &personagens[i].idade);

            printf("\n\n\tGenero: ");
            printf("\n\t1 - Masculino\n\t2 - Feminino\n\t");
            scanf("%d", &personagens[i].genero);

            printf("\n\n\tAltura: ");
            scanf("%d", &personagens[i].altura);

            printf("\n\n\tRaca: ");
            setbuf(stdin, NULL);
            fgets(personagens[i].raca, 31, stdin);
            personagens[i].raca[strcspn(personagens[i].raca, "\n")] = '\0';

            printf("\n\n\tHistoria do personagem: ");
            setbuf(stdin, NULL);
            fgets(personagens[i].historia_personagem, 700, stdin);
            personagens[i].historia_personagem[strcspn(personagens[i].historia_personagem, "\n")] = '\0';

            printf("\n\n\tClasse: ");
            setbuf(stdin, NULL);
            fgets(personagens[i].status.classe.nome_classe, 31, stdin);
            personagens[i].status.classe.nome_classe[strcspn(personagens[i].status.classe.nome_classe, "\n")] = '\0';

            printf("\n\n\tNivel da classe: ");
            scanf("%d", &personagens[i].status.classe.nivel_classe);

            printf("\n\n\tNome da classe: ");
            setbuf(stdin, NULL);
            fgets(personagens[i].status.classe.nome_classe, 31, stdin);
            personagens[i].status.classe.nome_classe[strcspn(personagens[i].status.classe.nome_classe, "\n")] = '\0';

            printf("\n\n\tArma: ");
            setbuf(stdin, NULL);
            fgets(personagens[i].status.classe.arma, 31, stdin);
            personagens[i].status.classe.arma[strcspn(personagens[i].status.classe.arma, "\n")] = '\0';

            printf("\n\n\tCapacete: ");
            setbuf(stdin, NULL);
            fgets(personagens[i].status.classe.capacete, 31, stdin);
            personagens[i].status.classe.capacete[strcspn(personagens[i].status.classe.capacete, "\n")] = '\0';

            printf("\n\n\tManto: ");
            setbuf(stdin, NULL);
            fgets(personagens[i].status.classe.manto, 31, stdin);
            personagens[i].status.classe.manto[strcspn(personagens[i].status.classe.manto, "\n")] = '\0';

            printf("\n\n\tPeitoral: ");
            setbuf(stdin, NULL);
            fgets(personagens[i].status.classe.peitoral, 31, stdin);
            personagens[i].status.classe.peitoral[strcspn(personagens[i].status.classe.peitoral, "\n")] = '\0';

            printf("\n\n\tCalca: ");
            setbuf(stdin, NULL);
            fgets(personagens[i].status.classe.calca, 31, stdin);
            personagens[i].status.classe.calca[strcspn(personagens[i].status.classe.calca, "\n")] = '\0';

            printf("\n\n\tBota: ");
            setbuf(stdin, NULL);
            fgets(personagens[i].status.classe.bota, 31, stdin);
            personagens[i].status.classe.bota[strcspn(personagens[i].status.classe.bota, "\n")] = '\0';

            printf("\n\n\tNivel do Personagem: ");
            scanf("%d", &personagens[i].status.nivel_personagem);

            printf("\n\n\tReputacao: ");
            scanf("%d", &personagens[i].status.reputacao);

            printf("\n\n\tarmadura Fisica: ");
            scanf("%d", &personagens[i].status.armadura_fisica);

            printf("\n\n\tArmadura Magica: ");
            scanf("%d", &personagens[i].status.armadura_magica);

            printf("\n\n\tPenetracao de armadura: ");
            scanf("%d", &personagens[i].status.penetracao_armadura);

            printf("\n\n\tPenetracao Magica: ");
            scanf("%d", &personagens[i].status.penetracao_magica);

            printf("\n\n\tDano Fisico: ");
            scanf("%d", &personagens[i].status.dano_fisico);

            printf("\n\n\tDano Magico: ");
            scanf("%d", &personagens[i].status.dano_magico);

            printf("\n\n\tChance de critico: ");
            scanf("%d", &personagens[i].status.chance_critico);

            printf("\n\n\tVelocidade: ");
            scanf("%d", &personagens[i].status.velocidade);

            if (i == (9 + tam_acrescentado))
            {
                personagens = realloc(personagens, (tam_acrescentado + 10) * sizeof(Personagem));
                tam_acrescentado = tam_acrescentado + 10;
                (*tamanho) = i;
                break;
            }
        }
    }
    return personagens;
}

int validar_id(Personagem persogagem, int tamanho, int id)
{
    for (size_t i = 0; i < tamanho; i++)
    {
        if (id == persogagem.id)
            return 1;
        else
            return 0;
    }
}

int validar_nome(Personagem persogagem, int tamanho, char* busca)
{
    for (size_t i = 0; i < tamanho; i++)
    {
        if (id == persogagem.id)
            return 1;
        else
            return 0;
    }
}

void editar_personagem(Personagem *personagens, int tamanho)
{
    int id, i;
    char op, busca[31];

    do
    {
        printf("\n\n\t2 - Buscar por ID");
        printf("\n\t1 - Buscar por nome\n\t");
        setbuf(stdin, NULL);
        scanf("%c", &op);
    } while (op != '1' || op != '2');

    if (op == '1')
    {
        printf("\n\tId do personagem: ");
        scanf("%d", &id);

        if (validar_id(personagens, tamanho, id) == 1)
        {
            printf("\n\n\tNome do personagem: ");
            setbuf(stdin, NULL);
            fgets(personagens[i].nick_name, 31, stdin);
            personagens[i].nick_name[strcspn(personagens[i].nick_name, "\n")] = '\0';

            printf("\n\n\tIdade: ");
            scanf("%d", &personagens[i].idade);

            printf("\n\n\tGenero: ");
            printf("\n\t1 - Masculino\n\t2 - Feminino\n\t");
            scanf("%d", &personagens[i].genero);

            printf("\n\n\tAltura: ");
            scanf("%d", &personagens[i].altura);

            printf("\n\n\tRaca: ");
            setbuf(stdin, NULL);
            fgets(personagens[i].raca, 31, stdin);
            personagens[i].raca[strcspn(personagens[i].raca, "\n")] = '\0';

            printf("\n\n\tHistoria do personagem: ");
            setbuf(stdin, NULL);
            fgets(personagens[i].historia_personagem, 700, stdin);
            personagens[i].historia_personagem[strcspn(personagens[i].historia_personagem, "\n")] = '\0';

            printf("\n\n\tClasse: ");
            setbuf(stdin, NULL);
            fgets(personagens[i].status.classe.nome_classe, 31, stdin);
            personagens[i].status.classe.nome_classe[strcspn(personagens[i].status.classe.nome_classe, "\n")] = '\0';

            printf("\n\n\tNivel da classe: ");
            scanf("%d", &personagens[i].status.classe.nivel_classe);

            printf("\n\n\tNome da classe: ");
            setbuf(stdin, NULL);
            fgets(personagens[i].status.classe.nome_classe, 31, stdin);
            personagens[i].status.classe.nome_classe[strcspn(personagens[i].status.classe.nome_classe, "\n")] = '\0';

            printf("\n\n\tArma: ");
            setbuf(stdin, NULL);
            fgets(personagens[i].status.classe.arma, 31, stdin);
            personagens[i].status.classe.arma[strcspn(personagens[i].status.classe.arma, "\n")] = '\0';

            printf("\n\n\tCapacete: ");
            setbuf(stdin, NULL);
            fgets(personagens[i].status.classe.capacete, 31, stdin);
            personagens[i].status.classe.capacete[strcspn(personagens[i].status.classe.capacete, "\n")] = '\0';

            printf("\n\n\tManto: ");
            setbuf(stdin, NULL);
            fgets(personagens[i].status.classe.manto, 31, stdin);
            personagens[i].status.classe.manto[strcspn(personagens[i].status.classe.manto, "\n")] = '\0';

            printf("\n\n\tPeitoral: ");
            setbuf(stdin, NULL);
            fgets(personagens[i].status.classe.peitoral, 31, stdin);
            personagens[i].status.classe.peitoral[strcspn(personagens[i].status.classe.peitoral, "\n")] = '\0';

            printf("\n\n\tCalca: ");
            setbuf(stdin, NULL);
            fgets(personagens[i].status.classe.calca, 31, stdin);
            personagens[i].status.classe.calca[strcspn(personagens[i].status.classe.calca, "\n")] = '\0';

            printf("\n\n\tBota: ");
            setbuf(stdin, NULL);
            fgets(personagens[i].status.classe.bota, 31, stdin);
            personagens[i].status.classe.bota[strcspn(personagens[i].status.classe.bota, "\n")] = '\0';

            printf("\n\n\tNivel do Personagem: ");
            scanf("%d", &personagens[i].status.nivel_personagem);

            printf("\n\n\tReputacao: ");
            scanf("%d", &personagens[i].status.reputacao);

            printf("\n\n\tarmadura Fisica: ");
            scanf("%d", &personagens[i].status.armadura_fisica);

            printf("\n\n\tArmadura Magica: ");
            scanf("%d", &personagens[i].status.armadura_magica);

            printf("\n\n\tPenetracao de armadura: ");
            scanf("%d", &personagens[i].status.penetracao_armadura);

            printf("\n\n\tPenetracao Magica: ");
            scanf("%d", &personagens[i].status.penetracao_magica);

            printf("\n\n\tDano Fisico: ");
            scanf("%d", &personagens[i].status.dano_fisico);

            printf("\n\n\tDano Magico: ");
            scanf("%d", &personagens[i].status.dano_magico);

            printf("\n\n\tChance de critico: ");
            scanf("%d", &personagens[i].status.chance_critico);

            printf("\n\n\tVelocidade: ");
            scanf("%d", &personagens[i].status.velocidade);
        }
        else
            printf("\n\tID inválido!");
    }

    if (op == '2')
    {
        printf("\n\tNome a ser buscado: ");
        setbuf(stdin, NULL);
        fgets(busca, 31, stdin);
        busca[strcspn(busca, "\n")] = '\0';


    }

    scanf("%d", &i);

    printf("\n\n\tNome do personagem: ");
    setbuf(stdin, NULL);
    fgets(personagens[i].nick_name, 31, stdin);
    personagens[i].nick_name[strcspn(personagens[i].nick_name, "\n")] = '\0';

    printf("\n\n\tIdade: ");
    scanf("%d", &personagens[i].idade);

    printf("\n\n\tGenero: ");
    printf("\n\t1 - Masculino\n\t2 - Feminino\n\t");
    scanf("%d", &personagens[i].genero);

    printf("\n\n\tAltura: ");
    scanf("%d", &personagens[i].altura);

    printf("\n\n\tRaca: ");
    setbuf(stdin, NULL);
    fgets(personagens[i].raca, 31, stdin);
    personagens[i].raca[strcspn(personagens[i].raca, "\n")] = '\0';

    printf("\n\n\tHistoria do personagem: ");
    setbuf(stdin, NULL);
    fgets(personagens[i].historia_personagem, 700, stdin);
    personagens[i].historia_personagem[strcspn(personagens[i].historia_personagem, "\n")] = '\0';

    printf("\n\n\tClasse: ");
    setbuf(stdin, NULL);
    fgets(personagens[i].status.classe.nome_classe, 31, stdin);
    personagens[i].status.classe.nome_classe[strcspn(personagens[i].status.classe.nome_classe, "\n")] = '\0';

    printf("\n\n\tNivel da classe: ");
    scanf("%d", &personagens[i].status.classe.nivel_classe);

    printf("\n\n\tNome da classe: ");
    setbuf(stdin, NULL);
    fgets(personagens[i].status.classe.nome_classe, 31, stdin);
    personagens[i].status.classe.nome_classe[strcspn(personagens[i].status.classe.nome_classe, "\n")] = '\0';

    printf("\n\n\tArma: ");
    setbuf(stdin, NULL);
    fgets(personagens[i].status.classe.arma, 31, stdin);
    personagens[i].status.classe.arma[strcspn(personagens[i].status.classe.arma, "\n")] = '\0';

    printf("\n\n\tCapacete: ");
    setbuf(stdin, NULL);
    fgets(personagens[i].status.classe.capacete, 31, stdin);
    personagens[i].status.classe.capacete[strcspn(personagens[i].status.classe.capacete, "\n")] = '\0';

    printf("\n\n\tManto: ");
    setbuf(stdin, NULL);
    fgets(personagens[i].status.classe.manto, 31, stdin);
    personagens[i].status.classe.manto[strcspn(personagens[i].status.classe.manto, "\n")] = '\0';

    printf("\n\n\tPeitoral: ");
    setbuf(stdin, NULL);
    fgets(personagens[i].status.classe.peitoral, 31, stdin);
    personagens[i].status.classe.peitoral[strcspn(personagens[i].status.classe.peitoral, "\n")] = '\0';

    printf("\n\n\tCalca: ");
    setbuf(stdin, NULL);
    fgets(personagens[i].status.classe.calca, 31, stdin);
    personagens[i].status.classe.calca[strcspn(personagens[i].status.classe.calca, "\n")] = '\0';

    printf("\n\n\tBota: ");
    setbuf(stdin, NULL);
    fgets(personagens[i].status.classe.bota, 31, stdin);
    personagens[i].status.classe.bota[strcspn(personagens[i].status.classe.bota, "\n")] = '\0';

    printf("\n\n\tNivel do Personagem: ");
    scanf("%d", &personagens[i].status.nivel_personagem);

    printf("\n\n\tReputacao: ");
    scanf("%d", &personagens[i].status.reputacao);

    printf("\n\n\tarmadura Fisica: ");
    scanf("%d", &personagens[i].status.armadura_fisica);

    printf("\n\n\tArmadura Magica: ");
    scanf("%d", &personagens[i].status.armadura_magica);

    printf("\n\n\tPenetracao de armadura: ");
    scanf("%d", &personagens[i].status.penetracao_armadura);

    printf("\n\n\tPenetracao Magica: ");
    scanf("%d", &personagens[i].status.penetracao_magica);

    printf("\n\n\tDano Fisico: ");
    scanf("%d", &personagens[i].status.dano_fisico);

    printf("\n\n\tDano Magico: ");
    scanf("%d", &personagens[i].status.dano_magico);

    printf("\n\n\tChance de critico: ");
    scanf("%d", &personagens[i].status.chance_critico);

    printf("\n\n\tVelocidade: ");
    scanf("%d", &personagens[i].status.velocidade);
}

void listar_personagem(Personagem *personagens)
{
}

void excluir_personagem(Personagem *personagens)
{
}

void pesquisar_personagem(Personagem *personagens)
{
}

void exportar_personagem(Personagem *personagens)
{
}