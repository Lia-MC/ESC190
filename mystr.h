#if !defined(MYSTR_H)

typedef struct mystr{
    char *block; // creating a block
    int sz; // keep track of string length
    int capacity; // keep track of block size
} mystr;

#endif