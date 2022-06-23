#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

void menu(Personagem *personagens, int num_linhas, FILE *arq)
{
    int tamanho = num_linhas;
    char opcao;

    while (1)
    {
        printf("\n\n\t\tRPG");
        printf("\n\tMENU - PERSONAGENS\n");
        printf("\n\t1 - Criar");
        printf("\n\t2 - Editar");
        printf("\n\t3 - Listar");
        printf("\n\t4 - Excluir");
        printf("\n\t5 - Pesquisar");
        printf("\n\t6 - Exportar dados");
        printf("\n\t0 - Sair do programa\n\t");
        setbuf(stdin, NULL);
        scanf("%c", &opcao);

        if (opcao == '1')
            personagens = criar_personagem(personagens, &tamanho);
        else if (opcao == '2')
        {
            editar_personagem(personagens, tamanho);
            if (personagens_cadastrados(personagens, tamanho) == 0)
                printf("\n\tNenhum personagem cadastrado!!!\n");
        }
        else if (opcao == '3')
        {
            for (size_t i = 0; i < tamanho; i++)
                listar_personagem(personagens[i], tamanho);
            if (personagens_cadastrados(personagens, tamanho) == 0)
                printf("\n\tNenhum personagem cadastrado!!!\n");
        }
        else if (opcao == '4')
        {
            excluir_personagem(personagens, tamanho);
            if (personagens_cadastrados(personagens, tamanho) == 0)
                printf("\n\tNenhum personagem cadastrado!!!\n");
        }
        else if (opcao == '5')
        {
            pesquisar_personagem(personagens, tamanho);
            if (personagens_cadastrados(personagens, tamanho) == 0)
                printf("\n\tNenhum personagem cadastrado!!!\n");
        }
        else if (opcao == '6')
        {
            exportar_personagem(personagens, tamanho);
            if (personagens_cadastrados(personagens, tamanho) == 0)
                printf("\n\tNenhum personagem cadastrado!!!\n");
        }
        else if (opcao == '0')
        {
            rewind(arq);
            fwrite(&tamanho, sizeof(int), 1, arq);
            fwrite(personagens, sizeof(Personagem), tamanho, arq);
            break;
        }
        else
            printf("\n\n\tOpcao invalida!!!\n");
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
            scanf("%f", &personagens[i].altura);

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
            scanf("%f", &personagens[i].status.armadura_fisica);

            printf("\n\n\tArmadura Magica: ");
            scanf("%f", &personagens[i].status.armadura_magica);

            printf("\n\n\tPenetracao de armadura: ");
            scanf("%d", &personagens[i].status.penetracao_armadura);

            printf("\n\n\tPenetracao Magica: ");
            scanf("%d", &personagens[i].status.penetracao_magica);

            printf("\n\n\tDano Fisico: ");
            scanf("%f", &personagens[i].status.dano_fisico);

            printf("\n\n\tDano Magico: ");
            scanf("%f", &personagens[i].status.dano_magico);

            printf("\n\n\tChance de critico: ");
            scanf("%d", &personagens[i].status.chance_critico);

            printf("\n\n\tVelocidade: ");
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

    printf("\n\tId do personagem: ");
    scanf("%d", &id);

    for (size_t j = 0; j < tamanho; j++)
    {
        if (id == personagens[j].id)
        {
            encontrado = 1;
            i = id - 1;
            printf("\n\tID encontrado!!!");
            escrever_personagem(&personagens[i]);
        }
    }
    if (encontrado == 0)
        printf("\n\tID nao encontrado...");
}

void listar_personagem(Personagem personagens, int tamanho)
{
    if (personagens.id > 0 && personagens.status.id > 0 && personagens.status.classe.id > 0)
    {
        printf("\n\n\t%2d\n", personagens.id);
        printf("\tNickname: %s\n", personagens.nick_name);
        printf("\tIdade: %d\n", personagens.idade);
        printf("\tGenero: %d\n", personagens.genero);
        printf("\tAltura: %.2f\n", personagens.altura);
        printf("\tRaca: %s\n", personagens.raca);
        printf("\tHistoria do personagem: %s\n", personagens.historia_personagem);
        printf("\tClasse: %s\n", personagens.status.classe.nome_classe);
        printf("\tNivel da classe: %d\n", personagens.status.classe.nivel_classe);
        printf("\tArma: %s\n", personagens.status.classe.arma);
        printf("\tCapacete: %s\n", personagens.status.classe.capacete);
        printf("\tManto: %s\n", personagens.status.classe.manto);
        printf("\tPeitoral: %s\n", personagens.status.classe.peitoral);
        printf("\tCalca: %s\n", personagens.status.classe.calca);
        printf("\tBota: %s\n", personagens.status.classe.bota);
        printf("\tNivel do Personagem: %d\n", personagens.status.nivel_personagem);
        printf("\tReputacao: %d\n", personagens.status.reputacao);
        printf("\tarmadura Fisica: %.2f\n", personagens.status.armadura_fisica);
        printf("\tArmadura Magica: %.2f\n", personagens.status.armadura_magica);
        printf("\tPenetracao de armadura: %d\n", personagens.status.penetracao_armadura);
        printf("\tPenetracao Magica: %d\n", personagens.status.penetracao_magica);
        printf("\tDano Fisico: %.2f\n", personagens.status.dano_fisico);
        printf("\tDano Magico: %.2f\n", personagens.status.dano_magico);
        printf("\tChance de critico: %d\n", personagens.status.chance_critico);
        printf("\tVelocidade: %.2f\n", personagens.status.velocidade);
    }
}

void excluir_personagem(Personagem *personagens, int tamanho)
{
    int id, i, encontrado = 0;
    char busca[31];

    printf("\n\n\tID que deseja excluir: ");
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

            printf("\n\tPersonagem com ID = %d excluido!!!", id);
        }
    }
    if (encontrado == 0)
        printf("\n\tID nao encontrado...");
}

