#include <stdio.h>
#include <mystr.h>

typedef struct mystr{
    char *block; // creating a block
    int sz; // keep track of string length
    int capacity; // keep track of block size
} mystr;

void create_string(mystr **p_p_s) {
    // send address of pointer, set pointer to address of valid mystr 
    if (*p_p_s == NULL) {
        // cant create anything
    } else {
        *p_p_s = (mystr *)malloc(sizeof(mystr));
        (*p_p_s)->capacity = 100;
        (*p_p_s)->block = (char *)malloc(sizeof(char) * (*p_p_s)->capacity);
        ((*p_p_s)->block)[0] = '\0';
        (*p_p_s)->sz = 0;
    }
}

// want to initialize string
// want to change char at an index
void set_char(mystr *p_s, int ind, char c) {
    // send a pointer
    // change p_s contents
    if ((ind >= p_s->sz) || (ind < 0)) {
        printf("Error: index out of bounds");
        exit(1);
    }
    (p_s->block) [ind] = c;
}

// want to be able to append
void append_str(mystr *p_s, const char* src) {
    // change p_s 
    // change p_s capacity
    // change p_s sz
    if (p_s->capacity < p_s->sz + strlen(src)) {
        int new_capacity = p_s->capacity + strlen(src) + 1; // exact amount needed
        // if want to be safe, can multiply it by 2 or smth to add extra memory
        p_s->block = (char *)realloc(new_capacity * sizeof(char));
        p_s->capacity = new_capacity;
        p_s->sz = p_s->sz + strlen(src);
    }

    strcat(p_s->block, src);
    // why not just use strcat? 
    // might not be enough space in the block - realloc is nice
}