#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {

  char pais[20];
  char cidade[20];
  int servidores_up;
  int servidores_down;
}Not;

int main(int argc, char const *argv[]) {

  Not* not;
  Not* not2;
  int tam = 5;
  int op;
  int aux = 0;
  int cont = 0;
  int porcent;
  char barra = '|';
  char linha = '\n';

  not = malloc(tam*sizeof(Not));

  FILE* arq = fopen("notifications.dat","wb");
  if (arq == NULL) {
    printf("Não foi posivel abrir o arquivo\n" );
    exit(1);
  }
  while (1) {
    for (size_t i = 0; i < tam; i++) {

      printf("Pais: \n");
      setbuf(stdin,NULL);
      fgets(not[i].pais, 20, stdin);
      not[i].pais[strcspn(not[i].pais,"\n")]='\0';
      setbuf(stdin,NULL);

      printf("%s\n\n",not[i].pais );

      if (strcmp(not[i].pais,"sair") == 0) {
        aux=1;
        break;
      }
      cont++;

      printf("Cidade: \n");
      fgets(not[i].cidade, 20, stdin);
      not[i].cidade[strcspn(not[i].cidade,"\n")]='\0';
      setbuf(stdin,NULL);

      printf("Servidores up: \n");
      scanf("%d",&not[i].servidores_up );

      printf("Servidores down: \n");
      scanf("%d",&not[i].servidores_down);
      if (i == (tam-1)) {
        not = realloc(not,(tam+5)*sizeof(Not));
      }
      fwrite(not[i].pais,sizeof(char),20,arq);
      fwrite(not[i].cidade,sizeof(char),20,arq);
      fwrite(not[i].servidores_up,sizeof(int),1,arq);
      fwrite(not[i].servidores_down,sizeof(int),1,arq);
    }
    if (aux == 1 ) {
      break;
      fclose(arq);
    }
  }
  not2 = malloc(cont*sizeof(Not));
  FILE* arq = fopen("notifications.dat","wb");
  if (arq == NULL) {
    printf("Não foi posivel abrir o arquivo\n" );
    exit(1);
  }
  for (size_t i = 0; i < cont; i++) {
    fread(not2[i].pais,sizeof(char),20,arq);
    fread(not2[i].cidade,sizeof(char),20,arq);
    fread(not2[i].servidores_up,sizeof(int),1,arq);
    fread(not2[i].servidores_down,sizeof(int),1,arq);
    printf("Pais   |  Cidade  |  Servs up  |  Servs down \n  %s    |  %s  |  %d  |  %d  \n",not2[i].pais,not2[i].cidade,not2[i].servidores_up,not2[i].servidores_down);
  }
  for (size_t i = 0; i < cont; i++) {
    porcent = (((not2[i].servidores_up+not2[i].servidores_down)-not2[i].servidores_down)/(not2[i].servidores_up+not2[i].servidores_down))*100;
    printf("Pais   |  Servs up  |  Servs down  | Rate \n  %s   |  %d  |  %d  |  %d  \n",not2[i].pais,not2[i].servidores_up,not2[i].servidores_down,porcent);
    fputs(not2[i].pais, "arq.txt");
    fputc(barra, "arq.txt");
    fputs(not2[i].servidores_up, "arq.txt");
    fputc(barra, "arq.txt");
    fputs(not2[i].servidores_down, "arq.txt");
    fputc(barra, "arq.txt");
    fputc(porcent, "arq.txt");
    fputc(linha, "arq.txt");
  }


  return 0;
}
