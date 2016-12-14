#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

#define MAX_CTRLS 80

int send(char val[1])
{
    int create;
    create = mkfifo("/tmp/ctrl", 0666);
    char line[MAX_CTRLS];
    int pipe;
    pipe = open("/tmp/ctrl", O_WRONLY);
    printf("Entrer message ");
    fgets(line, MAX_CTRLS, stdin);
    write(pipe, line, MAX_CTRLS);
    close(pipe);
    return 0;
}
int receive(char val[2])
{
    char line[MAX_CTRLS];
    int pipe;
    pipe = open("/tmp/ctrl", O_RDONLY);
    read(pipe, line, MAX_CTRLS);
    printf("%s",line);
    close(pipe);
    return 0;
}
