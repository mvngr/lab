#include <stdio.h>
int plus(int a, int b)
{
    if (a + b > 1)
    return 1;
    else
    return a+b;
}
int otr(int i)
{
    if (i==1)
    return 0;
    else return 1;
}
int main()
{
    int i, j = 0;

    for (i = 0; i < 5; i++)
    printf("Цикл for: i = %d\n", i);

    i = 0;
    while (i < 5 && j == 0){
    printf("Цикл while: i = %d\n", i);
    i++;
    }

    i = 0;
    do{
        printf("Цикл с постусловием: i = %d\n", i);
        i++;
    }
    while (i < 5);

    int a, b, c;

    printf("\n\nЦикл for: \n");
    for (a = 0; a <= 1; a++)
        for (b = 0; b <= 1; b++)
            for (c = 0; c <= 1; c++)
                printf("%d * %d + ¬%d = %d\n", a, b, c, plus(a * b, otr(c)));

    a = 0, b = 0, c = 0;

    printf("\n\nЦикл while: \n");
    while (a <= 1){
        while (b <= 1){
            while (c <= 1){
                printf("%d * %d + ¬%d = %d\n", a, b, c, plus(a * b, otr(c)));
                c++;
            }
            b++;
            c = 0;
        }
        a++;
        b = 0;
    }

    a = 0, b = 0, c = 0;

    printf("\n\nЦикл do while: \n");
    do {
    b = 0;
        do {
        c = 0;
            do {
                printf("%d * %d + ¬%d = %d\n", a, b, c, plus(a * b, otr(c)));
                c++;
            }
            while (c <= 1);
        b++;
        }
        while (b <= 1);
    a++;
    }
    while (a <= 1);


    return 0;
}
