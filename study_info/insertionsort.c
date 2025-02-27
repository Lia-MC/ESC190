// Question 4.
// Implement a function that performs https://en.wikipedia.org/wiki/Insertion_sort#Algorithm. The
// function should take in an array of integers, and modify the array so that it’s sorted in increasing order.
// Here is code to print out an array of integers using a for-loop and a while-loop in C.
// int i = 0;
// int a[5] = {2, 3, 4, 5, 6};
// // initialize i to 0, run the loop while i < 5, and increase i by 1 every time;
// // Here, i++ is the same as i = i + 1
// for(i = 0; i < 5; i++){
//     printf("%d\n", a[i]);
// }
// i = 0;
// while(i < 5){
//     printf("%d\n", a[i]);
//     i++; // same as i = i + 1
// }

#include <stdio.h>

void myinsertionsort(int *arr) {
    int i = 1; // if there's only one element it's always sorted
    int cur_elem;
    int prev_elem;
    int temp;
    int j;
    while (*(arr[i + 1]) != NULL) {
        cur_elem = arr[i];
        prev_elem = arr[i - 1];
        j = 1;
        while (cur_elem < prev_elem) {
            temp = cur_elem;
            arr[i] = prev_elem;
            arr[i - 1] = temp;
            prev_elem = arr[i - 1 - j];
            j++;
        }
        i++;
    }
    while (*(arr[i]) != NULL) {
        printf("%d\n" ,arr[i]);
    }
}

int main() {
    int *arr = {2, 6, 7, 2, 8, 3, 9, 1};
    myinsertionsort(arr);
}

Pseudocode for Insertion Sort
Initialization:

Start with the second element of the array (index 1) since the first element (index 0) is trivially sorted.

Outer Loop:

Iterate through the array from the second element to the last element.

For each element at index i (the "current element"), perform the following steps to place it in the correct position among the previously sorted elements.

Inner Loop (Shifting Elements):

Store the value of the current element in a temporary variable temp.

Initialize a variable j to the index just before i (i.e., i - 1).

While j is greater than or equal to 0 and the element at index j is greater than temp:

Shift the element at index j to index j + 1.

Decrement j to compare the next element in the previous sorted portion.

When the correct position for temp is found (i.e., when the loop condition is no longer met), place temp at index j + 1.

Repeat:

Repeat the outer loop until all elements have been processed and placed in their correct positions.

End:

The array is now sorted in ascending order.