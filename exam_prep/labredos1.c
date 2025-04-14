#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Q4
// Implement a function that performs https://en.wikipedia.org/wiki/Insertion_sort#Algorithm. 
// The function should take in an array of integers, and modify the array so that it’s sorted in increasing order.

void my_insertion_sort_draft(int *sorted_arr, int length) {
    int j;
    int temp;

    for (int i = 1; i < length; i++) {
        j = 1;
        while (i >= j) {
            if (sorted_arr[i] > sorted_arr[i - j]) {
                temp = sorted_arr[i];
                sorted_arr[i] = sorted_arr[i - j];
                sorted_arr[i - j] = temp;
                j++;
            }
        }
    }
}

// key is the element to be inserted.
// The inner while loop shifts larger elements to the right.
// Once we find the correct position, we insert key there.

void my_insertion_sort(int *arr, int length) {
    int j;
    int key;
    int k;
    int temp;
    int exit = 0;
    for (int i = 1; i < length; i++) {
        j = 0;
        key = arr[i];
        while (exit == 0 && i - j > 0) {
            if (key < arr[i - j]) {
                j++;
            } else {
                k = i;
                while(k > i - j + 1) {
                    arr[k] = arr[k - 1];
                    k--;
                }
                arr[i - j + 1] = key;
                exit = 1;
            }
        }
    }
}

void chats_insertion_sort(int *arr, int length) {
    int j, key;
    for (int i = 1; i < length; i++) {
        key = arr[i];
        j = i - 1;

        // Shift elements of arr[0..i-1] that are greater than key to the right
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        // Insert key at the correct position
        arr[j + 1] = key;
    }
}

void my_corrected_insertion_sort(int *arr, int length) {
    int j;
    int key;
    for (int i = 1; i < length; i++) {
        key = arr[i];
        j = i - 1; // the index before it, it's valid for at least 1 round because we start at index 1 so this would be index 0
        while (j >= 0 && arr[j] > key) { // if key is less, we'll wanna keep checking the lefter values
            arr[j+1] = arr[j]; // move the current element to the right, we start this by replacing the key, 
                               // and worst case we end this with the elem directly at the end, 
                               // moving it to the right creates an empty spot at the beginning 
            j--;
        }
        arr[j+1] = key;
    }
}

void practicing_insertion_sort(int *arr, int length) {
    int j;
    int key;
    for (int i = 0; i < length; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j]; // overwrite key
            j--;
        }
        arr[j+1] = key; // +1 because we need to cancel out the j--
    }
}

// Q5 
// Write a function that, without using strlen, returns the length of a string given by a pointer 
// to the first character in a string
// What is the runtime complexity of this function?

int length_of_string(char *first) {
    int i = 0;
    while (*(first + i) != '\0') {
        i++;
    }
    return i;
}

// O(n)

// Q6
// Write a function void seq_replace(int *arr1, unsigned long arr1_sz, int *arr2. unsigned long arr2_sz)
// which takes in two arrays arr1 and arr2 and their sizes, and replaces every appearances of arr2 in arr1 with all 0’s.
// For example:
// int a[] = {5, 6, 7, 8, 6, 7};
// int b[] = {6, 7};
// seq_replace(a, 6, b, 2);
// should result in a being {5, 0, 0, 8, 0, 0}
// What is the runtime complexity of this function?

void seq_replace(int *arr1, unsigned long arr1_sz, int *arr2, unsigned long arr2_sz) {
    printf("Function called\n");
    int k;
    for (int i = 0; i <= arr1_sz - arr2_sz; i++) {
        int mismatch = 0;
        // printf("in for loop");
        for (int j = 0; j < arr2_sz; j++) {
            // printf("in nested for loop");
            if (j == arr2_sz - 1 && mismatch == 0) {
                if (arr1[i + j] == arr2[j]) {
                    for (k = i + j; k < i; k--) {
                        arr1[k] = 0;
                        printf("wooooooooooooooooo");
                    }
                }
            } else if (j != arr2_sz) {
                if (arr1[i + j] != arr2[j]) {
                    mismatch = 1;
                    printf("mismatch");
                }
            }
        }
    }
}

int main() {
    int a[] = {5, 6, 7, 8, 6, 7};
    int b[] = {6, 7};
    seq_replace(a, 6, b, 2);
    for (int i = 0; i < 6; i++) {
        printf("%d", a[i]);
    }
}