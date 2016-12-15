#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

#define CTRLS 100

void createPipe()
{
    mkfifo("tmp/FIFOSCRN", S_IFIFO|0666); //Création du pipe
}
int send()//Fonction qui envoie au pipe
{
    char cmd[CTRLS];
    int pipe;
    pipe = open("tmp/FIFOSCRN", O_WRONLY);
    write(pipe, cmd, strlen(cmd));
    close(pipe);
    return 0;
}
int receive()//Fonction qui permt au pipe de recevoir les donnée envoyées par la fonction send()
{
    char cmd[CTRLS];
    int pipe;
    pipe = open("tmp/FIFOSCRN", O_RDONLY);
    read(pipe, cmd, strlen(cmd));
    close(pipe);
    return 0;
}
