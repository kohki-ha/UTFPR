#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

void menu(Personagem *personagens, int *num_personagens)
{
    int tamanho = (*num_personagens);
    char opcao;

    while (1)
    {
        printf(ANSI_COLOR_BLUE "\n\n\t\tRPG" ANSI_COLOR_RESET);
        printf(ANSI_COLOR_BLUE "\n\tMENU - PERSONAGENS\n" ANSI_COLOR_RESET);
        printf(ANSI_COLOR_YELLOW "\n\t1 - Criar" ANSI_COLOR_RESET);
        printf(ANSI_COLOR_YELLOW "\n\t2 - Editar" ANSI_COLOR_RESET);
        printf(ANSI_COLOR_YELLOW "\n\t3 - Listar" ANSI_COLOR_RESET);
        printf(ANSI_COLOR_YELLOW "\n\t4 - Excluir" ANSI_COLOR_RESET);
        printf(ANSI_COLOR_YELLOW "\n\t5 - Pesquisar" ANSI_COLOR_RESET);
        printf(ANSI_COLOR_YELLOW "\n\t6 - Exportar dados" ANSI_COLOR_RESET);
        printf(ANSI_COLOR_YELLOW "\n\t0 - Sair do programa\n\t" ANSI_COLOR_RESET);
        setbuf(stdin, NULL);
        scanf("%c", &opcao);

        if (opcao == '1')
            personagens = criar_personagem(personagens, &tamanho);
        else if (opcao == '2')
        {
            editar_personagem(personagens, tamanho);
            if (personagens_cadastrados(personagens, tamanho) == 0)
                printf(ANSI_COLOR_RED "\n\tNenhum personagem cadastrado!!!\n" ANSI_COLOR_RESET);
        }
        else if (opcao == '3')
        {
            for (size_t i = 0; i < tamanho; i++)
                listar_personagem(personagens[i], tamanho);
            if (personagens_cadastrados(personagens, tamanho) == 0)
                printf(ANSI_COLOR_RED "\n\tNenhum personagem cadastrado!!!\n" ANSI_COLOR_RESET);
        }
        else if (opcao == '4')
        {
            excluir_personagem(personagens, tamanho);
            if (personagens_cadastrados(personagens, tamanho) == 0)
                printf(ANSI_COLOR_RED "\n\tNenhum personagem cadastrado!!!\n" ANSI_COLOR_RESET);
        }
        else if (opcao == '5')
        {
            pesquisar_personagem(personagens, tamanho);
            if (personagens_cadastrados(personagens, tamanho) == 0)
                printf(ANSI_COLOR_RED "\n\tNenhum personagem cadastrado!!!\n" ANSI_COLOR_RESET);
        }
        else if (opcao == '6')
        {
            exportar_personagem(personagens, tamanho);
            if (personagens_cadastrados(personagens, tamanho) == 0)
                printf(ANSI_COLOR_RED "\n\tNenhum personagem cadastrado!!!\n" ANSI_COLOR_RESET);
        }
        else if (opcao == '0')
        {
            (*num_personagens) = tamanho;
            break;
        }
        else
            printf(ANSI_COLOR_RED "\n\n\tOpcao invalida!!!\n" ANSI_COLOR_RESET);
    }
}

