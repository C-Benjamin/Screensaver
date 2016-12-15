#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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


int main()
{

History history;
history.screenlaunched = 2;
time_t seconde;
time(&seconde);

history.instant=*localtime(&seconde);


    FILE* file = NULL;

    file = fopen("test.txt","a");

    if (file != NULL)
    {
        fprintf(file,"%d/%d/%d  %d:%d:%d      ",history.instant.tm_mday,history.instant.tm_mon+1,history.instant.tm_year+1900,
                history.instant.tm_hour,history.instant.tm_min,history.instant.tm_sec);

        if (history.screenlaunched == 1)
    {
        fprintf(file,"Type statique ");
        fprintf(file,"%d",history.displayedImage);
    }
    else if (history.screenlaunched == 2)
    {
        fprintf(file,"Type dynamique  ");
        fprintf(file,"%d   ",history.height);
        fprintf(file,"%d",history.height);
    }
    else if (history.screenlaunched ==3)
    {
        fprintf(file,"Type interactif  ");
        fprintf(file,"%d X %d",history.xpos, history.ypos);
    }

        fclose(file);


    }

    else if(

    printf("ERROR")

    )



return 0;



}
