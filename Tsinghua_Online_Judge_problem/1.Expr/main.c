#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[])
{
    double positive_integer_A, positive_integer_B, result;
    char operator;
    scanf("%lf %c %lf", &positive_integer_A, &operator, &positive_integer_B);

    switch(operator) {
        case '+':
          result = positive_integer_A + positive_integer_B;
          break;
        case '-':
          result = positive_integer_A - positive_integer_B;
          break;
        case '*':
          result = positive_integer_A * positive_integer_B;
          break;
        default:
          printf("Wrong operator: %s, valid operators are +, -, *", &operator);
          exit(1);
    }

    printf("%.0lf\n", result);
    return 0;
}
