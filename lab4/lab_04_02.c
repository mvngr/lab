#include <stdio.h>
#include<locale.h>
#define N 10

int main() {

    char name[20], surname[50], group[6];

    int day, month, year;

    printf("F.I.: ");
    scanf("%s %s", name, surname);
    printf("DD.MM.YYYY: ");
    scanf("%d.%d.%d", &day, &month, &year);
    printf("Number your group: ");
    scanf("%s", group);
    printf("\n--Table--\n");
    printf("%s %s\n", name, surname);
    printf("%d.%d.%d \n", day, month, year);
    printf("%s \n", group);

    printf("\n\n---------------------\n\n");

    int a[N];

    for(int i = 0; i < N; i++)
        scanf("%d", &a[i]);

    for(int i = 0; i < N; i++)
        printf("%d ", a[i]);

    char hello[20];

    gets(hello);
    puts(hello);

    int num;

    scanf("%d", &num); //4294967296 (выход из 4 байтов инта)
    printf("%d", num);

    double expnum;
    scanf("%lf", &expnum);

    printf("%.10lf", expnum);

    return 0;
}
