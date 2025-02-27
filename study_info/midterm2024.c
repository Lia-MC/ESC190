// q1a
// Complete this code so that the value of a becomes 42.

int main()
{
int a = 0;
int *p = &a;
f(p); // a should now be 42
return 0;
}

void f(int *pointer) {
    *pointer = 42;
}


// q1b 
// Write a function that computes the sum of the odd elements of an array of integers.

int main()
{
int arr[] = {4, 3, 2, 1, 5};
int n = sizeof(arr)/sizeof(arr[0]);
printf("%d\n", sum_odd(arr, n)); // complete the call.
// should print 9,
// since 3 + 1 + 5 = 9
return 0;
}

int sumodd(int *arr, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 != 0) {
            sum += arr[i];
        }
    }
    return sum;
}

// q1c
// Complete this code so that the values of arr are printed in increasing order, separated by commas, but so
// that the values of arr remain unchanged. Your code should work for any values of elements of arr.

int main() {
    int arr[] = {4, 2, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    g(arr, n); // should print out 2, 3, 4
    // but arr is still {4, 2, 3}
    return 0;
}

// You may find the following useful:
int cmp(const void *a, const void *b) { // don’t need to copy this if used
    return (*(int*)a - *(int*)b);
}
int main() {
    int arr[] = {4, 2, 3, 1, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    qsort(arr, n, sizeof(int), cmp);
    return 0;
}

// ny draft
void g(int *arr, int n) {
    int *cpy; // fine but i needed a malloc for n ints 
    for (int i = 0; i < n; i++) {
        cpy[i] = arr[i];
    }
    qsort(cpy, n, sizeof(int), cmp);
    for (int i = 0; i < n; i++) {
        printf("%d\n", cpy[i]); // forgot the separated by commas
        // to correctly separate by commas, i would need to make sure index is not n - 1 so that theres no comma before last elem
    }
    // also i shouldve freed cpy (all elements first if elements were pointers but theyre not so dont worry about that here)
}

// solution
void g(int *arr, int n) {
    int *temp = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        temp[i] = arr[i];
    }
    qsort(temp, n, sizeof(int), cmp);
    for (int i = 0; i < n; i++) {
        printf("%d", temp[i]);
        if (i < n - 1) {
            printf(", ");
        }
    }
    free(temp);
}

// q2

// Write a function with the signature int last_occurrence(char *str1, char *str2) that takes in two C
// strings, str1 and str2, and returns the location in str1 where the last occurrence of str2 starts. If str2
// is not found in str1, the function should return -1.
// For example,
// char str1[] = "EngSciEngSciTrackOne";
// char str2[] = "EngSci";
// int res = last_occurrence(str1, str2); // res should be 6, since the last
// // occurrence of "EngSci" starts at index 6

#include <stdio.h>

int last_occurrence(char *str1, char *str2) {
    // traverse str1
    // for each index, go for length of str2
    // see if that is identical and if so counter += 1
    // return counter

    int size1 = strlen(str1);
    int size2 = strlen(str2);
    int counter = 0;
    int fail = 1; // true first
    int lastind;

    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size2; j++) {
            if (str1[i] != str2[j]) {
                fail = 0; // now false
            }
        }
        if (fail == 1) {
            counter++; // dont need counter...
            lastind = i;
        }
    }

    if (lastind == NULL) {
        return -1;
    }

    return lastind;
}

// sol:
int last_occurrence(char *str1, char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int res = -1;
    for (int i = 0; i < len1; i++) {
        if (strncmp(str1 + i, str2, len2) == 0) {
            res = i;
        }
    }
    return res;
}


// q3

// Write a recursive function that takes in the strings str1 and str2 and returns the location in str1 where
// the first occurrence of str2 starts. If str2 is not found in str1, the function should return -1.
// You are not allowed to use any loops in your solution. You are not allowed to use any global variables.
// You are not allowed to use any external libraries.
// You are allowed to use helper functions that you implement yourself, as long as they do not use loops,
// global variables, or external libraries.
// You are allowed to define additional parameters for your function.

// char str1[] = "aEngSci EngSci TrackOne";
// char str2[] = "EngSci";
// the recursive function you define should return 1, since that is the
// index where the first occurrence of "EngSci" starts

int firstoccurence(char *str1, char *str2, int curind) { //maybe add a curind param here to keep track of the index?
    // if you reach a null in either str and they dont match return -1
    // if you find a match automatically return (thats when the next char in str2 is null and the next str1 char doesnt matter)

    if ((str2[1] == NULL) && (str1[0] == str2[0])) {
        return 1;
    // } else if ((str2[1] == NULL) && (str1[0] != str2[0])) { // how would this allow us to check the other indexes? ->curind
    //     return firstoccurence(str1 + 1, str2, curind + 1); // wrong but idk how to fix... like if i return -1 i cant check the next you knowww // fixed
    } else if ((str1[0] == str2[0])) {
        return firstoccurence(str1 + 1, str2 + 1, curind);
    } else {
        return firstoccurence(str1 + 1, str2, curind + 1);
    }
}

