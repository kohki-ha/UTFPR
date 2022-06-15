#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"

void menu(Personagem *personagens)
{
    int opcao;

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
        scanf("%d", &opcao);

        if (opcao == 1)
            criar_personagem(personagens);
        else if (opcao == 2)
            editar_personagem(personagens);
        else if (opcao == 3)
            listar_personagem(personagens);
        else if (opcao == 4)
            excluir_personagem(personagens);
        else if (opcao == 5)
            pesquisar_personagem(personagens);
        else if (opcao == 6)
            exportar_personagem(personagens);
        else if (opcao == 0)
            break;
        else
            printf("\n\n\tOpcao invalida!!!\n");
    }
}

void cirar_personagem(Personagem *personagens)
{
    for (size_t i = 0; i < 10; i++)
    {
        printf("\n\n\tNome do personagem: ");
        setbuf(stdin, NULL);
        fgets(personagens[i].nick_name, MAX, stdin);
        personagens[i].nick_name[strcspn(personagens[i].nick_name, "\n")] = '\0';

        printf("\n\n\tIdade: ");
        scanf("%d", &personagens[i].idade);

        printf("\n\n\tGenero: ");
        printf("1 - Masculino\n2 - Feminino");
        scanf("%d", &personagens[i].idade);

        printf("\n\n\tAltura: ");
        scanf("%d", &personagens[i].altura);

        printf("\n\n\tRaça: ");
        setbuf(stdin, NULL);
        fgets(personagens[i].raca, MAX, stdin);
        personagens[i].raca[strcspn(personagens[i].raca, "\n")] = '\0';

        printf("\n\n\tHistória do personagem: ");
        setbuf(stdin, NULL);
        fgets(personagens[i].historia_personagem, 700, stdin);
        personagens[i].historia_personagem[strcspn(personagens[i].historia_personagem, "\n")] = '\0';

        printf("\n\n\tClasse: ");
        setbuf(stdin, NULL);
        fgets(personagens[i].status.classe.nome_classe, MAX, stdin);
        personagens[i].status.classe.nome_classe[strcspn(personagens[i].status.classe.nome_classe, "\n")] = '\0';

        printf("\n\n\tNivel da classe: ");
        scanf("%d", &personagens[i].status.classe.nivel_classe);

        printf("\n\n\tClasse: ");
        setbuf(stdin, NULL);
        fgets(personagens[i].status.classe.arma, MAX, stdin);

        printf("\n\n\tNome da classe: ");
        setbuf(stdin, NULL);
        fgets(personagens[i].status.classe.nome_classe, MAX, stdin);
        personagens[i].status.classe.nome_classe[strcspn(personagens[i].status.classe.nome_classe, "\n")] = '\0';

        printf("\n\n\tArma: ");
        setbuf(stdin, NULL);
        fgets(personagens[i].status.classe.arma, MAX, stdin);
        personagens[i].status.classe.arma[strcspn(personagens[i].status.classe.arma, "\n")] = '\0';

        printf("\n\n\tCapacete: ");
        setbuf(stdin, NULL);
        fgets(personagens[i].status.classe.capacete, MAX, stdin);
        personagens[i].status.classe.capacete[strcspn(personagens[i].status.classe.capacete, "\n")] = '\0';

        printf("\n\n\tManto: ");
        setbuf(stdin, NULL);
        fgets(personagens[i].status.classe.manto, MAX, stdin);
        personagens[i].status.classe.manto[strcspn(personagens[i].status.classe.manto, "\n")] = '\0';

        printf("\n\n\tPeitoral: ");
        setbuf(stdin, NULL);
        fgets(personagens[i].status.classe.peitoral, MAX, stdin);
        personagens[i].status.classe.peitoral[strcspn(personagens[i].status.classe.peitoral, "\n")] = '\0';

        printf("\n\n\tCalça: ");
        setbuf(stdin, NULL);
        fgets(personagens[i].status.classe.calca, MAX, stdin);
        personagens[i].status.classe.calca[strcspn(personagens[i].status.classe.calca, "\n")] = '\0';

        printf("\n\n\tBota: ");
        setbuf(stdin, NULL);
        fgets(personagens[i].status.classe.bota, MAX, stdin);
        personagens[i].status.classe.bota[strcspn(personagens[i].status.classe.bota, "\n")] = '\0';
    }
}

void editar_personagem(Personagem *personagens)
{
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
