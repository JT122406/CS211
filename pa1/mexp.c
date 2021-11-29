#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

    void Multiply(int** matrix, int ex, int size){
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
             
             
                
            }
        }
        
    }

    void identity(int size){
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                if (i == j)
                {
                    printf("1 ");
                }
                else
                {
                    printf("0 ");
                }
            }
            printf("\n");
        }
    }

    int main(int argc, char** argv) {
    int size;
    FILE* doc = fopen(docname, "r");
    fscanf(doc, "%d", &size);
    int matrix1[size][size];
    int hold = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            fscanf(doc, "%d", &hold);
            matrix1[i][j] = hold;
        }
    }
    int exp;
    fscanf(doc, "%d", &exp);
    if (exp == 0)
    {
        identity(size);
    }
    else
    {
        Multiply(matrix1, exp, size)
    }
    

    }