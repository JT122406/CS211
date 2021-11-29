#include <stdio.h>
#include <ctype.h>
int chars = 0;
//char *count[];
int main(int arg, char *argv[]) {
int counter = 1;
 for (int i = 0; (i <  argv[1][i]) != '\0'; i++)
 {
     for (int j = 0; j < argv[1][j]; j++)
     {
        if (j == 0)
        {
            j = i;
        }
        
        else if (isdigit(argv[1][i]) || isdigit(argv[1][j]))
        {
        printf("error");
        return 0;    
        }
        if (i == j)
        {
            continue;
        }
        else if (argv[1][i] == argv[1][j])
        {
            counter++;
            i = j;
        }
        else if (argv[1][i] != argv[1][j])
        {
            break;
        }
        
    }
        //count[i] = (argv[1][i], counter);
        printf("%c",argv[1][i]);
        printf("%i",counter);
    counter = 1;
    chars = i;
 }
 /*
 for(int i = 0; i < count[i]; i++){
     if (i > chars)
    {
    for(int i = 0; i <  argv[1][i] != '\0'; i++)
    {
        printf("%c",argv[1][i]);
    }
        return 0;
    }
     
 }
 */


 return 0;
}