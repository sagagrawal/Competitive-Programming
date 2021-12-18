#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void find_roots(double a, double b, double c, double* root1, double* root2)
{
    double sqrtb24ac = sqrt(b * b - 4 * a * c);
    
    *root1 = (-b + sqrtb24ac) / (2 * a);
    *root2 = (-b - sqrtb24ac) / (2 * a);
}

#ifndef RunTests
int main()
{
    double root1, root2;
    find_roots(2, 10, 8, &root1, &root2);
    printf("Roots: %.2f, %.2f", root1, root2);
}
#endif