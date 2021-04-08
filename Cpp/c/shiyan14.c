#include <stdio.h>
float f1(float x);
float f2(float x);
float integral(float (*f)(float), float a, float b);
int main()
{
    printf("%f\n", integral(f1, 1, 2));
    printf("%f\n", integral(f2, 0, 3));
}
float f1(float x)
{
    return x * x + 1;
}
float f2(float x)
{
    return x / (1 + x * x);
}
float integral(float (*f)(float), float a, float b)
{
    float s, h;
    int n = 100;
    h = (b - a) / n;
    s = ((*f)(a) + (*f)(b)) / 2;
    for (int i = 1; i <= n; i++)
    {
        s = s + (*f)(a + i * h);
    }
    return s * h;
}