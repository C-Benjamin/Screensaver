#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include "PBM.h"
#include "conio.h"


void putImageInTable(FILE *file, Pbm* image, int imageTable[80][24])
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

void getImageScale(FILE *file, Pbm* p)
{
    char lineRead[30] = "";

    for(int i = 0; i < 2; i++)
    {
        fgets(lineRead, 30, file);

    }
    fscanf(file, "%d %d", &p->width, &p->height);
}

void displayImageTable(int imageTable[80][24])
{
	char c[] = {226, 150, 136, 0};

    for (int i = 0 ;i < 22; i++)
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

int main(int argc, char *argv[])
{
    /*if(argc != 2)
    {
        printf("Invalid arguments\n");
        return -1;
    }*/

    Pbm image;
    int imageTable[80][24] = {0};
    char* arguments = argv[1];
    printf("%s+",arguments);
    strcpy(image.imageName, arguments);

    FILE* file = NULL;

    char path[1024];
    char* str = getenv("EXIASAVER1_PBM");
    if(str != NULL) strcpy(path, str);
    else getcwd(path, 1024);
    printf("Path:%s\n",path);
    strcat(path,image.imageName);

    //strcpy(image.imageName, "tree.bpm");
    //printf("%s",argv[1]);
    //strcpy(image.imageName, "city.pbm");
    printf("Imgname:%s\n",image.imageName);

    file = fopen(image.imageName, "r");
    if(file != NULL)
    {
        getImageScale(file, &image);
        putImageInTable(file, &image, imageTable);
        fclose(file);
    }
    displayImageTable(imageTable);
    while(1){
        char ch;
        char kill = ' ';
        ch = getch();
        if(ch==kill)
        {
            exit(1);
        }
    }
    return 0;
}

