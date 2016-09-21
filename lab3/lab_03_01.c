#include <stdio.h>
#define ROW 5 //строка
#define COL 3 //столбец
#define ind 5

int main() {
    int arr[10] = {1,2,3,4,5};
    
    for (int i = 5; i< 10; i++)
        arr[i] = i+1;
        
    int b[10] = {10,9,8,7,6,5,4,3,2,1};
    
    for (int i = 0; i < 10; i++)
        printf("%d ", b[i]);
        
    printf("\n");
    
    int a[COL][ROW];
    int c[2] = {-1,-1};
    
    for (int i = 0; i < COL; i++){
        for (int j = 0; j < ROW; j++){
            a[i][j] = i * j;
                if (a[i][j]!=0 && a[i][j]%6 == 0)
                {
                    c[0] = i;
                    c[1] = j;
                }
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    printf("Эл-т находится в %d строке %d столбце\n",c[0],c[1]);
    
    printf("\n");
    
    int crab[3][2] = { {11,12}, {21,22}, {31,32} };
    
    long int rows = sizeof(crab)/sizeof(crab[0]);
    long int columns = sizeof(crab[0])/sizeof(crab[0][0]);
    
    printf("Rows crab: %ld\n", rows);
    printf("Columns crab: %ld\n", columns); 

    int d[30] = {0,1}, sum = 0;
    printf("%d %d ", d[0], d[1]);
    
    for (int i = 2; i < 30; i++)
    {
        d[i] = d[i-1] + d[i-2];
        printf("%d ", d[i]);
    }
    
    for (int i = 0; i< 30 ; i++)
        if (i%2==0)
            sum+=d[i];
    
    printf("\nsum = %d", sum);
    
    int tmp;
    for (int i = 0; i < 15; i++) //сортировка по убыванию
    {
        tmp = d[i];
        d[i] = d[29-i];
        d[29-i]=tmp;
    }
    
    printf("\n\nСортированный массив:\n");
    for (int i = 0; i< 30 ; i++) //вывод массива
        printf("%d ", d[i]);
      
    int t1[ind], t2[ind]; 
    int t3[ind] = {1,2,3,4,5};
    t1[0] = 0; t1[1] = 1; t1[2] = 2; t1[3] = 3; t1[4] = 4;
    for (int i = 0; i < ind; i++)
        t2[i] = i;
        
    int v[2][4][5];
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 4; j++)
            for (int z = 0; z < 5; z++)
                v[i][j][z] = i*j*z;
    
    printf("\n\nsize i = %d", sizeof(v)/sizeof(v[0]));
    printf("\nsize j = %d", sizeof(v[0])/sizeof(v[0][0]));
    printf("\nsize z = %d", sizeof(v[0][0])/sizeof(v[0][0][0]));
    
    return 0;
}