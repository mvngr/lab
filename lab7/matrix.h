#ifndef XMATRIX_H_INCLUDED
#define XMATRIX_H_INCLUDED

double ** readMatrix(char *link);
double * createMatrix(char *str);
double ** equateMatrix(unsigned int m, unsigned int n, double num);
double ** eyeMatrix(int k);
double elemIndex(unsigned int row, unsigned int col, double ** arr);
void printMatrix(double ** matrix);
int saveMatrix(double ** matrix, char * link);
int getRowsNum(double ** matrix);
int getColumnsNum(double ** matrix);
double ** tranposeMatrix(double ** matrix);
double ** combineMatrices(double ** matrix1, double ** matrix2,char * align);
double ** multiplyByNumber(double ** matrix, double num);
double ** multiplyByMatrix(double ** matrix1, double ** matrix2);
double ** addMatrix(double ** matrix1, double ** matrix2);
double ** powMatrix(double ** matrix, unsigned int degree);
#endif
