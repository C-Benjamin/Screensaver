#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

#define MAX_CTRLS 80

int main(int argc, char** argv) {
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
