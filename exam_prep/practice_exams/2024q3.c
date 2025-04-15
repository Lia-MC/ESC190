// Question 3. [15 marks]
// In C, write a function that takes a string as input and reverses the order of words in that string. A word is
// defined as a continuous sequence of non-space characters, and words are separated by one or more spaces.
// The function should return a new string, leaving the input string unchanged.
// For example, given the string "Hello EngSci Hi", your function should return "Hi EngSci Hello".
// You may assume that the input only contains letters and spaces.

// brainstorm
/*
take string as input
assume input only contains letters and spaces
reverse order of words (words are continuous sequence of non space characters and are separated by 1 or more spaces)
    reverse:
    - start at the end of the string until you hit a space and add the chunk to the beginning of new string
    - start at the beginning, until you hit a space concatenate the chars into a string, when you hit a space, 
      append the string to the beginning of the new word list
function should return a NEW string
*/

#include <stdio.h>
#include <stdlib.h>

char* reverse_words(char *str) {
    int count = 0;
    while (str[count] != '\0') {
        count++;
    }
    char *new = (char *)malloc(count * sizeof(char) + 1); // accounts for null character

    // int i = 0;
    // char *curword;
    // int counter = 0;
    // while (str[i] != '\0') {
    //     counter = 0;
    //     while (str[i] != ' ') {
    //         curword[counter] = str[i];
    //         counter++;
    //     }
    //     // move all the words in new to the right by counter number of spaces + 1
    //     // add a space
    //     // put in the word
    //     i++;
    // }

    int j = count + 1;
    int start;
    int end;
    int k;
    int initial = 0;
    int n = 0;
    while (j != 0) {
        end = j;
        k = j;
        while (str[k] != ' ' && k >= 0) {
            k--;
        }
        start = k + 1;
        for (int m = start; end; m++) {
            new[n] = str[m]; // seg fault
            n++;
        }
        if (j != 1) { // right before the last one doesnt need a space, needs a null instead
            new[n] = ' ';
            n++;
        } else {
            new[n] = '\0';
        }
        j--;
    }

    return new;
}


int main() {
    char *str = "Hello EngSci Hi";
    printf("%s", reverse_words(str));
    // "Hi EngSci Hello"
}