#include <time.h>
#include <stdio.h>
#include <stdlib.h>


typedef struct History History;
struct History
{
    struct tm instant;
    int screenlaunched;
    int displayedImage;
    int height;
    int weidht;
    int xpos;
    int ypos;
};

//void fillHistory(history);
//void displayHistory(history);

void fillHistory(History history)
{

}

void displayHistory(History history)
{
    printf("%d/%d/%d %d:%d:%d",history.instant.tm_yday,history.instant.tm_mon,history.instant.tm_year
           ,history.instant.tm_hour,history.instant.tm_min,history.instant.tm_sec);

    if (history.screenlaunched == 1)
    {
        printf("Type statique\n");
        printf("%d",history.displayedImage);
    }
    else if (history.screenlaunched == 2)
    {
        printf("Type dynamique");
        printf("%d",history.height);
        printf("%d\n",history.height);
    }
    else if (history.screenlaunched ==3)
    {
        printf("Type interactif\n");
        printf("%d X %d",history.xpos, history.ypos);
    }
}

int main(void)
{
    int screenlauched = 1;
    History history;
    fillHistory(history);
    displayHistory(history);


    return 0;
}






