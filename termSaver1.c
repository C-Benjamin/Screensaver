#include <stdio.h>
#include <stdlib.h>

#include "keyboard.h"
#include "keyboard.c"
#include "PBM.h"
#include "PBM.c"
#include "display.h"
#include "display.c"

void initialiseBackground(Background *background)
{

}

void getRandomStaticImage(char* *imageName)
{

}

int main()
{
    Background background;
    char* imageName = "";
    initialiseBackground(&background);
    getRandomStaticImage(&imageName);
    fillGridWithImage(&background.grid, imageName);
    displayBackground(background);
    return 0;
}

