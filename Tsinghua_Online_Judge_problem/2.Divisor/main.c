#include <stdio.h>
#include <stdlib.h>

/* Use Euclid's algorithm, see more details at https://en.wikipedia.org/wiki/Greatest_common_divisor */
int main(int argc, const char * argv[])
{
    int positive_integer_A, positive_integer_B;
    scanf("%d %d", &positive_integer_A, &positive_integer_B);

    int result = 1;
    while (result != 0) {
        result = positive_integer_A % positive_integer_B;
        positive_integer_A = positive_integer_B;
        positive_integer_B = result;
    }
    printf("%d\n", positive_integer_A);
    return 0;
}
