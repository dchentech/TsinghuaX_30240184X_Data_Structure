#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/*
3.字母统计(Count)

### 描述
给定一段文本,统计每个英文字母在其中的出现频率。忽略字母的大小写。

### 输入
一段文本,以换行结束。

### 输出
不超过 26 行。按次序逐行输出各英文字母的出现次数,未出现的字母忽略。 每一行的格式均为:

字母: 出现次数
其中,字母统一采用大写形式,冒号为半角形式,紧接冒号有个空格。

### 输入样例
Hello World!

### 输出样例
D: 1
E: 1
H: 1
L: 3
O: 2
R: 1
W: 1

### 限制
文本总长度不超过 4,096 个字节
*/


#define INPUT_MAX_LEN 4096
#define ALPHABET_LEN 26

int main(int argc, const char * argv[])
{
    char input_chars[INPUT_MAX_LEN + 1];
    scanf("%[^\n]", input_chars);
    int idx;

    // init counter
    int counter[ALPHABET_LEN];
    for (idx = 0; idx < ALPHABET_LEN; idx ++) {
        counter[idx] = 0;
    }

    int input_len = strlen(input_chars);
    for (idx = 0; idx < input_len; idx ++) {
        char chr = input_chars[idx];
        if (isalpha(chr)) {
            counter[toupper(chr) - 'A'] ++;
        }
    }

    for (idx = 0; idx < ALPHABET_LEN; idx ++) {
        if (counter[idx] != 0) {
            printf("%c: %d\n", idx + 'A', counter[idx]);
        }
    }

    return 0;
}
