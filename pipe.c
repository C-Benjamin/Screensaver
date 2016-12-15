#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

#define MAX_CTRLS 2
    
void send(char ch2[MAX_CTRLS])
{
    int create;
    create = mkfifo("/tmp/ctrl", 0666);
    int pipe1;
    pipe1 = open("/tmp/ctrl", O_WRONLY);
    write(pipe1, ch2, MAX_CTRLS);
    close(pipe1);
}
int receive()
{
   int pipe1;
   pipe1 = open("/tmp/ctrl", O_RDONLY);
while(1)
{
   char ch2[MAX_CTRLS];
   int reader;
   reader = read(pipe1, ch2, MAX_CTRLS);
   if (reader!=-1)
	{
	   printf("%s",ch2);
	   memset(ch2, 0, MAX_CTRLS);
	}
}
	close(pipe1);
	return 0;
}

