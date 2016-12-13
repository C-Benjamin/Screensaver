#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
//#include "keyboard.h"
//#include "keyboard.c"
#include "PBM.h"
//#include "PBM.c"
//#include "display.h"
//#include "display.c"

void putImageInTable(char *file, Pbm* image, int imageTable[80][24])
{
    char lineRead[71] = "";
    int caseValue;

    fgets(lineRead, 71, file);

    while (fgets(lineRead, 71, file) != NULL)
    {
        for(int z = 0; z < image->height; z++)
        {
            for(int k = 0; k < image->width; k++)
            {
                fscanf(file, "%d", &caseValue);
                imageTable[k + ((80 - image->width)/2)][z + ((24 - image->height)/2)] = caseValue;
            }
        }
    }
}

void getImageScale(char *file, Pbm* p)
{
    char lineRead[71] = "";

    for(int i = 0; i < 2; i++)
    {
        fgets(lineRead, 71, file);
    }
    fscanf(file, "%d %d", &p->width, &p->height);
}

void displayImageTable(int imageTable[80][24])
{
	char c[] = {226, 150, 136, 0};

    for (int i = 0 ;i < 24; i++)
    {
        for (int j = 0;j < 80; j++)
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
    Pbm image;
    int imageTable[80][24] = {0};

    FILE* file = NULL;
    strcpy(image.imageName, "tree.pbm");
    file = fopen(image.imageName, "r");
    if(file != NULL)
    {
        getImageScale(file, &image);
        putImageInTable(file, &image, imageTable);
        fclose(file);
    }
    displayImageTable(imageTable);
    return 0;
}

