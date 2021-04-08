#include <stdio.h>
float f1(float x);
float f2(float x);
float integral(float (*f)(float), float a, float b);
int main()
{
    printf("%f\n", integral(f1, 1,