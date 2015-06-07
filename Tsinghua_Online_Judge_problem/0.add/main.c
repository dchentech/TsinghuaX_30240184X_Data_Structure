#include <stdio.h>

int main(int argc, const char * argv[])
{
    double positive_integer_A, positive_integer_B;
    scanf("%lf %lf", &positive_integer_A, &positive_integer_B);
    printf("%.0lf\n", positive_integer_A + positive_integer_B);
    return 0;
}
