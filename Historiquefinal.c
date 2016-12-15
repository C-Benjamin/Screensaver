
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct History History;
struct History
{
    int screenlaunched;
    int  ch;
    int  aff;
    int taille;
    char * tab[100][50];
    int  nbr;
};
//////////////////////////////////////////////////////////////////
void Tri1(History *history)
{
    int tabidate = 0;


    int j = 0;
    char* temp [50];
    printf("\n");
    while (tabidate == 0)
    {
        tabidate = 1;
        for(j = 0;j < history->taille-1;j++)
        {
            if(j < j+1)
            {
                strcpy(temp,history->tab[j+1]);
                strcpy(history->tab[j+1],history->tab[j]);
                strcpy(history->tab[j],temp);

                 tabidate = 0;
           }
        }
        history->taille--;
    }
    int n;
    printf("\n");
    for(n = 0;n < history->aff;n++)
    {
         printf("%s",history->tab[n]);
    }
}
///////////////////////////////////////////////////////////////////
void Tri2(History *history)
{
    int n;
     printf("\n");
 for(n = 0;n < history->ch;n++)
 {
    if ((strstr(history->tab[n],"statique")) != NULL)
    {
         printf("%s",history->tab[n]);
    }
  }
  for(n = 0;n < history->ch;n++)
  {
    if ((strstr(history->tab[n],"dynamique")) != NULL)
    {
         printf("%s",history->tab[n]);
    }
  }
  for(n = 0;n < history->ch;n++)
  {
    if ((strstr(history->tab[n],"interactif")) != NULL)
    {
         printf("%s",history->tab[n]);
    }
  }
}

///////////////////////////////////////////////////////////////////
void affichage(History *history){


char* text;
char testl[50] = "";
FILE* file = NULL;
file = fopen("test.txt","r");
int c;
int n = 0;

    if (file != NULL){

      while ((c=fgetc(file)) != EOF)
      {

        text = fgets(testl,50,file);
        strcpy(history->tab[n],text);
        printf("%s",history->tab[n]);
        n++;
     }
     history->aff = n;
     history->ch = n;
     history->taille = n;
     history->nbr = n;
 
}
////////////////////////////////////////////////////////////////
void Stat(History *history)
{
int st=0;
int dy=0;
int in=0;
 printf("Stats:\n");
 printf("Nombre d'historique: %d\n",history->nbr);
  int n;
     printf("\n");
 for(n = 0;n < history->ch;n++)
 {
    if ((strstr(history->tab[n],"statique")) != NULL)
    {

         st++;
    }
  }
  for(n = 0;n < history->ch;n++)
  {
    if ((strstr(history->tab[n],"dynamique")) != NULL)
    {

         dy++;
    }
  }
  for(n = 0;n < history->ch;n++)
  {
    if ((strstr(history->tab[n],"interactif")) != NULL)
    {

        in++;
    }
  }

 printf("Type statique : %d\n",st);
 printf("Type dynamique : %d\n",dy);
 printf("Type interactif : %d\n",in);
}


void main()
{
    History history;
    affichage(&history);
    int choix = 0;

    printf("\n");
    printf("Tapez 1 pour un tri décroissant\n"
            "Tapez 2 pour un tri par type \n"
            "Tapez 3 pour afficher les stats de l'historique\n");


    scanf("Choix : %d",&choix);
    system("clear");

    if (choix == 1)
    {
        Tri1(&history);
        printf("\nFait");
    }

    else if (choix == 2)
    {
        Tri2(&history);
        printf("\nFait");
    }

    else if (choix == 3)
    {
       Stat(&history);
    }


}



