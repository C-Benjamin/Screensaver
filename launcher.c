#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <time.h>

//#include "keyboard.h"
//#include "keyboard.c"


typedef struct Plane Plane;
struct Plane
{
    int direction;
    int xpos;
    int ypos;
    int planeImage[6][6];
};


void randomScreenChoice(char**randomScreensaver)
{
    srand(time(NULL));
    int random = rand();
    random = random %3;
    switch(random)
    {
    case 0:
        *randomScreensaver = "termSaver1";
        break;
    case 1:
        *randomScreensaver = "termSaver2";
        break;
    case 2:
        *randomScreensaver = "termSaver3";
        break;
    default:
        printf("Error in randomScreenChoice");
        break;
    }
}

void getActualTime(struct tm **actualTime)
{
    time_t seconds;
    time(&seconds);
    *actualTime = localtime(&seconds);
}

char* randomStaticImageChoice(int nbAvailableImages)
{
    char* staticImageChoice;
    srand(time(NULL));
    int random = rand();
    random = random %nbAvailableImages;
    switch(random)
    {
    case 0:
        staticImageChoice = "city.pbm";
        break;
    case 1:
        staticImageChoice = "island.pbm";
        break;
    case 2:
        staticImageChoice = "tree.pbm";
        break;
    case 3:
        staticImageChoice = "STP.pbm";
        break;
    default:
        printf("Error in randomStaticImageChoice");
        break;
    }

    return staticImageChoice;
}

void initialisePlane(Plane *plane)
{
    srand(time(NULL));
    int random1 = rand();
    srand(time(NULL));
    int random2 = rand();
    srand(time(NULL));
    int random3 = rand();
    random1 = random1 %4;
    plane->direction = random1;
    random2 = random2 %84;
    plane->xpos = random2;
    random3 = random3 %23;
    plane->ypos = random3;
}

void fillHistory(struct tm **actualTime, char* randomScreensaver, char* randomStaticImage, Plane plane)

}


void launchProg(char* randomScreensaver, char* randomStaticImage, Plane plane)
{
    pid_t child_pid;
    int status;

    if((child_pid = fork()) < 0 )
    {
        perror("fork failure");
        exit(1);
    }

    if(child_pid == 0)
    {
        execl(randomScreensaver,"",NULL);
        perror("execl failure");
        _exit(1);
    }

    else
    {
        if (randomScreensaver == "termSaver1")
        {
            //transmit the image to display by fifo
        }
        else if (randomScreensaver == "termSaver3")
        {
            //transmit the random plane placement by fifo
        }
        execl("keyboard","",NULL);
        wait(&status);
    }
}



int main(int argc, char *argv[])
{
    struct tm *actualTime;
    char* randomScreensaver = "termSaver3";
    char* randomStaticImage = "city.pbm";
    int nbAvailableImages = 4;
    Plane plane;

    randomScreenChoice(&randomScreensaver);
    if (randomScreensaver == "termSaver1")
    {
        randomStaticImage = randomStaticImageChoice(nbAvailableImages);
    }
    else if (randomScreensaver == "termSaver3")
    {
        initialisePlane(&plane);
    }


    if(argc == 2)
    {
        if(strcmp(argv[1],"-stats")==0)
        {
            execl("history","",NULL);
        }
    }
    else
    {
        launchProg(randomScreensaver, randomStaticImage, plane);
    }
  
    getActualTime(&actualTime);
    fillHistory(actualTime, randomScreensaver, randomStaticImage, plane);
    launchProg(randomScreensaver, randomStaticImage, plane);


    return 0;
}
