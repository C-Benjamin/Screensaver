#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
//#include "keyboard.h"
//#include "keyboard.c"
#include "PBM.h"
#include "conio.h"
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
    printf("%s\n",lineRead);
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
    char lineRead[20] = "";

    for(int i = 0; i < 2; i++)
    {
        fgets(lineRead, 20, file);
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

Pbm manipulationFile(char* arguments)
{
    Pbm image;
    strcpy(image.imageName, arguments);
    //int tableauPourImage[80][24] = {0};

    FILE* file = NULL;

    char path[1024];
    char* str = getenv("EXIASAVER1_PBM");
    if(str != NULL) strcpy(path, str);
    else getcwd(path, 1024);

    strcat(path, image.imageName);
    return image;
    /*
    file = fopen(path, "r");

    if(file != NULL)
    {
        lireResolution(file, &image); // cette fonction va permettre de stocker la rÈsoltion de l'image PBM
        insererImageCentreeDansTableau(file, &image, tableauPourImage);
        fclose(file); // aprËs avoir fini de manipuler le file, il faut fermer le file pour libÈrer la mÈmoire vive
    }
    else // permet de savoir si le file ne s'est pas ouvert
    {
        printf("File can't be opened");
    }
    afficherTableau(tableauPourImage);// on va afficher le tableau ‡ deux dimensions qui contient le code de l'image PBM, on va afficher un "X" quand la valeur est 0 et un " " quand la valeur est 1
    quiterProgrammeAvecEspace();*/
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

    FILE* file = NULL;
    char* arguments = {//argv[1];
    image = manipulationFile(arguments);
    //printf("%s",argv[1]);
    strcpy(image.imageName, "city.pbm");
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

