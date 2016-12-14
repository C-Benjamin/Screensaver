#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct History History;
struct History
{
    int screenlaunched;
    int ch;
    int aff;
    int taille;
    char* tab[100][50];
};

/*void Tri1(History history)
{
    int tabidate = 0;


    int j = 0;
    char* temp [50];
    printf("\n");
    while (tabidate == 0)
    {
        tabidate = 1;
        for(j = 0;j < history.taille-1;j++)
        {
            if(j < j+1)
            {
                strcpy(temp,history.tab[j+1]);
                strcpy(history.tab[j+1],history.tab[j]);
                strcpy(history.tab[j],temp);

                 tabidate = 0;
           }
        }
        history.taille--;
    }
    int n;
    printf("\n");
    for(n = 0;n < history.aff;n++)
    {
         printf("%s",history.tab[n]);
    }
}

void Tri2(History history)
{
    int n;
     printf("\n");
 for(n = 0;n < history.ch;n++)
 {
    if ((strstr(history.tab[n],"statique")) != NULL)
    {
         printf("%s",history.tab[n]);
    }
  }
  for(n = 0;n < history.ch;n++)
  {
    if ((strstr(history.tab[n],"dynamique")) != NULL)
    {
         printf("%s",history.tab[n]);
    }
  }
  for(n = 0;n < history.ch;n++)
  {
    if ((strstr(history.tab[n],"interactif")) != NULL)
    {
         printf("%s",history.tab[n]);
    }
  }
}
*/

void affichage(History history){
char* tab[100][50];
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
        strcpy(tab[n],text);
        printf("%s",tab[n]);
        n++;
     }
     history.aff = n;
     history.ch = n;
     history.taille = n;

 ////////////////////////////////////////////////
   int tabidate = 0;
    history.taille = n;

    int j = 0;
    char* temp [50];
    printf("\n");
    while (tabidate == 0)
    {
        tabidate = 1;
        for(j = 0;j < history.taille-1;j++)
        {
            if(j < j+1)
            {
                strcpy(temp,tab[j+1]);
                strcpy(tab[j+1],tab[j]);
                strcpy(tab[j],temp);

                 tabidate = 0;
           }
        }
        history.taille--;
    }
    n = 0;
    printf("\n");
    for(n = 0;n < history.aff;n++)
    {
         printf("%s",tab[n]);
    }
///////////////////////////////////////////////////
 printf("\n");
 for(n = 0;n < history.ch;n++)
 {
    if ((strstr(tab[n],"statique")) != NULL)
    {
         printf("%s",tab[n]);
    }
  }
  for(n = 0;n < history.ch;n++)
  {
    if ((strstr(tab[n],"dynamique")) != NULL)
    {
         printf("%s",tab[n]);
    }
  }
  for(n = 0;n < history.ch;n++)
  {
    if ((strstr(tab[n],"interactif")) != NULL)
    {
         printf("%s",tab[n]);
    }
  }
//////////////////////////////////////////////////////



 }
fclose(file);

}



void main()
{
    History history;
    affichage(history);
    int choix = 0;
  /*  printf("Quels tris voulez-vous faire ?\n");
   // while(choix!=1&&choix!=2)
    //{
    scanf("%d",&choix);
   // }
    if (choix == 1)
    {
        Tri1(history);
        printf("\nFait");
    }

    else if (choix == 2)
    {
        Tri2(history);
        printf("\nFait");
    }

    else
    {
        printf("ERROR");
    }
    */

}



