#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

double** creatematrix(int row, int columns){
    double** matrix = malloc(row * sizeof(double*));
    for (int i = 0; i < row; i++)
    {
        matrix[i] = malloc(columns * sizeof(double));
    }
    for(int i = 0; i < row; i++){
        for (int j = 0; j < columns; j++)
        {
            matrix[i][j] = 0;
        }
    }
    return matrix;
}

void print(double** mat, int row, int col){
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%.0f", mat[i][j]);
        } 
        printf("\n");
    }
    return;
}

double **multiply(double** array, int row1, int column1, double** array2, int row2, int column2){
    if ((array == NULL || array2 == NULL) || (row2 != column1))
    {
        return 0;
    }
    else
    {
        double sum = 0;
        double** result = creatematrix(row1, column2);
        for (int i = 0; i < row1; i++)
        {
            for (int j = 0; j < column2; j++) //check this in morning please future J.T. help me
            {
                for (int k = 0; k < column1; k++)
                {
                    sum += (array[i][k] * array2[k][j]);
                }
                result[i][j] = sum;
                sum = 0;
            }
        }
        return result;
    }
}

double **transpose(double** array, int row, int column){
    double** result = creatematrix(column, row);
    for(int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            result[j][i] = array[i][j];
        }
    }
    return result;
}

int main(int argc, char** argv){
int row = 0;
int column = 0;
char trains[6] = "";
FILE* traindoc = fopen(argv[1], "r");
fscanf(traindoc, "%5s\n", trains);
fscanf(traindoc, "%d\n", &row);
row++;
fscanf(traindoc, "%d\n", &column);
double** train = creatematrix(column, row);
double hold = 0;
double** Y = creatematrix(column, 1);

for (int i = 0; i < column; i++)
{
    train[i][0] = 1;
}

for (int i = 0; i < column; i++)
{
    for (int j = 1; j < row; j++)
    {
        if (j == (row - 1))
            {
                fscanf(traindoc, "%lf ", &hold);
                train[i][j] = hold;
                fscanf(traindoc, "%lf ", &hold);
                Y[i][0] = hold;
                j++;
            }
        else
            {
                fscanf(traindoc, "%lf ", &hold);
                train[i][j] = hold;
            }        
    }
}

//identity
double** identity = creatematrix(row, row);
for (int i = 0; i < row; i++)
{
    for (int j = 0; j < row; j++)
    {
        if (j == i)
        {
            identity[i][j] = 1;
        }
    }
}

//invert
double** transMat = transpose(train, column, row);
double** tranmulti = multiply(transMat, row, column, train, column, row);

double f = 0;
for (int p = 0; p < row; p++)
{
    f = tranmulti[p][p];
    for (int i = 0; i < row; i++)
    {
        tranmulti[p][i] = (tranmulti[p][i] / f);
        identity[p][i] = (identity[p][i] / f);
    }
    for (int j = p + 1; j < row; j++)
    {
        f = tranmulti[j][p];
        for (int k = 0; k < row; k++)
        {
         tranmulti[j][k] = tranmulti[j][k] - (tranmulti[p][k] * f);   
         identity[j][k] = identity[j][k] - (identity[p][k] * f);  
        }
    } 
}
for (int p = row -1; p >= 0; p--)
{
    for (int i = p - 1; i >= 0; i--)
    {
       f = tranmulti[i][p]; 
       for (int j = 0; j < row; j++)
       {
           tranmulti[i][j] = tranmulti[i][j] - (tranmulti[p][j] * f);
           identity[i][j] = identity[i][j] - (identity[p][j] * f);
       }
    } 
}
double** Q = multiply(identity, row, row, transMat, row, column);
double** W = multiply(Q, row, column, Y, column, 1);

//data
int row2 = 0;
int column2 = 0;
fclose(traindoc);
FILE* datadoc = fopen(argv[2], "r");
char datachar[5] = "";
fscanf(datadoc, "%4s\n", datachar);
fscanf(datadoc, "%d\n", &row2);
row2++;
fscanf(datadoc, "%d\n", &column2);
double **data = creatematrix(column2, row2);
for (int i = 0; i < column2; i++) 
{
    data[i][0] = 1;
}
for (int i = 0; i < column2; i++)
{
    for (int j = 1; j < row2; j++)
    {
        fscanf(datadoc, "%lf ", &hold);
        data[i][j] = hold;
    }
}
double** y2 = multiply(data, column2, row2, W, row, 1);

fclose(datadoc);

for (int i = 0; i < column; i++)
{
    free(train[i]);
}
    free(train);

for (int i = 0; i < column; i++)
{
    free(Y[i]);
}
    free(Y);

for (int i = 0; i < row; i++)
{
    free(transMat[i]);
}
    free(transMat);

for (int i = 0; i < row; i++)
{
    free(identity[i]);
}
    free(identity);

for (int i = 0; i < row; i++)
{
    free(tranmulti[i]);
}
    free(tranmulti);

for (int i = 0; i < row; i++)
{
    free(W[i]);
}
    free(W);

for (int i = 0; i < column2; i++)
{
    free(data[i]);
}
    free(data);

for (int i = 0; i < row; i++)
{
    free(Q[i]);
}
    free(Q);

print(y2, column2, 1);

for (int i = 0; i < column2; i++)
{
    free(y2[i]);
}
    free(y2);

return 0;
}