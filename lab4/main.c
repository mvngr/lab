#include <stdio.h>
#include <stdlib.h>
int main() {
    int value = 101, *pValue = &value;

    printf("value = %d \n", value);
    printf("*pValue = %d \n", *pValue);
    printf("*(&value) = %d \n", *(&value));

    printf("value address = %p \n", &value);
    printf("pValue = %p \n", pValue);
    printf("pValue address = %p \n", &pValue);

    int a[6] = {9,8,7,6,5,4};

    printf("a[0] = %d \n", a[0]);
    printf("a[0] = %d \n", *a);
    printf("a[1] = %d \n", *(a+1));

    int *arr;
    arr = malloc(100 * sizeof(int));
    if (arr != NULL) {
    int i;
    for (i = 0; i < 100; i++)
    arr[i] = i;
    }
    for (int i = 0; i < 100; i++)
        printf("%d ", arr[i]);
    free(arr);
    arr = NULL;

    int year = 2016;

    int *pYear = &year;

    printf("\n\n%d\n", *pYear);
    printf("%d\n", *&year);

    printf("\n%p\n", &pYear);
    printf("%p\n", pYear);
    printf("%p\n", &year);

    int b[10] = {0,3,4,5,8,15,12,1,16,18};

    int n = 0;
    while (*(b+n) < 20)
    {
        if (*(b+n)%2 != 0)
            printf("%d ", *(b+n));
        n++;
    }



    return 0;
}
