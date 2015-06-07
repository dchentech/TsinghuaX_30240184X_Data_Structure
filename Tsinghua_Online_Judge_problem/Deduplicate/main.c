/*
重名剔除(Deduplicate)  http://dsa.cs.tsinghua.edu.cn/oj/problem.shtml?id=408

### Description
Mr. Epicure is compiling an encyclopedia of food. He had collected a
long list of candidates nominated by several belly-gods. As candidates in list
are nominated by several people, duplication of name is inevitable. Mr. Epicure
pay you a visit for help. He request you to remove all duplication, which is
thought an easy task for you. So please hold this opportunity to be famous to
all belly-gods.

### Input
1 integer in fist line to denote the length of nomination list. In
following n lines, each nomination is given in each line.

### Output
All the duplicated nomination (only output once if duplication appears
more multiple times), which is sorted in the order that duplication appears
firstly.

### Example

Input

10
brioche
camembert
cappelletti
savarin
cheddar
cappelletti
tortellni
croissant
brioche
mapotoufu

Output

cappelletti
brioche

### Restrictions
1 < n < 6 * 10^5

All nominations are only in lowercase. No other character is included. Length of
each item is not greater than 40.

Time: 2 sec

Memory: 256 MB

### Hints
Hash
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MaxFoodLen 40
#define HASHSIZE 600000



/*
 * See original code at http://stackoverflow.com/questions/4384359/quick-way-to-implement-dictionary-in-c
 * Below is modified, such as the value is int type now.
 *
 * Use open addressing hash method.
 *
 * */
struct Food { /* table entry: */
    struct Food *next; /* next entry in chain */
    char *name; /* food name */
    int *count; /* food count*/
};

static struct Food *epicure_collection[HASHSIZE]; /* pointer table */

/* hash: form hash value for string s */
unsigned hash(char *s)
{
    unsigned hashval;
    for (hashval = 0; *s != '\0'; s++)
      hashval = *s + 31 * hashval;
    return hashval % HASHSIZE;
}

/* lookup: look for s in epicure_collection */
struct Food *lookup(char *s)
{
    struct Food *np;
    for (np = epicure_collection[hash(s)]; np != NULL; np = np->next)
        if (strcmp(s, np->name) == 0)
          return np; /* found */
    return NULL; /* not found */
}

/* install: put (name, count) in epicure_collection */
struct Food *install(char *name, int count)
{
    struct Food *np;
    unsigned hashval;
    if ((np = lookup(name)) == NULL) { /* not found */
        np = (struct Food *) malloc(sizeof(*np));
        if (np == NULL || (np->name = strdup(name)) == NULL)
          return NULL;
        hashval = hash(name);
        np->next = epicure_collection[hashval];
        epicure_collection[hashval] = np;
    } else {/* already there */
        // http://stackoverflow.com/questions/13148119/what-does-pointer-being-freed-was-not-allocated-mean-exactly
        // NOTE: int don't need to be `malloc`, then don't need to `free`.
        // free(np->count);
    }
    if ((np->count = &count) == NULL)
       return NULL;
    return np;
}



int main() {
    // hash_t *epicure_collection = hash_new();
    // dict *epicure_collection = dict_new();

    int read_line_num = 0;
    int foods_count = 0;

    char *food = NULL;
    size_t foodcap = 0;
    ssize_t foodlen;

    int max_food_len = 40;

    while ((foodlen = getline(&food, &foodcap, stdin)) > 0) {
        // via http://stackoverflow.com/questions/1726298/strip-first-and-last-character-from-c-string
        food[strlen(food)-1] = 0;  // remove \n at the last of the str, and food is already a pointer.

        if (strlen(food) > 40) {
            printf("The food \"%s\"'s length at line %d is greater than %d", food, read_line_num, max_food_len);
            exit(1);
        }
        // printf("[new food] %s\n", food);

        // when init, read_line_num and foods_count both are zero, so the cond is valid..
        if (read_line_num > foods_count) {
            printf("read_line_num:%d should not be large than foods_count:%d.", read_line_num, foods_count);
            exit(1);
        }

        if (read_line_num == 0) {
            foods_count = atoi(food);
        } else {
            // read previous value from epicure_collection
            // char *pre_val_str = hash_get(epicure_collection, food);
            // char *pre_val_str = dict_get(epicure_collection, food);
            struct Food *np = lookup(food);
            int pre_val, curr_val;
            if (np == NULL) {
                pre_val = 0;
            }  else {
                pre_val = *np->count;
            }
            curr_val = pre_val + 1;

            // print if it's already exists
            if (curr_val > 1) {
                // printf("food:%s, curr_val:%d\n", food, curr_val);
                printf("%s\n", food);
            }

            install(food, curr_val);
        }

        // printf("hash_size:%d, read_line_num:%d\n", dict_len(epicure_collection), read_line_num);
        read_line_num ++;
    }

    return 0;
}
