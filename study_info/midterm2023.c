// q1

// Write a function that appends a node to a linked list. You must use the definitions below. Make sure that
// the code works on lists of any size. If you need helper functions, you must write them yourself.
// You may need to make assumptions like “the next field of the last node is NULL.” State any such
// assumption as a comment.
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
typedef struct node{
int data;
struct node *next;
} node;
typedef struct LL{
node *head;
int size;
} LL;
// append integer new_elem to linked list my_list
void LL_append(LL *my_list, int new_elem)
{
    // next field of the last node is null

    int i = 0;
    node *curnode = my_list->head;

    while (curnode != NULL) {
        i++;
        curnode = curnode->next;
    }
    if (i == 0) {
        // create a new node
        node *newnode = {new_elem, NULL};
        my_list->head = newnode;
        my_list->size = 1;
    } else {
        node *newnode = {new_elem, NULL};
        curnode->next = newnode;
        (my_list->size)++;
    }
}

// real sol for q1:

void LL_append(LL *my_list, int new_elem)
{
    // next field of the last node is null

    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = new_elem;
    newnode->next = NULL;

    if (my_list->head == NULL) {
        my_list->head = newnode;
    } else {
        node *curnode = my_list->head;
        while (curnode != NULL) {
            curnode = curnode->next;
        }
        curnode->next = newnode;
    }
    (my_list->size)++;
}


// q2

// Write a function with the signature char * strcat_rec(char *dest, const char *src) that concatenates dest and src recursively. 
// The result is to be stored at dest. The function returns the destination
// string dest. The function does the same thing as strcat in string.h. You must use recursion. You
// must not include header files, use helper functions, or use loops. You may assume that there is sufficient
// space at dest to store the resultant string.
char *strcat_rec(char *dest, const char *src) {
    // assume that there is sufficient space at dest to store the resultant string

    // base cases
    if (*src == '\0') {
        dest = '\0';
    }
    return dest;

    // recursive case
    if (*dest == '\0') {
        *dest = *src;
        *(dest + 1) = '\0';
    }
    
    return (strcat_rec(dest + 1, src + 1));
}

// his sol:
char * strcat_rec(char *dest, const char *src) {
    if(*dest!= '\0'){ 
        strcat_rec(dest + 1, src);
        return dest;
    }
    *dest = *src;
    if(*src == '\0')
        return dest;
    *(dest + 1) = '\0';
    strcat_rec(dest + 1, src + 1);   
    return dest;
}

// copilot

char *strcat_rec(char *dest, const char *src) {
    // assume that there is sufficient space at dest to store the resultant string

    // base cases
    if (*dest == '\0') { // if dest is null, if src is null we keep it, if src is not null, we append that src val to dest
        if (*src == '\0') {
            return dest;
        }
        *dest = *src;
        *(dest + 1) = '\0'; // then we ensure dest ends with null so that when we send the substr, we can go through here again
        strcat_rec(dest + 1, src + 1);
    } else {
        strcat_rec(dest + 1, src); // if dest isnt null just advance through the list
    }
    return dest;
}

// q 3

// You have been tasked with creating a digital White Pages book for the Province of Ontario. You have
// been provided with a text file. The first line of the file contains the number of entries present. Each of the
// following lines contains a phone number formatted as XXX-XXX-XXXX, followed by a tab, followed by
// the business name.
// 3
// 226-222-6678 Spring Cleaning 4 U
// 289-778-1123 Nowruz Party Planners
// 416-445-2555 The April Shower Curtain Company

// Part (a) [15 marks]
// Write a function to read the file filename and set the values at the input pointers appropriately so that
// the information can be used outside the function. The data must be stored as a contiguous block of struct
// business’s.
// Assume memory allocated in this function will be freed elsewhere. Assume that the number of businesses
// can fit in an int. You may not assume that you know the maximum size of a business name. Your code
// needs to be able to handle business names of any length.
// We strongly recommend, but don’t require, using a while-loop rather than strtok or
// sscanf in order to read in the phone numbers and business names. It is MUCH easier to use
// a while-loop!

typedef struct business {
    int phone_number[10]; // Note: this is an array of 10 integers
                          // (one per digit), not a character array
    char *name;
} business;

void read_numbers(const char *filename, business **whitepages, int *size) {
    FILE *fp = fopen(filename, "r");
    int cur_line = 200;
    char *line;
    while () {
        line = malloc(cur_line);
        line = fgets(line, cur_line, fp);
        if (line[-1] != NULL) {
            cur_line *= 2;
        } else {
            //
        }        
    }
    fclose(fp);
}

DEFINE STRUCT business
    INTEGER phone_number[10]  // Array to store each digit of phone number
    POINTER TO CHAR name      // Pointer to store business name

FUNCTION skip_n1_lines(fp, n)
    // Function to skip 'n' lines in a file
    INITIALIZE i TO 0
    INITIALIZE line TO NULL
    FOR i FROM 0 TO n-1
        READ a line from file fp into line
        FREE the memory allocated for line

FUNCTION my_getline(dest, filename, index)
    // Function to read a specific line (index-th line) from a file
    INITIALIZE cur_len TO 1
    SET *dest TO NULL

    DO
        OPEN file with filename in read mode as fp
        CALL skip_n1_lines(fp, index-1)
        REALLOCATE memory for *dest to sizeof(char) * cur_len
        READ a line from fp into *dest with size cur_len
        DOUBLE the value of cur_len
        CLOSE fp
    WHILE last character of *dest is not '\n'

FUNCTION read_numbers(filename, whitepages, size)
    // Function to read the file and populate the whitepages array with business info
    OPEN file with filename in read mode as fp
    ALLOCATE memory for *whitepages to sizeof(business) * (*size)

    INITIALIZE line to an array of size (sizeof(int) * 8)
    READ first line from fp into line
    CONVERT line to integer and store in *size

    INITIALIZE i TO 0
    FOR i FROM 0 TO *size-1
        INITIALIZE line TO NULL
        INITIALIZE ph_sz TO 0
        INITIALIZE index TO 0
        CALL my_getline(line, filename, i+1)

        DO
            IF line[index] is not '-'
                CONVERT line[index] to integer and store in (*whitepages)[i].phone_number[ph_sz]
                INCREMENT ph_sz
            INCREMENT index
        WHILE line[index] is not '\t'
        
        INCREMENT index
        COPY line starting from index to (*whitepages)[i].name
        FREE memory allocated for line

// takeaways
- to write in a file, strcpy(pagename[i]->phone_number, thephonenumber);
- fgets() function returns a pointer to the string buffer if successful
- atoi converts strings to whole numbers (int val = atoi(const char * str);):
// atoi() function reads a representation of a whole number from a string and returns its value.
// While reading it first skips over any whitespace (spaces, tabs or new lines) 
// and then reads all of the characters until it runs into one which is not part of the number. 
// It will stop reading if it finds a decimal point because it is only expecting a whole number
- free line before getting new line
- when getting line, account for unlimited size by doing a while loop, multiply capacity by 2 
- open file, skip lines until you get to your line, realloc to curlen, read in a line, double curlen
- repeat until last char is null 
- if line[index] != '.' convert to num while line[index] isnt '\t'