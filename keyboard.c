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
        if (ch =='\033')
        {
            getch();
            switch(getch())
            {
                case 'A':
                ch2[0] = 'a';
                send(ch2);
                break;
                case 'B':
                ch2[0] = 'b';
                send(ch2);
                break;
                case'C':
                ch2[0] = 'c';
                send(ch2);
                break;
                case'D':
                ch2[0] = 'd';
                send(ch2);
                break;
            }
        }

    }
}
