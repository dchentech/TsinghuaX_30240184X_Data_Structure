#include <stdio.h>
#include <stdlib.h>


/*
1.简单表达式(Expr)

### 描述
任给一个形如“A op B”的表达式,计算它的值。其中操作数 A 和 B 都是正整数,运算符 op 可以是+、‐或*,分别表示加、减、乘。

运算符有且只有一个,除了 A 和 B 的内部不能有空格外(例如 123 不能写成 12 3),其余位置均可能有空格甚至多个空格,但不包含制表符 TAB。

### 输入
共计一行,即表达式“A op B”。

### 输出
共计一行,即表达式的值。

### 输入样例1
100 +  200

### 输出样例1
300

### 输入样例2
100 - 200

### 输出样例2
-100

### 限制
1 ≤ {A, B} ≤ 106
*/


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
