#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int year = 2016;
    
void printBirthday(int day, int month, int year)
{
    printf("Date birthday: %d.%d.%d\n", day, month, year);
}
void printAnotherBirthday(int day, int month)
{
    printf("Date birthday: %d.%d\n", day, month);
}

int sum(int a, int b)
{
    return a + b;
}

long long int factorial(int a)
{
    long long int res = 1;
    while (a!=1)
    {
        res*=a;
        a--;
        if(res<0)
            return -1;
    }
    return res;
}

long long int fibonacci(int pos)
{
    switch(pos)
    {
        case 0: return 0; break;
        case 1: return 1; break;
        default: return (fibonacci(pos-1) + fibonacci(pos - 2)); break;
    };
}

void sumArray(int a[], int aLen, int b[], int bLen, int *c)
{
    if (aLen == bLen) {
        int i = 0;
        for (i = 0; i < aLen; i++) 
            c[i] = a[i] + b[i];
    }
}

int main()
{
    int input1;
    float input2;
    double input3;
    
    printf("[int .. float .. double]\n");
    scanf("%d%f%lf", &input1, &input2, &input3);
    printf("%d  %f  %lf\n", input1, input2, input3);
    
    int dayB = 23, monthB = 2, yearB = 1998;
    
    printBirthday(dayB,monthB,yearB);
    printAnotherBirthday(dayB,monthB);
    
    int val1 = 5, val2 = 8, res;
    res = sum(val1, val2);
    printf("val1 + val2 = %d \n", res);
    
    int a[5] = {1,2,3,4,5};
    int b[5] = {6,7,8,9,10};
    int c[5];
    
    sumArray(a, 5, b, 5, c);
    
    for (int i = 0; i < 5; i++)
        printf("c[%d] = %d \n", i+1, c[i]);
        
    int num;
    printf("\nInput number: ");
    scanf("%d", &num);
    printf("%d! = %lld\n", num, factorial(num));
    
    num = 11;
    printf("\nFibonacci %d = %lld", num, fibonacci(num));
    
    return 0;
}