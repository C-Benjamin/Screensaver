#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "keyboard.h"
#include "keyboard.c"

typedef struct Plane Plane;
struct Plane
{
    int direction;
    int xpos;
    int ypos;
    int planeImage[6][6];
};

void randomScreenChoice(char* *randomScreensaver)
{

}

void getActualTime(struct tm *actualTime)
{

}

int randomStaticImageChoice(int nbAvailableImages)
{
    int staticImageChoice = 0;

    return staticImageChoice;
}

void initialisePlane(Plane *plane)
{

}

void fillHistory(struct tm actualTime, char* randomScreensaver, int randomStaticImage, Plane plane)
{

}

void launchProg(char* randomScreensaver, int randomStaticImage, Plane plane)
{

}

int main()
{
    struct tm actualTime;
    char* randomScreensaver = "";
    int randomStaticImage = 0;
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
    getActualTime(&actualTime);
    fillHistory(actualTime, randomScreensaver, randomStaticImage, plane);
    launchProg(randomScreensaver, randomStaticImage, plane);

    return 0;
}
