#include <stdio.h>
#include <stdlib.h>

// Question 2.
// Implement two versions of the string.h function strcat: https://www.programiz.com/c-programming/
// library-function/string.h/strcat .
// In one version, use the index i to access elements of strings.
// In another version, only use pointer arithmetic.

// using only pointer arithmetic
void strcat1(char *destination, const char *source) {
    // make the null character elem point to src
    // &(*(dest + srclen)) = src;
    while (*(destination) != '\0') {
        destination++;
    }
    while (*source != '\0') {
        *destination = *source;
        destination++;
        source++;
    }
    *destination = '\0'; // i had been forgetting this :(((
}

// using index i:
void strcat2(char *str1, char *str2) {
    int i = 0;
    while (*(str1 + i) != '\0') {
        i++;
    } // at i, it's null char
    int len2 = 0; // find by doing same strat as above
    while (*(str2 + len2) != '\0') {
        len2++;
    }
    for (int j = 0; j <= len2; j++) { // equal two means it accounts for the null char
        *(str1 + i) = *(str2 + j);
        i++;
    }
}

// Q2
// Implement a version of strcmp recursively. Name the function my strcmp rec. See the description of
// strcmp here: https://www.programiz.com/c-programming/library-function/string.h/strcmp.
// Suppose your code looks as follows:
// char *s1 = "[...]";
// char *s2 = "[...]";
// Explain the difference between s1 == s2, *s1 == *s2, and strcmp(s1, s2).

int mystrcmprec(const char* str1, const char* str2) {
    if (*str1 == *str2 && *str1 != '\0') {
        mystrcmprec(str1+1, str2+1);
    } else if (*str1 != *str2) {
        return 0; // false
    } else if (*str1 == *str2 && *str1 == '\0') {
        return 1; // true
    }
}

// Question 4.
// For Project 1, you will need to implement “Binary Search Deluxe” in C.
// “Binary Search Deluxe” takes in a sorted list of integers and a target, and returns both the first and
// the last index where target appears.
// For example,
// binary_search_deluxe([1, 2, 3, 10, 10, 10, 12, 12], 10)
// should return [3, 5], since the 10’s start at index 3 and end at index 5.
// Make sure that the algorithm runs in O(log(n)) time.

// Your task is to implement binary search deluxe right, which returns the index of the last occurrence
// of target in L, in O(log(n)) time. (Note: finding the first occurrence and then looking through the list from
// there is not O(log(n)) time. One idea: what is the condition that indicates that you found the right-most
// occurrence of target?)

int binary_search_deluxe_right(int *sorted_ints, int target) {
    int found = 0; // 0 means not found aka false
    int mid;
    int left = 0;
    int i = 0;
    while (sorted_ints[i] != NULL) {
        i++;
    }
    int right = i - 1;

    while (found == 0) {
        mid = (right - left) / 2;
        if (target < sorted_ints[mid]) {
            right = mid;
        } else if (target > sorted_ints[mid]) {
            left = mid;
        } else {
            while (sorted_ints[mid] == target) {
                mid++;
            }
        }
    }

    return mid - 1;
}

// for reference:
    // def binary_search_deluxe_left(L, target):
    // """Return the index of the first occurrence of target in L.
    // Assume that target is in L"""
    //      left = 0
    //      right = len(L) - 1
    //          while left <= right:
    //              mid = (left + right) // 2
    //              if L[mid] < target:
    //                  left = mid + 1
    //              else:
    //                  right = mid - 1
    //      return left

// so essentially i start by initializing left and right, then i write a while where right is greater than or equal to left
// i calculate mid, and then i check if mid is bigger than the target. if mid is bigger than the target, 
// then change left to be mid + 1, but if mid is equal to or smaller than the target, then keep looking 

int main() {
    // q2
    char *first = (char *)malloc(sizeof(char) * 300);
    *(first) = 'a';
    *(first + 1) = 'g';
    *(first + 2) = '\0';
    char *second = "oooooooooooo";
    strcat1(first, second);
    printf("%s", first);
    strcat2(first, second);
    printf("%s", first);

    // q3
    char *one = "ahhhhhhhhhhhhhhh";
    char *two = "no";
    char *three = "ahhhhhhhhhhhhhhh";

    printf("%d", mystrcmprec(one, two));
    printf("%d", mystrcmprec(one, three));

    // q4
    int list[8] = [1, 2, 3, 10, 10, 10, 12, 12];
    printf("%d", binary_search_deluxe_right(list, 10));
}