void inicializar_personagem(Personagem *personagem)
{
    personagem->id = 0;
    personagem->idade = 0;
    personagem->genero = 0;
    personagem->altura = 0;
    personagem->status.id = 0;
    personagem->status.nivel_personagem = 0;
    personagem->status.chance_critico = 0;
    personagem->status.reputacao = 0;
    personagem->status.penetracao_armadura = 0;
    personagem->status.penetracao_magica = 0;
    personagem->status.velocidade = 0;
    personagem->status.dano_fisico = 0;
    personagem->status.dano_magico = 0;
    personagem->status.armadura_fisica = 0;
    personagem->status.armadura_magica = 0;
    personagem->status.classe.id = 0;
    personagem->status.classe.nivel_classe = 0;
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
            inicializar_personagem((personagens + i));

            printf(ANSI_COLOR_CYAN "\n\n\tNome do personagem: " ANSI_COLOR_RESET);
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

            printf(ANSI_COLOR_CYAN "\n\tIdade: " ANSI_COLOR_RESET);
            scanf("%d", &personagens[i].idade);

            printf(ANSI_COLOR_CYAN "\n\tGenero: " ANSI_COLOR_RESET);
            printf(ANSI_COLOR_CYAN "\n\t1 - Masculino\n\t2 - Feminino\n\t" ANSI_COLOR_RESET);
            scanf("%d", &personagens[i].genero);

            printf(ANSI_COLOR_CYAN "\n\tAltura: " ANSI_COLOR_RESET);
            scanf("%f", &personagens[i].altura);

            printf(ANSI_COLOR_CYAN "\n\tRaca: " ANSI_COLOR_RESET);
            setbuf(stdin, NULL);
            fgets(personagens[i].raca, 31, stdin);
            personagens[i].raca[strcspn(personagens[i].raca, "\n")] = '\0';

            printf(ANSI_COLOR_CYAN "\n\tHistoria do personagem: " ANSI_COLOR_RESET);
            setbuf(stdin, NULL);
            fgets(personagens[i].historia_personagem, 700, stdin);
            personagens[i].historia_personagem[strcspn(personagens[i].historia_personagem, "\n")] = '\0';

            printf(ANSI_COLOR_CYAN "\n\tClasse: " ANSI_COLOR_RESET);
            setbuf(stdin, NULL);
            fgets(personagens[i].status.classe.nome_classe, 31, stdin);
            personagens[i].status.classe.nome_classe[strcspn(personagens[i].status.classe.nome_classe, "\n")] = '\0';

            printf(ANSI_COLOR_CYAN "\n\tNivel da classe: " ANSI_COLOR_RESET);
            scanf("%d", &personagens[i].status.classe.nivel_classe);

            printf(ANSI_COLOR_CYAN "\n\tArma: " ANSI_COLOR_RESET);
            setbuf(stdin, NULL);
            fgets(personagens[i].status.classe.arma, 31, stdin);
            personagens[i].status.classe.arma[strcspn(personagens[i].status.classe.arma, "\n")] = '\0';

            printf(ANSI_COLOR_CYAN "\n\tCapacete: " ANSI_COLOR_RESET);
            setbuf(stdin, NULL);
            fgets(personagens[i].status.classe.capacete, 31, stdin);
            personagens[i].status.classe.capacete[strcspn(personagens[i].status.classe.capacete, "\n")] = '\0';

            printf(ANSI_COLOR_CYAN "\n\tManto: " ANSI_COLOR_RESET);
            setbuf(stdin, NULL);
            fgets(personagens[i].status.classe.manto, 31, stdin);
            personagens[i].status.classe.manto[strcspn(personagens[i].status.classe.manto, "\n")] = '\0';

            printf(ANSI_COLOR_CYAN "\n\tPeitoral: " ANSI_COLOR_RESET);
            setbuf(stdin, NULL);
            fgets(personagens[i].status.classe.peitoral, 31, stdin);
            personagens[i].status.classe.peitoral[strcspn(personagens[i].status.classe.peitoral, "\n")] = '\0';

            printf(ANSI_COLOR_CYAN "\n\tCalca: " ANSI_COLOR_RESET);
            setbuf(stdin, NULL);
            fgets(personagens[i].status.classe.calca, 31, stdin);
            personagens[i].status.classe.calca[strcspn(personagens[i].status.classe.calca, "\n")] = '\0';

            printf(ANSI_COLOR_CYAN "\n\tBota: " ANSI_COLOR_RESET);
            setbuf(stdin, NULL);
            fgets(personagens[i].status.classe.bota, 31, stdin);
            personagens[i].status.classe.bota[strcspn(personagens[i].status.classe.bota, "\n")] = '\0';

            printf(ANSI_COLOR_CYAN "\n\tNivel do Personagem: " ANSI_COLOR_RESET);
            scanf("%d", &personagens[i].status.nivel_personagem);

            printf(ANSI_COLOR_CYAN "\n\tReputacao: " ANSI_COLOR_RESET);
            scanf("%d", &personagens[i].status.reputacao);

            printf(ANSI_COLOR_CYAN "\n\tarmadura Fisica: " ANSI_COLOR_RESET);
            scanf("%f", &personagens[i].status.armadura_fisica);

            printf(ANSI_COLOR_CYAN "\n\tArmadura Magica: " ANSI_COLOR_RESET);
            scanf("%f", &personagens[i].status.armadura_magica);

            printf(ANSI_COLOR_CYAN "\n\tPenetracao de armadura: " ANSI_COLOR_RESET);
            scanf("%d", &personagens[i].status.penetracao_armadura);

            printf(ANSI_COLOR_CYAN "\n\tPenetracao Magica: " ANSI_COLOR_RESET);
            scanf("%d", &personagens[i].status.penetracao_magica);

            printf(ANSI_COLOR_CYAN "\n\tDano Fisico: " ANSI_COLOR_RESET);
            scanf("%f", &personagens[i].status.dano_fisico);

            printf(ANSI_COLOR_CYAN "\n\tDano Magico: " ANSI_COLOR_RESET);
            scanf("%f", &personagens[i].status.dano_magico);

            printf(ANSI_COLOR_CYAN "\n\tChance de critico: " ANSI_COLOR_RESET);
            scanf("%d", &personagens[i].status.chance_critico);

            printf(ANSI_COLOR_CYAN "\n\tVelocidade: " ANSI_COLOR_RESET);
            scanf("%f", &personagens[i].status.velocidade);

            personagens[i].id = i + 1;
            personagens[i].status.id = i + 1;
            personagens[i].status.classe.id = i + 1;

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

int personagens_cadastrados(Personagem *personagens, int tamanho)
{
    int numero_personagens = 0;

    for (size_t i = 0; i < tamanho; i++)
    {
        if (personagens[i].id > 0)
            numero_personagens++;
    }

    return numero_personagens;
}

void editar_personagem(Personagem *personagens, int tamanho)
{
    int id, i, encontrado = 0;
    char busca[31];

    printf(ANSI_COLOR_CYAN "\n\n\tId do personagem: " ANSI_COLOR_RESET);
    scanf("%d", &id);

    for (size_t j = 0; j < tamanho; j++)
    {
        if (id == personagens[j].id)
        {
            encontrado = 1;
            i = id - 1;
            printf(ANSI_COLOR_GREEN "\n\tID encontrado!!!\n" ANSI_COLOR_RESET);
            escrever_personagem(&personagens[i]);
        }
    }
    if (encontrado == 0)
        printf(ANSI_COLOR_RED "\n\tID nao encontrado...\n" ANSI_COLOR_RESET);
}

void listar_personagem(Personagem personagens, int tamanho)
{
    if (personagens.id > 0 && personagens.status.id > 0 && personagens.status.classe.id > 0)
    {
        printf("\x1b[34m" "\n\n\t%2d\n" ANSI_COLOR_RESET, personagens.id);
        printf(ANSI_COLOR_CYAN "\tNickname: %s\n" ANSI_COLOR_RESET, personagens.nick_name);
        printf(ANSI_COLOR_CYAN "\tIdade: %d\n" ANSI_COLOR_RESET, personagens.idade);
        printf(ANSI_COLOR_CYAN "\tGenero: %d\n" ANSI_COLOR_RESET, personagens.genero);
        printf(ANSI_COLOR_CYAN "\tAltura: %.2f\n" ANSI_COLOR_RESET, personagens.altura);
        printf(ANSI_COLOR_CYAN "\tRaca: %s\n" ANSI_COLOR_RESET, personagens.raca);
        printf(ANSI_COLOR_CYAN "\tHistoria do personagem: %s\n" ANSI_COLOR_RESET, personagens.historia_personagem);
        printf(ANSI_COLOR_CYAN "\tClasse: %s\n" ANSI_COLOR_RESET, personagens.status.classe.nome_classe);
        printf(ANSI_COLOR_CYAN "\tNivel da classe: %d\n" ANSI_COLOR_RESET, personagens.status.classe.nivel_classe);
        printf(ANSI_COLOR_CYAN "\tArma: %s\n" ANSI_COLOR_RESET, personagens.status.classe.arma);
        printf(ANSI_COLOR_CYAN "\tCapacete: %s\n" ANSI_COLOR_RESET, personagens.status.classe.capacete);
        printf(ANSI_COLOR_CYAN "\tManto: %s\n" ANSI_COLOR_RESET, personagens.status.classe.manto);
        printf(ANSI_COLOR_CYAN "\tPeitoral: %s\n" ANSI_COLOR_RESET, personagens.status.classe.peitoral);
        printf(ANSI_COLOR_CYAN "\tCalca: %s\n" ANSI_COLOR_RESET, personagens.status.classe.calca);
        printf(ANSI_COLOR_CYAN "\tBota: %s\n" ANSI_COLOR_RESET, personagens.status.classe.bota);
        printf(ANSI_COLOR_CYAN "\tNivel do Personagem: %d\n" ANSI_COLOR_RESET, personagens.status.nivel_personagem);
        printf(ANSI_COLOR_CYAN "\tReputacao: %d\n" ANSI_COLOR_RESET, personagens.status.reputacao);
        printf(ANSI_COLOR_CYAN "\tarmadura Fisica: %.2f\n" ANSI_COLOR_RESET, personagens.status.armadura_fisica);
        printf(ANSI_COLOR_CYAN "\tArmadura Magica: %.2f\n" ANSI_COLOR_RESET, personagens.status.armadura_magica);
        printf(ANSI_COLOR_CYAN "\tPenetracao de armadura: %d\n" ANSI_COLOR_RESET, personagens.status.penetracao_armadura);
        printf(ANSI_COLOR_CYAN "\tPenetracao Magica: %d\n" ANSI_COLOR_RESET, personagens.status.penetracao_magica);
        printf(ANSI_COLOR_CYAN "\tDano Fisico: %.2f\n" ANSI_COLOR_RESET, personagens.status.dano_fisico);
        printf(ANSI_COLOR_CYAN "\tDano Magico: %.2f\n" ANSI_COLOR_RESET, personagens.status.dano_magico);
        printf(ANSI_COLOR_CYAN "\tChance de critico: %d\n" ANSI_COLOR_RESET, personagens.status.chance_critico);
        printf(ANSI_COLOR_CYAN "\tVelocidade: %.2f\n" ANSI_COLOR_RESET, personagens.status.velocidade);
    }
}

void excluir_personagem(Personagem *personagens, int tamanho)
{
    int id, i, encontrado = 0;
    char busca[31];

    printf(ANSI_COLOR_CYAN "\n\n\tID que deseja excluir: " ANSI_COLOR_RESET);
    scanf("%d", &id);

    for (size_t j = 0; j < tamanho; j++)
    {
        if (id == personagens[j].id)
        {
            encontrado = 1;
            i = id - 1;
            personagens[i].id = 0;
            personagens[i].status.id = 0;
            personagens[i].status.classe.id = 0;

            printf(ANSI_COLOR_GREEN "\n\tPersonagem com ID = %d excluido!!!\n" ANSI_COLOR_RESET, id);
        }
    }
    if (encontrado == 0)
        printf(ANSI_COLOR_RED "\n\tID nao encontrado...\n" ANSI_COLOR_RESET);
}

void pesquisar_personagem(Personagem *personagens, int tamanho)
{
    int id, i, encontrado = 0;
    printf(ANSI_COLOR_CYAN "\n\n\tID que deseja buscar: " ANSI_COLOR_RESET);
    scanf("%d", &id);

    for (size_t j = 0; j < tamanho; j++)
    {
        if (id == personagens[j].id)
        {
            encontrado++;
            i = id - 1;
            listar_personagem(personagens[i], tamanho);

            printf(ANSI_COLOR_GREEN "\n\tPersonagem encontrado!!!\n" ANSI_COLOR_RESET);
        }
    }

    if (encontrado == 0)
        printf(ANSI_COLOR_RED "\n\tPersonagem nao encontrado...\n" ANSI_COLOR_RESET);
}

void exportar_personagem(Personagem *personagens, int tamanho)
{
    FILE *arq = fopen("dados.csv", "w");

    if (arq == NULL)
    {
        printf(ANSI_COLOR_RED "Erro ao abrir o arquivo...\n" ANSI_COLOR_RESET);
        exit(1);
    }

    fprintf(arq, "ID_Personagem, ID_Status, ID_Classe, Nick_name, Idade, Genero, Altura, Raça, História, Classe, Nivel_Classe, Arma, Capacete, Manto, Peitoral, Calça, Bota, Nivel_personagem, Reputação, Armadura_fisica, Armadura_magica, Penetração_fisica, Penetração_mágica, Dano_físico, Dano_mágico, Chance_crítico, Velocidade\n");
    for (size_t i = 0; i < tamanho; i++)
    {
        if (personagens[i].id > 0 && personagens[i].status.id > 0 && personagens[i].status.classe.id > 0)
        {
            fprintf(arq, "%2d, ", personagens[i].id);
            fprintf(arq, "%2d, ", personagens[i].status.id);
            fprintf(arq, "%2d, ", personagens[i].status.classe.id);
            fprintf(arq, "%s, ", personagens[i].nick_name);
            fprintf(arq, "%d, ", personagens[i].idade);
            fprintf(arq, "%d, ", personagens[i].genero);
            fprintf(arq, "%.2f, ", personagens[i].altura);
            fprintf(arq, "%s, ", personagens[i].raca);
            fprintf(arq, "%s, ", personagens[i].historia_personagem);
            fprintf(arq, "%s, ", personagens[i].status.classe.nome_classe);
            fprintf(arq, "%d, ", personagens[i].status.classe.nivel_classe);
            fprintf(arq, "%s, ", personagens[i].status.classe.arma);
            fprintf(arq, "%s, ", personagens[i].status.classe.capacete);
            fprintf(arq, "%s, ", personagens[i].status.classe.manto);
            fprintf(arq, "%s, ", personagens[i].status.classe.peitoral);
            fprintf(arq, "%s, ", personagens[i].status.classe.calca);
            fprintf(arq, "%s, ", personagens[i].status.classe.bota);
            fprintf(arq, "%d, ", personagens[i].status.nivel_personagem);
            fprintf(arq, "%d, ", personagens[i].status.reputacao);
            fprintf(arq, "%.2f, ", personagens[i].status.armadura_fisica);
            fprintf(arq, "%.2f, ", personagens[i].status.armadura_magica);
            fprintf(arq, "%d, ", personagens[i].status.penetracao_armadura);
            fprintf(arq, "%d, ", personagens[i].status.penetracao_magica);
            fprintf(arq, "%.2f, ", personagens[i].status.dano_fisico);
            fprintf(arq, "%.2f, ", personagens[i].status.dano_magico);
            fprintf(arq, "%d, ", personagens[i].status.chance_critico);
            fprintf(arq, "%.f\n", personagens[i].status.velocidade);
        }
    }

    fclose(arq);
}

void escrever_personagem(Personagem *personagens)
{
    printf(ANSI_COLOR_CYAN "\n\tNome do personagem: " ANSI_COLOR_RESET);
    setbuf(stdin, NULL);
    fgets(personagens->nick_name, 31, stdin);
    personagens->nick_name[strcspn(personagens->nick_name, "\n")] = '\0';

    printf(ANSI_COLOR_CYAN "\n\tIdade: " ANSI_COLOR_RESET);
    scanf("%d", &personagens->idade);

    printf(ANSI_COLOR_CYAN "\n\tGenero: " ANSI_COLOR_RESET);
    printf(ANSI_COLOR_CYAN "\n\t1 - Masculino\n\t2 - Feminino\n\t" ANSI_COLOR_RESET);
    scanf("%d", &personagens->genero);

    printf(ANSI_COLOR_CYAN "\n\tAltura: " ANSI_COLOR_RESET);
    scanf("%f", &personagens->altura);

    printf(ANSI_COLOR_CYAN "\n\tRaca: " ANSI_COLOR_RESET);
    setbuf(stdin, NULL);
    fgets(personagens->raca, 31, stdin);
    personagens->raca[strcspn(personagens->raca, "\n")] = '\0';

    printf(ANSI_COLOR_CYAN "\n\tHistoria do personagem: " ANSI_COLOR_RESET);
    setbuf(stdin, NULL);
    fgets(personagens->historia_personagem, 700, stdin);
    personagens->historia_personagem[strcspn(personagens->historia_personagem, "\n")] = '\0';

    printf(ANSI_COLOR_CYAN "\n\tClasse: " ANSI_COLOR_RESET);
    setbuf(stdin, NULL);
    fgets(personagens->status.classe.nome_classe, 31, stdin);
    personagens->status.classe.nome_classe[strcspn(personagens->status.classe.nome_classe, "\n")] = '\0';

    printf(ANSI_COLOR_CYAN "\n\tNivel da classe: " ANSI_COLOR_RESET);
    scanf("%d", &personagens->status.classe.nivel_classe);

    printf(ANSI_COLOR_CYAN "\n\tArma: " ANSI_COLOR_RESET);
    setbuf(stdin, NULL);
    fgets(personagens->status.classe.arma, 31, stdin);
    personagens->status.classe.arma[strcspn(personagens->status.classe.arma, "\n")] = '\0';

    printf(ANSI_COLOR_CYAN "\n\tCapacete: " ANSI_COLOR_RESET);
    setbuf(stdin, NULL);
    fgets(personagens->status.classe.capacete, 31, stdin);
    personagens->status.classe.capacete[strcspn(personagens->status.classe.capacete, "\n")] = '\0';

    printf(ANSI_COLOR_CYAN "\n\tManto: " ANSI_COLOR_RESET);
    setbuf(stdin, NULL);
    fgets(personagens->status.classe.manto, 31, stdin);
    personagens->status.classe.manto[strcspn(personagens->status.classe.manto, "\n")] = '\0';

    printf(ANSI_COLOR_CYAN "\n\tPeitoral: " ANSI_COLOR_RESET);
    setbuf(stdin, NULL);
    fgets(personagens->status.classe.peitoral, 31, stdin);
    personagens->status.classe.peitoral[strcspn(personagens->status.classe.peitoral, "\n")] = '\0';

    printf(ANSI_COLOR_CYAN "\n\tCalca: " ANSI_COLOR_RESET);
    setbuf(stdin, NULL);
    fgets(personagens->status.classe.calca, 31, stdin);
    personagens->status.classe.calca[strcspn(personagens->status.classe.calca, "\n")] = '\0';

    printf(ANSI_COLOR_CYAN "\n\tBota: " ANSI_COLOR_RESET);
    setbuf(stdin, NULL);
    fgets(personagens->status.classe.bota, 31, stdin);
    personagens->status.classe.bota[strcspn(personagens->status.classe.bota, "\n")] = '\0';

    printf(ANSI_COLOR_CYAN "\n\tNivel do Personagem: " ANSI_COLOR_RESET);
    scanf("%d", &personagens->status.nivel_personagem);

    printf(ANSI_COLOR_CYAN "\n\tReputacao: " ANSI_COLOR_RESET);
    scanf("%d", &personagens->status.reputacao);

    printf(ANSI_COLOR_CYAN "\n\tarmadura Fisica: " ANSI_COLOR_RESET);
    scanf("%f", &personagens->status.armadura_fisica);

    printf(ANSI_COLOR_CYAN "\n\tArmadura Magica: " ANSI_COLOR_RESET);
    scanf("%f", &personagens->status.armadura_magica);

    printf(ANSI_COLOR_CYAN "\n\tPenetracao de armadura: " ANSI_COLOR_RESET);
    scanf("%d", &personagens->status.penetracao_armadura);

    printf(ANSI_COLOR_CYAN "\n\tPenetracao Magica: " ANSI_COLOR_RESET);
    scanf("%d", &personagens->status.penetracao_magica);

    printf(ANSI_COLOR_CYAN "\n\tDano Fisico: " ANSI_COLOR_RESET);
    scanf("%f", &personagens->status.dano_fisico);

    printf(ANSI_COLOR_CYAN "\n\tDano Magico: " ANSI_COLOR_RESET);
    scanf("%f", &personagens->status.dano_magico);

    printf(ANSI_COLOR_CYAN "\n\tChance de critico: " ANSI_COLOR_RESET);
    scanf("%d", &personagens->status.chance_critico);

    printf(ANSI_COLOR_CYAN "\n\tVelocidade: " ANSI_COLOR_RESET);
    scanf("%f", &personagens->status.velocidade);
}