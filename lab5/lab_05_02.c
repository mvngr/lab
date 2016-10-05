#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846
#define E 2.718281828459

double triangleArea(double a, double b, double c)
{
    double p = (a+b+c)/2;
    return pow((p*(p-a)*(p-b)*(p-c)), 0.5);
}

double findSide(double a, double b, double alpha)
{
    return pow(a*a+b*b-2*a*b*cos(alpha), 0.5);
}

int main()
{
    double alphaDeg = 45,
    alpha = PI*alphaDeg/180; 
    
    printf("alphaDeg = %.0lf, alpha = %lf\n", alphaDeg, alpha);
    printf("sin(alpha) = %lf\n", sin(alpha));
    printf("cos(alpha) = %lf\n", cos(alpha));
    printf("tan(alpha) = %lf\n", tan(alpha));
    printf("atan(tan(alpha)) = %lf\n", atan(tan(alpha)));
    printf("floor(alpha) = %lf\n", floor(alpha));
    printf("ceil(alpha) = %lf\n", ceil(alpha));
    
    double a = 5, b = 3;
    printf("exp(a) = %lf\n", exp(a));
    printf("log(a) = %lf\n", log(a));
    printf("log10(a) = %lf\n", log10(a));
    printf("pow(a,b) = %lf\n", pow(a,b));
    printf("sqrt(a) = %lf\n", sqrt(a));
    printf("fabs(a) = %lf\n", fabs(-alpha));
    
    double c;
    printf("\nInput C: ");
    scanf("%lf", &c);
    printf("S (ABC) = %lf\n", triangleArea(a, b, c));
    
    printf("C = %lf\n", findSide(a,b,alpha));
    printf("log(E^7) = %lf\n", log(pow(E, 7)));
    return 0;