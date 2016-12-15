#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct History History;
struct History
{
    int screenlaunched;
};

//void fillHistory(history);
//void displayHistory(history);

void fillHistory(History history)
{
char* date;
char test[255] = "";
FILE* file = NULL;
file = fopen("test.txt","r");
int c;
int nLignes = 0;

    if (file != NULL){

    while ((c=fgetc(file)) != EOF){

        date = fgets(test,11,file);
        printf("%s",date);
        char* time = fgets(test,11,file);
        printf("%s",time);

            if (history.screenlaunched == 1){

            char*  type1 = fgets(test,16,file);
              printf("%s",type1);
            char*  name = fgets(test,9,file);
              printf("%s",name);



            }

            else if (history.screenlaunched == 2){

            char* type2 = fgets(test,17,file);
              printf("%s",type2);
            char* height = fgets(test,15,file);
              printf("%s",height);
            char* weidht = fgets(test,15,file);
              printf("%s",weidht);

        }
             else if (history.screenlaunched == 3){

            char* type3 = fgets(test,18,file);
              printf("%s",type3);
            char* posx = fgets(test,5,file);
              printf("%s",posx);
            char* posy = fgets(test,5,file);
              printf("%s",posy);
        }
    }
    if (c=='\n'){
        nLignes++;
        }
   }

 fclose(file);
}


int main()
{

    History history;
    history.screenlaunched = 3;
    fillHistory(history);



    return 0;
}



