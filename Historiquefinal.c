
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct History History;
struct History // Cette structure permet de récuperer des information de la première fonction pour celles qui suivent
{
    int screenlaunched;
    int  ch;
    int  aff;
    int taille;
    char * tab[100][50];
    int  nbr;
};

void Tri1(History *history)// Fontion qui permet le tri de la date la plus ancienne à la date la plus recent
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
            {   // Permet l'inversion des termes du tableau lorsque le teste est réeussi
                strcpy(temp,history->tab[j+1]);
                strcpy(history->tab[j+1],history->tab[j]);
                strcpy(history->tab[j],temp);

                 tabidate = 0;
           }
        }
        history->taille--; //Récuperation de la taille grâce à la variable de la première fonction
    }
    int n;
    printf("\n");
    for(n = 0;n < history->aff;n++)
    {
         printf("%s",history->tab[n]); // Affiche le nouvelle ordre 
    }
}

void Tri2(History *history)// Permet un tri par type
{
    int n;
     printf("\n");
 for(n = 0;n < history->ch;n++)
 {
    if ((strstr(history->tab[n],"statique")) != NULL) // Teste si le type "statique" est dans la chaine de charactère
    {
         printf("%s",history->tab[n]);// Si oui, l'affiche
    }
  }
  for(n = 0;n < history->ch;n++)
  {
    if ((strstr(history->tab[n],"dynamique")) != NULL)// Pareil pour "dynamique"
    {
         printf("%s",history->tab[n]);
    }
  }
  for(n = 0;n < history->ch;n++)
  {
    if ((strstr(history->tab[n],"interactif")) != NULL)// Pareil pour "interactif"
    {
         printf("%s",history->tab[n]);
    }
  }
}

void affichage(History *history){
//Lis le fichier .txt et récupère l'historique en l'enregistrant dans un tableau

char* text;
char testl[50] = "";
FILE* file = NULL;
file = fopen("test.txt","r");
int c;
int n = 0; // Variable importante qui permettra de déterminer le nombre de ligne max écrites sur le .txt

    if (file != NULL){

      while ((c=fgetc(file)) != EOF)
      {

        text = fgets(testl,50,file);
        strcpy(history->tab[n],text);// Transfert la chaine de charactère du .txt dans le tableau
        printf("%s",history->tab[n]);
        n++;
     }
     history->aff = n;
     history->ch = n;        // On récupère la variable n qui a alors le nombre max de ligne et transfert sa valeur à d'autre variable pour les autres fonction
     history->taille = n;
     history->nbr = n;
 
}

void Stat(History *history)// Permettra de calculer des stats en récupérant des informaton grâce à d'autre fonction ou les calculant dans cette même fonction
{
int st=0;
int dy=0;
int in=0;
 printf("Stats:\n");
 printf("Nombre d'historique: %d\n",history->nbr);
  int n;
     printf("\n");
 for(n = 0;n < history->ch;n++)// Ici, on fait comme pour afficher par types mais on ingrémente une variable à la place
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
 printf("Type dynamique : %d\n",dy);  //Affiche les stats
 printf("Type interactif : %d\n",in);
}


void main()
{
    History history;
    affichage(&history);// Affiche l'historique
    int choix = 0;

    printf("\n");
    printf("Tapez 1 pour un tri décroissant\n"
            "Tapez 2 pour un tri par type \n"       // Permet un choix entre les différents tri et les stats
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



