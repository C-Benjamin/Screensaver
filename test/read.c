#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#define MAX_CTRLS 80


void main()
{

   char line[MAX_CTRLS];
   int pipe;
   pipe = open("/tmp/ctrl", O_RDONLY);
   read(pipe, line, MAX_CTRLS);
   printf("%s",line);
   close(pipe);
}

