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
    mkfifo("tmp/FIFOSCRN", S_IFIFO|0666);
}
int send()
{
    char cmd[CTRLS];
    int pipe;
    pipe = open("tmp/FIFOSCRN", O_WRONLY);
    write(pipe, cmd, strlen(cmd));
    close(pipe);
    return 0;
}
int receive()
{
    char cmd[CTRLS];
    int pipe;
    pipe = open("tmp/FIFOSCRN", O_RDONLY);
    read(pipe, cmd, strlen(cmd));
    close(pipe);
    return 0;
}