// Solution
int first_occurrence(char *str1, char *str2, int i, int j) {
    if (str1[i] == NULL || str2[j] == NULL) { // if theyre both null and you havent returned anything yet then -1 (youve reached end of list)
        return -1;
    }
    if (str1[i] == str2[j]) { // if a har is equal
        if (str2[j + 1] == NULL) { // if the next char in the str2 is null (aka the whole str2 was in str1) 
            return i - j; // then immediately return the index by taking the index of the str1 - str2 (why?????)
        }
        return first_occurrence(str1, str2, i + 1, j + 1); // they were equal so keep searching in parallel
    }
    return first_occurrence(str1, str2, i + 1, 0); // they were not equal so reset str2 to 0 and keep search for the next index
}

// q4 
// You are given a file in the following format. On each line, the first number is a 10-digit student number. It
// is then followed by numbers representing marks. The number of marks is not fixed.
// 1234560789 25 75 50
// 9874512541 12 13 14 15 16
// 4564789145 7 6 5
// Write a function that takes in the name of the file, and prints the student numbers of all the student(s)
// whose average mark is the highest. (There can be one or more such student).
// You can assume all marks are whole numbers between 0 and 100, and that there are at most 10 marks
// per student. The student number and the marks are separated by a single space. The file is not sorted in
// any way. Assume at least one student is in the file, and assume that every student has at least one mark.
// Assume there are "\n"s after every line in the file. You cannot assume that the number of students is fixed.
// You may find code from Q1 to be indirectly useful.

typedef struct student{
    int *stunum[10];
    int *marks; // need to malloc at some point somewhere
} student;

void read_in_student_from_str(char *str, student *s){
    int j = 10;
    int k = 0;
    char *mark = (char *)malloc(sizeof(char) * 3);
    for (int i = 0; i < 10; i++) {
        (s->stunum)[i] = str[i];
    }
    while (str[j] != '\n') {
        k = 0;
        while (str[j] != ' ') {
            mark[k] = str[j];
        }
        (s->marks)[j - 10] = atoi(mark);
        free(mark);
        if (str[j] == ' ') {
            j++;
        }
    }
}

void read_in_student_from_file(FILE *f, student *s){
    // fopen(f, "r"); // check this syntax
    // check if empty or smth first i think
    fgets(char *s, int n, f);

    // sol:
    char str[100];
    fgets(str, 100, f);
    read_in_student_from_str(str, s);
    // fclose(f); // check this syntax
}

void read_in_all_students_from_file(char *filename, student *s, int *num_students){
    FILE *fp = fopen(filename, "r"); // check this syntax
    // my code
    for (int i = 0; i < *num_students; i++) {
        read_in_student_from_file(fp, s + i);
    }
    // his code
    while not end of file, read_in_student_from_file(f, &s[i]) and do this in a while loop while incrementing i 

    store i as *num_students value

    fclose(filename); // check this syntax - WRONG 
    fclose(fp); // close filepath
}


void highest_average(char *filename){
    student s[100]; // why can we do this whats the purpose - were not allowed to assume # students is fixed... this has nthg to do with this line acc
    int num_students;

    read_in_all_students_from_file(filename, s, &num_students);

    int highest_average = 0;

    for(int i = 0; i < num_students; i++){
        int sum = 0;
        for(int j = 0; j < 10; j++){
            sum += s[i].marks[j];
        }
        int average = sum / 10;
        if(average > highest_average){
            highest_average = average;
        }
    }

    for(int i = 0; i < num_students; i++){
        int sum = 0;
        for(int j = 0; j < 10; j++){
            sum += s[i].marks[j];
        }
        int average = sum / 10;
        if(average == highest_average){
            printf("%s\n", s[i].student_number);
        }
    }
}

// q1 function that might be half helpful
// int sumodd(int *arr, int n) {
//     int sum = 0;
//     for (int i = 0; i < n; i++) {
//         if (arr[i] % 2 != 0) {
//             sum += arr[i];
//         }
//     }
//     return sum;

// q5

// A linked list structure is defined as follows:
typedef struct node{
    int data;
    struct node *next;
} node;

typedef struct LL{
    node *head;
} LL;

// Part (a)
// Write a function that returns the length of a linked list
int listlen(LL *listtt) {
    int counter = 0;
    if (listtt->head == NULL) {
        return -1;
    } else {
        node *curnode = listtt->head;
        while (curnode != NULL) {
            counter++;
            curnode = curnode->next;
        }
    }
    return counter;
}

// Part (b)
// Write a function that returns the median data point of a linked list. You must use qsort to accomplish this.
// Assume the linked list has an odd number of elements, and they are all distinct.

int mediannn(LL *listtt) {
    // this is what i forgot but NEEDed
    int len = listlen(listtt); // find the length of the linkedlist 
    int *arr = (int *)malloc(len * sizeof(int)); // allocate enough memory for that list properly
    // my code started here
    // int *arr[]; // dont need this anymore bc we do it in *arr
    int i = 0;
    node *curnode = listtt->head;
    while (curnode != NULL) {
        arr[i] = curnode->data;
        curnode = curnode->next;
        i++;
    }
    qsort(arr, listlen(listtt), sizeof(int), comp);
    // return arr[listlen(listtt)/2]; // fine EXCEPT i need to free the place in memory first so i cant just return it right then

    ans = arr[len/2];
    free(arr); // freeing matters
    return ans;
}

int comp(const void *a, const void*b) {
    return ();
}