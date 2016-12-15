#include "conio.h"
#include "pipe.h"
#include "pipe.c"
#define MAX_CTRLS 2

 char ch2[MAX_CTRLS];
 char ch;
int main()
{
    while (1)
    {

        ch = getch();
        if (ch =='\033')// l'information que renvoie les flèche est tout d'abord \033 puis [ et enfin une information uniques pour chaque flèche comme A pour la flèche du haut
        {
            getch();
            switch(getch())
            {
                case 'A': // Cas de la flèche haut
                ch2[0] = 'a';
                send(ch2);// Envoie l'information grâce au pipe
                break;
                case 'B':// Cas de la flèche bas
                ch2[0] = 'b';
                send(ch2);
                break;
                case'C':// Cas de la flèche gauche
                ch2[0] = 'c';
                send(ch2);
                break;
                case'D':// Cas de la flèche droite
                ch2[0] = 'd';
                send(ch2);
                break;
            }
        }

    }
}
