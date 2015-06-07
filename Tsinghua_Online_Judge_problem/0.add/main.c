#include <stdio.h>


/*
0.加法(Add)

### 描述
给两个正整数A和B,输出它们的和C = A + B。

### 输入
共计一行,含两个正整数 A 和 B。

### 输出
共计一行,含一个正整数,即 A 与 B 之和 C。

### 输入样例
100 200

### 输出样例
300

### 限制
1 ≤ {A, B} ≤ 106
 */

int main(int argc, const char * argv[])
{
    double positive_integer_A, positive_integer_B;
    scanf("%lf %lf", &positive_integer_A, &positive_integer_B);
    printf("%.0lf\n", positive_integer_A + positive_integer_B);
    return 0;
}
