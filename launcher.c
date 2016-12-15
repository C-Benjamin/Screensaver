#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <dirent.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/ioctl.h>


typedef struct Plane Plane;
struct Plane
{
    int direction;
    int xpos;
    int ypos;
    int planeImage[6][6];
};

char* randomScreenChoice(char* randomScreensaver)
{
    int random = randomChoice(0, 2);
    //printf("%d",random);
    //srand(time(NULL));
    //random = rand()%2;
    switch(random)
    {
    case 0:
        randomScreensaver = "termSaver1";
        break;
    case 1:
        randomScreensaver = "termSaver2";
        break;/*
    case 2:
        *randomScreensaver = "termSaver3";
        break;*/
    default:
        printf("Error in randomScreenChoice");
        break;
    }
    return randomScreensaver;
}

void getActualTime(struct tm **actualTime)
{
    time_t seconds;
    time(&seconds);
    *actualTime = localtime(&seconds);
}

int randomChoice(int min, int max)             // Random permettant de choisir un programme aléatoirement
{
    int random1;
    srand(time(NULL));
    random1 = rand()%(max - min) + min;
    return random1;
}

char* randomStaticImageChoice()
{
    char pbm_repertory[1024];
    char* str = getenv("EXIASAVER1_PBM");
    if(str != NULL)
    {
        strcpy(pbm_repertory, str);
    }
    else
    {
        getcwd(pbm_repertory, 1024);
    }
    DIR* rep = opendir(pbm_repertory);
    if(rep != NULL)
    {
        struct dirent * ent;
        int compteur = 0;
        while((ent = readdir(rep)) != NULL)
        {
            if(strcmp(ent->d_name, ".") != 0 && strcmp(ent->d_name, "..") != 0) compteur ++;
        }
        int random_nbr = randomChoice(1, compteur+1);
        rewinddir(rep);
        compteur = 0;
        while(compteur != random_nbr && (ent = readdir(rep)) != NULL)
        {
            if(strcmp(ent->d_name, ".") != 0 && strcmp(ent->d_name, "..") != 0) compteur ++;

        }
        closedir(rep);
        return ent->d_name;
    }
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

void fillHistory(struct tm *actualTime, char* randomScreensaver, char* randomStaticImage, Plane plane)
{
    FILE* file = NULL;

    file = fopen("history.txt","a");

    if (file != NULL)
    {
        fprintf(file,"%d/%d/%d  %d:%d:%d      ",actualTime->tm_mday,actualTime->tm_mon+1,actualTime->tm_year+1900,actualTime->tm_hour,actualTime->tm_min,actualTime->tm_sec);

        if (randomScreensaver == "termSaver1")
        {
            fprintf(file,"Type statique ");
            fprintf(file,"%s\n",randomStaticImage);
        }
        else if (randomScreensaver == "termSaver2")
        {
            struct winsize w;
            ioctl(0, TIOCGWINSZ, &w);

            fprintf(file,"Type dynamique  ");
            fprintf(file,"%d x %d\n",w.ws_row,w.ws_col);
        }
        else if (randomScreensaver == "termSaver3")
        {
            fprintf(file,"Type interactif  ");
            fprintf(file,"%d x %d\n",plane.xpos, plane.ypos);
        }
        fclose(file);
    }
}

void launchProg(char* randomScreensaver, char* randomStaticImage, Plane plane)
{
    pid_t child_pid;
    int status;

    char path[1024];
    char* str = getenv("EXIASAVER_HOME");

    if((child_pid = fork()) < 0 )
    {
        perror("fork failure");
        exit(1);
    }

    if(child_pid == 0)
    {
        if (randomScreensaver == "termSaver1")
        {
            if(str != NULL) strcpy(path, str);
            else getcwd(path, 1024);
            strcat(path, "termSaver1");
            char* arguments[] = {"termSaver1", randomStaticImage, NULL};
            execv(path, arguments);
        }/*
        else if (randomScreensaver == "termSaver3")
        {
            char* arguments[] = {plane.direction,plane.xpos,plane.ypos};
            execv(path,arguments);
        }*/
        else
        {
            execl("termSaver2","",NULL);
        }
        perror("execl failure");
        _exit(1);
    }
    else
    {
        execl("keyboard","",NULL);
        wait(&status);
    }
}


int main(int argc, char *argv[])
{
    system("clear");
    struct tm *actualTime;
    char* randomScreensaver = "termSaver1";
    char* randomStaticImage = "city.pbm";

    Plane plane;

    randomScreensaver = randomScreenChoice(randomScreensaver);
    if (randomScreensaver == "termSaver1")
    {
        randomStaticImage = randomStaticImageChoice();
        printf("%s",randomStaticImage);
    }/*
    else if (randomScreensaver == "termSaver3")
    {
        initialisePlane(&plane);
    }*/
    getActualTime(&actualTime);
    fillHistory(actualTime, randomScreensaver, randomStaticImage, plane);
    if(argc == 2)
    {
        if(strcmp(argv[1],"-stats")==0)
        {
            char path[1024];
            char* str = getenv("EXIASAVER_HOME");
            if(str != NULL) strcpy(path, str);
            else getcwd(path, 1024);
            strcat(path, "history");
            char* arguments[] = {"history",NULL};
            execv(path, arguments);
        }
    }
    else
    {
        launchProg(randomScreensaver, randomStaticImage, plane);
    }

    return 0;
}
