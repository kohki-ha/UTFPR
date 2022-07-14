#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char cidades[5][21];
    int servidores[5][3];
    char busca[21];
    int achou = 0;
    float maiorPorentual = 0; //maior percentual
    float porcentualAtual;
    int posicao = 0;
    int somaAtivos = 0;
    int somaFalha = 0;
    int somaTotal = 0;

    //item "a"
    for (size_t i = 0; i < 5; i++)
    {
        printf("Digite o nome da cidades: ");
        fgets(cidades[i], 20, stdin);
        setbuf(stdin, NULL);

        printf("Digite o numero de servidores ativos: ");
        scanf("%i", &servidores[i][0]);
        setbuf(stdin, NULL);

        printf("Digito o numero de ervidores com falha:");
        scanf("%i", &servidores[i][1]);
        setbuf(stdin, NULL);
    }

    //item "b"
    for (size_t i = 0; i < 5; i++)
    {
        servidores[i][2] = servidores[i][0] + servidores[i][0];
    }
    

    //item c
    printf("|%-20s | %3s | %3s | %3s | \n", 
           "CIDADES", " A ", " F ", " T ");

    for (size_t i = 0; i < 5; i++)
    {
        printf("|%-20s | %3d | %3d | %3d |\n",
               cidades[i], 
               servidores[i][0], 
               servidores[i][1],
               servidores[i][2]);
    }
    
    //item d
    printf("Digite a cidade para buscar: ");
    fgets(busca, 20, stdin);
    busca[strcspn(busca, "\n")] = '\0';

    for (size_t i = 0; i < 5; i++)
    {
        if(strcmp(busca, cidades[i]) == 0)
            achou++;
            printf("|%-20s | %3d | %3d | %3d |\n",
               cidades[i], 
               servidores[i][0], 
               servidores[i][1],
               servidores[i][2]);
    }
    
    if(achou == 0)
        printf("Cidade nao encontrada");

    //item e
    maiorPorentual = (float) servidores[0][1]/servidores[0][2];

    for (size_t i = 0; i < 5; i++)
    {
        porcentualAtual = (float) servidores[0][1]/servidores[0][2];

        if(porcentualAtual > maiorPorentual){
            maiorPorentual = porcentualAtual;
            posicao = i;
        }
    }
    printf("A maior eh de %.2f%%\n", maiorPorentual*100);
    printf("Ocorreu na cidade de %s\n", cidades[posicao]);
    
    //item f
    for (size_t i = 0; i < 5; i++)
    {
        somaAtivos += servidores[i][0];
        somaFalha += servidores[i][1];
        somaTotal += servidores[i][2];
    }
    printf("Porcentual de ativos: %.1f%%\n", (float) somaAtivos/somaTotal*100);
    printf("Porcentual de falhas: %.1f%%\n", (float) somaFalha/somaTotal*100);

    //item g
    for (size_t i = 0; i < 5; i++)
    {
        if(servidores[i][0] < servidores[i][1]){
            strcat(cidades[i], " Defeated");
        }
    }
    


    return 0;
}
