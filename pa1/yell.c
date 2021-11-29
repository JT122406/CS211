#include <stdio.h>
#include <ctype.h>

    int main(int argc, char *argv[]) {
        if((argc < 2) || (*argv[1] == '\0')){
            return 0;
        }
        for(int i = 0; argv[1][i] != '\0'; i++){
            printf("%c",toupper(argv[1][i]));
        }
        printf("!!\n");
        return 0;
    }