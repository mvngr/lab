#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>
double power(int num)
{
    int cpyNum = num;
    double res = 1;
    while (cpyNum > 0)
    {
        res *= 0.1;
        cpyNum /= 10;
    }
    return num*res;
}
double ** readMatrix(char *link)
{
    FILE *fileIn;
    double **arr;
    int col, row;
    fileIn = fopen(link, "r");
    if (!fileIn)
        printf("AHTUNG!");
        else
        {
            int i=0, j;
            int ch;
            ch = fgetc(fileIn);

            char tmp[10];
            for(i = 0; i < 10; i ++)
                tmp[i] = 0;
            i=0;
            while (ch!=',')
            {
                tmp[i]=ch;
                ch = fgetc(fileIn);
                i++;
            }
            col = atoi(tmp);

            for(i = 0; i < 10; i ++)
                tmp[i] = 0;

            ch = fgetc(fileIn);
            i= 0;
            while (ch!='\n')
            {
                tmp[i]=ch;
                ch = fgetc(fileIn);
                i++;
            }
            row = atoi(tmp);

            printf("%d   %d\n", col, row);


            arr = (double **)malloc(col * sizeof(double*));

            for (i = 0; i < col; i++)
                arr[i]=(double *)malloc(row*sizeof(double));

            char temp[10];
            int changeTempTmp; //0 - целая часть, 1 - дробная
            for (i = 0; i < col; i++){
                for (j = 0; j < row; j++)
                {
                    changeTempTmp = 0;
                    int m;
                    for(m = 0; m < 10; m ++){ //чистим
                        tmp[m] = 0; //целая часть
                        temp[m] = 0; //дробная часть
                    }

                    ch = fgetc(fileIn); //первый символ
                    int f = 0;
                    while (ch!=',' && ch!='\n' && !feof(fileIn))
                    {

                        // printf("%c ", ch);
                        if (ch == '.'){
                            changeTempTmp = 1;
                            f = 0;
                        }
                        else{
                            if (changeTempTmp == 0)//смотрим записывать в целую часть или дробную
                                tmp[f]=ch;
                                else
                                temp[f] = ch;
                            f++;
                        }

                        ch = fgetc(fileIn);


                    }
                    int bbb = atoi(tmp);
                    bbb = atoi(temp);
                    printf(" %d,%d) ", i, j);
                    arr[i][j] = (double)(atoi(tmp) + power(atoi(temp)));
                    printf("%lf ", arr[i][j]);

                    if(ch == ',')
                        ch = fgetc(fileIn); //пропускаем пробел после ,
                }
                printf("\n");
            }
        }

    fclose(fileIn);
    return arr;
}
double ** equateMatrix(unsigned int m, unsigned int n, double num)
{
    double ** arr;

    arr = (double **)malloc(m * sizeof(double*));

    int i, j;
    for (i = 0; i < m; i++)
        arr[i]=(double *)malloc(n*sizeof(double));

    for (i =0; i < n; i++)
        for (j = 0; j < m; j++)
            arr[i][j] = num;
    return arr;
}
double ** eyeMatrix(int k)
{
    int i, j;
    double ** arr;

    arr = (double **)malloc(k * sizeof(double*));
    for (i = 0; i < k; i++)
        arr[i]=(double *)malloc(k * sizeof(double));

    for (i =0; i < k; i++)
        for (j = 0; j < k; j++)
            if (i == j)
                arr[i][j] = 1;
            else
                arr[i][j] = 0;
    return arr;
}
double elemIndex(unsigned int row, unsigned int col, double ** arr)
{
    return arr[row][col];
}
void printMatrix(double ** matrix)
{
    int i, j;

    for (i = 0; i < getRowsNum(matrix); i++){
        for (j = 0; j < getColumnsNum(matrix); j++)
            printf("%lf ", matrix[i][j]);
        printf("\n");
    }
    return;
}
int saveMatrix(double ** matrix, char * link)
{
    int i, j;
    FILE *fileOut;
    fileOut = fopen(link, "w");
        if (!fileOut)
            return 0;
        else{
            fprintf(fileOut, "%d, ", getRowsNum(matrix));
            fprintf(fileOut, "%d\n", getColumnsNum(matrix));
            for (i = 0; i < getRowsNum(matrix); i++){
                for (j = 0; j < getColumnsNum(matrix); j++)
                    if(j != getRowsNum(matrix)-1)
                        fprintf(fileOut,"%lf, ",matrix[i][j]);
                        else
                        fprintf(fileOut,"%lf",matrix[i][j]);
                fprintf(fileOut, "\n");
            }
        }

        fclose(fileOut);
        return 1;

}
int getRowsNum(double ** matrix)
{
    int res = sizeof(matrix)/sizeof(matrix[0]); //не работает :(
    return res;
}
int getColumnsNum(double ** matrix)
{
    return sizeof(matrix[0])/sizeof(matrix[0][0]);
}
double ** tranposeMatrix(double ** matrix)
{
    double ** arr;

    arr = (double **)malloc(getColumnsNum(matrix) * sizeof(double*));

    int i, j;
    for (i = 0; i < getColumnsNum(matrix); i++)
        arr[i]=(double *)malloc(getRowsNum(matrix) * sizeof(double));

    for (i = 0; i < getRowsNum(matrix); i++)
        for (j = 0; j < getColumnsNum(matrix); j++)
            arr[i][j] = matrix[j][i];
    return arr;
}
double ** combineMatrices(double ** matrix1, double ** matrix2, char * align) //todo ПНД
{
    int i, j;
    int at;
    double ** arr;

    switch (align[0]) {
    case 't':
        arr = (double **)malloc((getRowsNum(matrix1) + getRowsNum(matrix2)) * sizeof(double*));
        for (i = 0; i < getRowsNum(matrix1) + getRowsNum(matrix2); i++)
            arr[i]=(double *)malloc(getColumnsNum(matrix1) * sizeof(double));

        for (i = 0; i < getRowsNum(matrix2); i++)
            for (j = 0; j < getColumnsNum(matrix2); j++)
                arr[i][j] = matrix2[i][j];

        at = getRowsNum(matrix2);
        for (i = 0; i < getRowsNum(matrix1); i++)
            for (j = 0; j < getColumnsNum(matrix1); j++)
                arr[i + at][j] = matrix2[i][j];

        break;
    case 'l':
        arr = (double **)malloc((getRowsNum(matrix1)) * sizeof(double*));
        for (i = 0; i < getRowsNum(matrix1); i++)
            arr[i]=(double *)malloc((getColumnsNum(matrix1) + getColumnsNum(matrix2)) * sizeof(double));

        for (i = 0; i < getRowsNum(matrix2); i++)
            for (j = 0; j < getColumnsNum(matrix2); j++)
                arr[i][j] = matrix2[i][j];

        at = getColumnsNum(matrix2);
        for (i = 0; i < getRowsNum(matrix1); i++)
            for (j = 0; j < getColumnsNum(matrix1); j++)
                arr[i][j + at] = matrix1[i][j];

        break;
    case 'r':
        arr = (double **)malloc((getRowsNum(matrix1)) * sizeof(double*));
        for (i = 0; i < getRowsNum(matrix1); i++)
            arr[i]=(double *)malloc((getColumnsNum(matrix1) + getColumnsNum(matrix2)) * sizeof(double));

        for (i = 0; i < getRowsNum(matrix2); i++)
            for (j = 0; j < getColumnsNum(matrix2); j++)
                arr[i][j] = matrix1[i][j];

        at = getColumnsNum(matrix2);
        for (i = 0; i < getRowsNum(matrix1); i++)
            for (j = 0; j < getColumnsNum(matrix1); j++)
                arr[i][j + at] = matrix2[i][j];

        break;
    case 'b':
        arr = (double **)malloc((getRowsNum(matrix1) + getRowsNum(matrix2)) * sizeof(double*));
        for (i = 0; i < getRowsNum(matrix1) + getRowsNum(matrix2); i++)
            arr[i]=(double *)malloc(getColumnsNum(matrix1) * sizeof(double));

        for (i = 0; i < getRowsNum(matrix2); i++)
            for (j = 0; j < getColumnsNum(matrix2); j++)
                arr[i][j] = matrix2[i][j];

        at = getRowsNum(matrix2);
        for (i = 0; i < getRowsNum(matrix1); i++)
            for (j = 0; j < getColumnsNum(matrix1); j++)
                arr[i + at][j] = matrix2[i][j];

        break;
    default: printf("\ngo to default in combineMatrix\n"); return matrix1; break;
    }
    //todo добавить free
    return arr;
}
double ** multiplyByNumber(double ** matrix, double num)
{
    int i, j;
    for (i = 0; i < getRowsNum(matrix); i++)
        for (j = 0; j < getColumnsNum(matrix); j++)
            matrix[i][j] *= num;
    return matrix;
}
double ** multiplyByMatrix(double ** matrix1, double ** matrix2)
{
    double ** arr;
    int i, j, m;

    arr = (double **)malloc(getRowsNum(matrix1) * sizeof(double*));
    for (i = 0; i < getRowsNum(matrix1); i++)
        arr[i]=(double *)malloc(getColumnsNum(matrix2) * sizeof(double));


    for(i = 0; i < getRowsNum(matrix1); i++)
        for(j = 0; j < getColumnsNum(matrix1); j++)
            for(m = 0; m < getRowsNum(matrix2); m++)
                arr[i][j] = matrix1[i][j] * matrix2[i][m];
    //todo free + ПНД
    return arr;
}
double ** addMatrix(double ** matrix1, double ** matrix2)
{
    int i, j;

    for(i = 0; i < getRowsNum(matrix1); i++)
        for(j = 0; j < getColumnsNum(matrix2); j++)
            matrix1[i][j] += matrix2[i][j];
    return matrix1;
}
double ** powMatrix(double ** matrix, unsigned int degree)
{
    int i, j;
    double ** arr;
    arr = (double **)malloc(getRowsNum(matrix) * sizeof(double*));
    for (i = 0; i < getRowsNum(matrix); i++)
        arr[i]=(double *)malloc(getColumnsNum(matrix) * sizeof(double));

    for(i = 0; i < getRowsNum(matrix); i++)
        for(j = 0; j < getColumnsNum(matrix); j++)
            arr[i][j] = matrix[i][j];

    for (i = 0; i < degree; i++)
        arr = addMatrix(arr, matrix);

    return arr;
}
