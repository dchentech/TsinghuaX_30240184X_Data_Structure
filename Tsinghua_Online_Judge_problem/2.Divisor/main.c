#include <stdio.h>
#include <stdlib.h>


/*
2.最大公约数(Divisor)

### 描述
任给大于 1 的两个整数 A 和 B,输出它们的最大公约数,即能够同时整除 A 和 B 的最大正整数。

### 输入
共计一行,含两个正整数 A 和 B。

### 输出
共计一行,即 A 和 B 的最大公约数。

### 输入样例1
100 35

### 输出样例1
5

### 输入样例2
121 37

### 输出样例2
1

### 限制
1 ≤ {A, B} ≤ 109

*/

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
