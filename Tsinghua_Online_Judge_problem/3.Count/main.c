#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

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
