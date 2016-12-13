#include "keyboard.h"
#include "conio.h"


#define UP 72
pid_t sonPid;
 char ch;
 char kill = ' ';
int main()
{
    while (1)
    {
        ch = getch();
        printf("%c",ch);
        if (ch =='\033')
        {
            getch();
            switch(getch())
            {
                case 'A':
                ;
                break;
                case 'B':
                printf(" ddown");
                break;
                case'C':
                printf(" rright");
                break;
                case'D':
                printf(" lleft");
                break;
            }
        }
        if (ch==kill)
        {
            printf("kill");
        }
    }
}
