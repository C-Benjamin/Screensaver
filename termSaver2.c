#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "conio.h"
typedef struct Pbm Pbm;
struct Pbm
{
    int height;
    int width;
    char image[100][100];

};

void placeNumbersInHourTable(int imageTable[80][24])
{
    time_t seconds;
    struct tm actualTime;
    FILE* file = NULL;
    char lineRead[71] = "";
    int caseValue;
    time(&seconds);
    actualTime=*localtime(&seconds);
    //printf("Il est actuellement %.2d:%.2d:%.2d\n", actualTime.tm_hour, actualTime.tm_min, actualTime.tm_sec);
    int hourArray[6] = {0};
    imageTable[33][9] = 1;
    imageTable[33][11] = 1;
    imageTable[45][9] = 1;
    imageTable[45][11] = 1;
    hourArray[0]=actualTime.tm_hour/10;
    hourArray[1]=actualTime.tm_hour%10;
    hourArray[2]=actualTime.tm_min/10;
    hourArray[3]=actualTime.tm_min%10;
    hourArray[4]=actualTime.tm_sec/10;
    hourArray[5]=actualTime.tm_sec%10;
    printf("\n");

    for(int i = 0; i < 6; i++)
    {
        switch(hourArray[i])
        {
        case 0:
            file = fopen("0.pbm", "r");
            for(int a =0; a< 3 ; a++)
            {
                fgets(lineRead, 71,file);
            }
            for(int z = 0; z < 5; z++)
            {
                for(int k = 0; k < 3; k++)
                {
                    fscanf(file, "%d", &caseValue);
                    imageTable[(23+i*6)+k][8+z] = caseValue;
                }
            }
            fclose(file);
            break;
        case 1:
            file = fopen("1.pbm", "r");
            for(int b =0; b< 3 ; b++)
            {
                fgets(lineRead, 71,file);
            }
            for(int z = 0; z < 5; z++)
            {
                for(int k = 0; k < 3; k++)
                {
                    fscanf(file, "%d", &caseValue);
                    imageTable[(23+i*6)+k][8+z] = caseValue;
                }
            }
            fclose(file);
            break;
        case 2:
            file = fopen("2.pbm", "r");
            for(int c =0; c< 3 ; c++)
            {
                fgets(lineRead, 71,file);
            }
            for(int z = 0; z < 5; z++)
            {
                for(int k = 0; k < 3; k++)
                {
                    fscanf(file, "%d", &caseValue);
                    imageTable[(23+i*6)+k][8+z] = caseValue;
                }
            }
            fclose(file);
            break;
        case 3:
            file = fopen("3.pbm", "r");
            for(int q =0; q< 3 ; q++)
            {
                fgets(lineRead, 71,file);
            }
            for(int z = 0; z < 5; z++)
            {
                for(int k = 0; k < 3; k++)
                {
                    fscanf(file, "%d", &caseValue);
                    imageTable[(23+i*6)+k][8+z] = caseValue;
                }
            }
            fclose(file);
            break;
        case 4:
            file = fopen("4.pbm", "r");
            for(int e =0; e< 3 ; e++)
            {
                fgets(lineRead, 71,file);
            }
            for(int z = 0; z < 5; z++)
            {
                for(int k = 0; k < 3; k++)
                {
                    fscanf(file, "%d", &caseValue);
                    imageTable[(23+i*6)+k][8+z] = caseValue;
                }
            }
            fclose(file);
            break;
        case 5:
            file = fopen("5.pbm", "r");
            for(int f =0; f< 3 ; f++)
            {
                fgets(lineRead, 71,file);
            }
            for(int z = 0; z < 5; z++)
            {
                for(int k = 0; k < 3; k++)
                {
                    fscanf(file, "%d", &caseValue);
                    imageTable[(23+i*6)+k][8+z] = caseValue;
                }
            }
            fclose(file);
            break;
        case 6:
            file = fopen("6.pbm", "r");
            for(int g =0; g< 3 ; g++)
            {
                fgets(lineRead, 71,file);
            }
            for(int z = 0; z < 5; z++)
            {
                for(int k = 0; k < 3; k++)
                {
                    fscanf(file, "%d", &caseValue);
                    imageTable[(23+i*6)+k][8+z] = caseValue;
                }
            }
            fclose(file);
            break;
        case 7:
            file = fopen("7.pbm", "r");
            for(int h =0; h< 3 ; h++)
            {
                fgets(lineRead, 71,file);
            }
            for(int z = 0; z < 5; z++)
            {
                for(int k = 0; k < 3; k++)
                {
                    fscanf(file, "%d", &caseValue);
                    imageTable[(23+i*6)+k][8+z] = caseValue;
                }
            }
            fclose(file);
            break;
        case 8:
            file = fopen("8.pbm", "r");
            for(int l =0; l< 3 ; l++)
            {
                fgets(lineRead, 71,file);
            }
            for(int z = 0; z < 5; z++)
            {
                for(int k = 0; k < 3; k++)
                {
                    fscanf(file, "%d", &caseValue);
                    imageTable[(23+i*6)+k][8+z] = caseValue;
                }
            }
            fclose(file);
            break;
        case 9:
            file = fopen("9.pbm", "r");
            for(int m =0; m< 3 ; m++)
            {
                fgets(lineRead, 71,file);
            }
            for(int z = 0; z < 5; z++)
            {
                for(int k = 0; k < 3; k++)
                {
                    fscanf(file, "%d", &caseValue);
                    imageTable[(23+i*6)+k][8+z] = caseValue;
                }
            }
            fclose(file);
            break;
        default:
            exit(2);
            break;
        }

    }
}

void displayImageTable(int imageTable[80][24])
{
	char c[] = {226, 150, 136, 0};

    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 80; j++)
        {
            if(imageTable[j][i] == 0)
            {
                printf(" ");
            }
            else
            {
                printf("%s", c);
            }
        }
        printf("\n");
    }
    printf("\n");
}

int main()
{
    char ch;
    char kill = ' ';
    int sleepTime = 10;
    sleepTime = atoi(getenv("EXIASAVER2_SLEEP"));
    char* test = "oui";
    test = getenv("EXIASAVER2_PBM");
    //printf("%s",test);
    int imageTable[80][24] = {0};
    Pbm image;
    Pbm hour;
    image.height = 5;
    image.width = 39;
    hour.height = 5;
    hour.width = 3;
    while(1)
    {
        system("clear");
        placeNumbersInHourTable(imageTable);
        displayImageTable(imageTable);
        for(int i = 0; i < 22; i++) printf(" ");
        printf("Actualisation toutes les %d secondes ",sleepTime);
        fflush(stdout);
        for (int i = 0; i<sleepTime; i++)
        {
            sleep(1);
            printf(". ");
            fflush(stdout);
        }
        //ch = getch();
        if(ch==kill)
        {
            exit(1);
        }
    }
    return 0;
}
