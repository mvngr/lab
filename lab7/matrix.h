#ifndef XMATRIX_H_INCLUDED
#define XMATRIX_H_INCLUDED
/**
* Чтение матрицы из файла
*
* @param char * filename - имя файла
*
* Формат входного файла:
* m,n
* a11,a12,...,a1n
* a21,a22,...,a2n
* ...
* an1,an2,...,amn
*
* Первая строка файла содержит кол-во строк m и кол-во столбцов
* n, указанные через запятую.
* Вторая и последующие строки содержат значения
* элементов матрицы.
*
* @return double * matrix - одномерный массив размером m*n+2,
* содержащий количество строк (элемент matrix[-2]),
* столбцов (элемент matrix[-1]) и все элементы матрицы,
* записанные построчно.
*
*/
double ** readMatrix(char *link);
/**
* Создание матрицы из строки
*
* @param char * str - матрица размером m*n, представленная в
* виде строки формата:
* [a11,a12,...,a1n;a21,a22,...,a2n;...an1,an2,...,amn]
* В качестве разделителей используется запятая между элементами
* одной строки и точка с запятой между строками
*
* @return double * matrix - одномерный массив размером m*n+2,
* содержащий количество строк (элемент matrix[-2]),
* столбцов (элемент matrix[-1]) и все элементы матрицы,
* записанные построчно.
*
*/
double * createMatrix(char *str);
/**
* Создание матрицы, состоящей из цифры
*
* @param unsigned int m - количество строк
* @param unsigned int n - количество столбцов
*
* @return double * matrix - одномерный массив размером m*n+2,
* содержащий количество строк (элемент matrix[-2]),
* столбцов (элемент matrix[-1]) и все элементы матрицы,
* записанные построчно.
*
*/
double ** equateMatrix(unsigned int m, unsigned int n, double num);
/**
* Создание матрицы, состоящей из цифры num
*
* @param unsigned int m - количество строк
* @param unsigned int n - количество столбцов
*
* @return double * matrix - одномерный массив размером m*n+2,
* содержащий количество строк (элемент matrix[-2]),
* столбцов (элемент matrix[-1]) и все элементы матрицы,
* записанные построчно.
*
*/
double ** eyeMatrix(unsigned int k);
/**
* Получение элемента матрицы по его позиции
*
* @param unsigned int i - номер строки
* @param unsigned int j - номер столбца
* @param unsigned int n - количество столбцов
*
* @return double ind - индекс элемента одномерного массива,
* в котором записана матрица
*
*/
double elemIndex(unsigned int col, unsigned int row, double ** arr);
/**
* Display matrix
* @param double * matrix - одномерный массив, в котором
* записана матрица
*
* Матрица выводится на экран в формате:
* a11,a12,...,a1n
* a21,a22,...,a2n
* ...
* an1,an2,...,amn
*
*/
void printMatrix(double ** matrix);
/**
* Сохранение матрицы в файл
*
* @param double * matrix - одномерный массив, в котором
* записана матрица
* @param char * filename - имя файла
*
* Матрица записывается в файл в формате:
* m,n
* a11,a12,...,a1n
* a21,a22,...,a2n
* ...
* an1,an2,...,amn
*
* @return int flag - результат операции (1-запись прошла успешно
* или 0-ошибка записи)
*
*/
int saveMatrix(double ** matrix, char * link);
/**
* Получение числа строк
*
* @param double * matrix - одномерный массив, в котором
* записана матрица
*
* @return int m - количество строк
*
*/
int getRowsNum(double ** matrix);
/**
* Получение числа столбцов
*
* @param double * matrix - одномерный массив, в котором
* записана матрица
*
* @return int n - количества столбцов
*
*/
int getColumnsNum(double ** matrix);
/**
* Транспонирование матрицы
*
* @param double * matrix - одномерный массив, в котором
* записана исходная матрица
*
* @return double * matrix - одномерный массив, в котором
* записана транспонированная матрица
*
*/
double ** tranposeMatrix(double ** matrix);
/**
* Объединение матриц
*
* @param double * matrix1 - одномерный массив, в котором
* записана первая матрица
* @param double * matrix2 - одномерный массив, в котором
* записана вторая матрица
* @param char * align - положение второй матрицы относительно
* первой ("top","left","right","bottom")
*
* Функция должна осуществлять проверку размеров матриц на
* соответствие для выполнения операции
*
* @return double * matrix - одномерный массив, в котором
* записана результирующая матрица
*
*/
double ** combineMatrices(double ** matrix1, double ** matrix2,
char * align);
/**
* Умножение матрицы на число
*
* @param double * matrix - одномерный массив, в котором
* записана матрица
* @param double num - число
*
* @return double * matrix - одномерный массив, в котором
* записана результирующая матрица
*
*/
double * multiplyByNumber(double * matrix, double num);
/**
* Умножение матриц
*
* @param double * matrix1 - одномерный массив, в котором
* записана первая матрица
* @param double * matrix2 - одномерный массив, в котором
* записана вторая матрица
*
* Функция должна осуществлять проверку размеров матриц на
* соответствие для выполнения операции
*
* @return double * matrix - одномерный массив, в котором
* записана результирующая матрица
*
*/
double * multiplyByMatrix(double * matrix1, double * matrix2);
/**
* Сложение матриц
*
* @param double * matrix1 - одномерный массив, в котором
* записана первая матрица
* @param double * matrix2 - одномерный массив, в котором
* записана вторая матрица
*
* Функция должна осуществлять проверку размеров матриц на
* соответствие для выполнения операции
*
* @return double * matrix - одномерный массив, в котором
* записана результирующая матрица
*
*/
double * addMatrix(double * matrix1, double * matrix2);
/**
* Возведение матрицы в степень
*
* @param double * matrix - одномерный массив, в котором
* записана матрица
* @param unsigned int degree - степень
*
* @return double * matrix - одномерный массив, в котором
* записана результирующая матрица
*
*/
double * powMatrix(double * matrix, unsigned int degree);
#endif
