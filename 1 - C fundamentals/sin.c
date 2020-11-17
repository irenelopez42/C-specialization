#include <stdio.h>
#include <math.h>

int main(void)
{ 
    double x, y;
    printf("Enter angle in radians:");
    scanf("%lf", &x);
    y = sin(x);
    printf("sin(x) = %lf \n\n", y);
    return 0;
}