void pesquisar_personagem(Personagem *personagens, int tamanho)
{
    int id, i, encontrado = 0;

    printf("\n\n\tID que deseja buscar: ");
    scanf("%d", &id);

    for (size_t j = 0; j < tamanho; j++)
    {
        if (id == personagens[j].id)
        {
            encontrado++;
            i = id - 1;
            listar_personagem(personagens[i], tamanho);

            printf("\n\tPersonagem encontrado!!!");
        }
    }

    if (encontrado == 0)
        printf("\n\tPersonagem nao encontrado...");
}

void exportar_personagem(Personagem *personagens, int tamanho)
{
    FILE *arq = fopen("dados.csv", "w");

    if (arq == NULL)
    {
        printf("Erro ao abrir o arquivo");
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

void escrever_personagem(Personagem *perso)
{
    printf("\n\n\tNome do personagem: ");
    setbuf(stdin, NULL);
    fgets(perso->nick_name, 31, stdin);
    perso->nick_name[strcspn(perso->nick_name, "\n")] = '\0';

    printf("\n\n\tIdade: ");
    scanf("%d", &perso->idade);

    printf("\n\n\tGenero: ");
    printf("\n\t1 - Masculino\n\t2 - Feminino\n\t");
    scanf("%d", &perso->genero);

    printf("\n\n\tAltura: ");
    scanf("%f", &perso->altura);

    printf("\n\n\tRaca: ");
    setbuf(stdin, NULL);
    fgets(perso->raca, 31, stdin);
    perso->raca[strcspn(perso->raca, "\n")] = '\0';

    printf("\n\n\tHistoria do personagem: ");
    setbuf(stdin, NULL);
    fgets(perso->historia_personagem, 700, stdin);
    perso->historia_personagem[strcspn(perso->historia_personagem, "\n")] = '\0';

    printf("\n\n\tClasse: ");
    setbuf(stdin, NULL);
    fgets(perso->status.classe.nome_classe, 31, stdin);
    perso->status.classe.nome_classe[strcspn(perso->status.classe.nome_classe, "\n")] = '\0';

    printf("\n\n\tNivel da classe: ");
    scanf("%d", &perso->status.classe.nivel_classe);

    printf("\n\n\tArma: ");
    setbuf(stdin, NULL);
    fgets(perso->status.classe.arma, 31, stdin);
    perso->status.classe.arma[strcspn(perso->status.classe.arma, "\n")] = '\0';

    printf("\n\n\tCapacete: ");
    setbuf(stdin, NULL);
    fgets(perso->status.classe.capacete, 31, stdin);
    perso->status.classe.capacete[strcspn(perso->status.classe.capacete, "\n")] = '\0';

    printf("\n\n\tManto: ");
    setbuf(stdin, NULL);
    fgets(perso->status.classe.manto, 31, stdin);
    perso->status.classe.manto[strcspn(perso->status.classe.manto, "\n")] = '\0';

    printf("\n\n\tPeitoral: ");
    setbuf(stdin, NULL);
    fgets(perso->status.classe.peitoral, 31, stdin);
    perso->status.classe.peitoral[strcspn(perso->status.classe.peitoral, "\n")] = '\0';

    printf("\n\n\tCalca: ");
    setbuf(stdin, NULL);
    fgets(perso->status.classe.calca, 31, stdin);
    perso->status.classe.calca[strcspn(perso->status.classe.calca, "\n")] = '\0';

    printf("\n\n\tBota: ");
    setbuf(stdin, NULL);
    fgets(perso->status.classe.bota, 31, stdin);
    perso->status.classe.bota[strcspn(perso->status.classe.bota, "\n")] = '\0';

    printf("\n\n\tNivel do Personagem: ");
    scanf("%d", &perso->status.nivel_personagem);

    printf("\n\n\tReputacao: ");
    scanf("%d", &perso->status.reputacao);

    printf("\n\n\tarmadura Fisica: ");
    scanf("%f", &perso->status.armadura_fisica);

    printf("\n\n\tArmadura Magica: ");
    scanf("%f", &perso->status.armadura_magica);

    printf("\n\n\tPenetracao de armadura: ");
    scanf("%d", &perso->status.penetracao_armadura);

    printf("\n\n\tPenetracao Magica: ");
    scanf("%d", &perso->status.penetracao_magica);

    printf("\n\n\tDano Fisico: ");
    scanf("%f", &perso->status.dano_fisico);

    printf("\n\n\tDano Magico: ");
    scanf("%f", &perso->status.dano_magico);

    printf("\n\n\tChance de critico: ");
    scanf("%d", &perso->status.chance_critico);

    printf("\n\n\tVelocidade: ");
    scanf("%f", &perso->status.velocidade);
}
