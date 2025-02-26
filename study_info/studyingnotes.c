// questions
// 1. how to return a nonint number (aka float) in a function? as in what to put as the type of the function 
// -> maybe double??
// 2. how to do unlimited lines during file reading?


// notes
dont do this: int *p_a = 0; because addresses CANNOT be set to 0
// practice implementing strlen, strcmp, strcpy, strcat // DONE
// review memove, memcpy // reviewed, not implemented
// practice reading input // practiced, gotta review
// practice writing to a file // dont think this is needed
// finish the damn pointer exercises
// use blocks of structs
// insertion sort (lab 1)
// do proj 1 / use qsort
// binary search lab 2 q 4
// make atoi lab 2 q 5
// review linked lists / use linked lists (namely creating and initializing + append)
// do past midterms (2024, 2023)
// understand realloc
// do the bubble sort exercise by quilin
// question 6 (lab 1)

// qsort:
qsort(array_to_be_sorted, #_elements_in_array, sizeof(type of data thats stored in array), comp)
// where comp:
int comp(const void *p_a, const void *p_b) {
    // go through each element of the two lists

    // then return:
    // A negative number if the first element is smaller than the second element
    // 0 if the two elements are equal
    // A positive number if the first element is larger than the second element
}

// int * myfunc() {}

// file reading:
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
FILE *filepath = fopen("l1.txt", "r"); // r is for read // if the file doesn't exist, fopen returns NULL
char line[200]; // character array line with a maximum size of 200 characters is declared
fgets(line, 200, filepath); // reads a line of text from the file pointed to by fp and stores it in the line array
// maximum number of characters to be read is specified as 200
line[strlen(line) - 1] = '\0'; // last character of line, which is the newline character, is replaced with a null terminator ('\0')
// int num_items = atoi(line); // in this particular case, the value of the first line in cities.txt is the number of terms

// note: we can use fgets to read the entire file line by line. 
// this is useful if we want to read the file line by line and do something with each line

// realloc
//make memory 
char *str = (char *)malloc(100 * sizeof(char));

// want to make more space
str = (char *)realloc(str, 200 * sizeof(char));

// reading input

get an int -> inta; scanf("%d", &a);
get a float -> float f; scanf("%f", &f);
get a string -> char s[100]; scanf("%s", s);
get a pointer to a string -> char *p_a = (char *)malloc(100); scanf("%s", p_a);
get a pointer to an int -> int *p_int = (int *)malloc(sizeof(int)); scanf("%d", p_int);

// local versus . versus ->
person p;
p.name = // property of person
// or
person* p = (person*) malloc(sizeof(person));
and then 
person *p_person;
(*p_person).name= // dereference the pointer and then get property of person, here, the person's name
// is equal to
p_person->name= // dereferencing and getting the name is done in one step

// when constructing an array of integers from an input, use double pointer
pass in: int **p_arr
use as: *p_arr = (int *)malloc(*p_n * sizeof(int));
                for (int i = 0; i < *p_n; i++){
                    scanf("%d", &(*p_arr)[i]);
                }

// equivalent pointers
&(*p_arr)[i] == *p_arr + i
// where *p_arr is the address of the actual array, then we want to access element i and then get its address

// remember all libraries and their purposes + what functions can be called using it
#include <stdbool.h> //for booleans
#include <stdio.h> //the standard
#include <string.h> 
#include <stdlib.h> //allows you to use malloc..etc

strlen() return the length of the string
strcpy() copy one string to another 
strcmp() compares two strings
strcat() concatenates first n characters of one string to another
isspace(character) checks if the argument contains white space
memmove() moves content that overrides to a buffer
memcpy() will override the content

// weird ass shortcuts
str++ puts str + 1 into str, the value of *str is str[0]
*++a means first increment a then access *a
a++ = a + 1 is undefined behaviour

// how to declare arrays of chars/ints/etc. - initializing or just declaring
int arr[5] = {1,2,3,4,5};
char arr[] = {'x', 'y', 'z', '\0'}; // The program will automatically determine how many entries this array has.
char str[]; // both point to the first character of a string 
char *str; // both point to the first character of a string 
the last element in the array is the null character ‘\0’

// declaring/initializing strings
#include <stdio.h>
int main()
{
  char arr1[4] = "uvw";
  char arr2[4] = {'x', 'y', 'z', '\0'};
  char arr3[3] = {'a', 'b', 'c'}; // Incorrect, will produce weird results
  printf("%s\n", arr1); // uvw
  printf("%s\n", arr2); // xyz
  printf("%s\n", arr3); // something weird!
}

// bits and bytes for different data types
char is 1 byte
bool is 1 byte
short occupies 2 bytes of memory 
int is 4 bytes
float is 4 bytes
long int is 4 bytes
long long int is 8 bytes
long double is 8 bytes
double is 8 bytes
on a 32gb, pointer is 4 bytes
on a 64gb, pointer is 8 bytes

// swapping int

// pointer arithmetic
*(str + 1) == str[1]
arr[2] = 6; is the same as *(arr + 2) = 6;

// using arrays in functions
#include <stdio.h>
#include <stdlib.h>

int *make_array_right()
{
    int *a = (int *)malloc(5*sizeof(int));
    a[0] = 1;
    a[1] = 2;
    a[2] = 3;
    a[3] = 4;
    a[4] = 5;

    return a;
}
int main()
{
  int *a_good = make_array_right();
  printf("%d" , a_good[0]);

  free(a_good);
}

// iterating through a list and freeing each element before freeing the block or list

// struct creation
typedef struct waterloo_student{
  char *st_number_str;
} waterlooser;
void createwaterlooser(waterlooser **l, char *stunum) {
    *l = (waterlooser *)malloc(sizeof(waterlooser)); // dereference to change address to malloced address
    (*l)->st_number_str = (char *)malloc(5 * sizeof(char)); // explicitly dereference l because rn it's ** and we want just l which -> only dereferences *
    // (*(*l)->st_number_str) = stunum;
    strcpy((*l)->st_number_str, stunum); // // copy the string to allocated memory
}
int main() {
    waterlooser *looser1;
    createwaterlooser(&looser1, "6135");

    free(looser1->st_number_str);
    free(looser1);
}

// functions and strings
void set_name1a(student1 s)
{
  strcpy(s.name,"abc"); // this doesnt do anything because it changes the name of the copy locally but it doesnt change anything in memory
}
void set_name2b(student2 s)
{
  s.name = (char *)malloc(5); // this would cause a memory leak, since the malloc is good but we can only access it locally
  strcpy(s.name,"abc");
}

// const
const char * = ' ' type is defined by using single quotes
cannot change the value pointed to, but you can change the pointer itself

// printf()
%d: decimal
%c: character
%s: string
%ld: long decimal