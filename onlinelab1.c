// Q0 (not graded)
// ===========
// Make sure that you can run and compile a Hello World program in VS Code.

void helloworld() {
    printf("%s\n", "Hello World");
}

// Q1
// ===
// Write the function 

// The function returns the index of the first occurrence of the element elem 
// in a block of ints a of size sz. Assume elem occurs in a.

int linear_search(int *a, int sz, int elem) {
    int i = 0;
    while(*(a + i) != elem) {
        i++;
    }
    return i;
}


// Q2
// ====
// Write the following function, which reverses the block of ints arr, 
// which is of size sz. For example, if arr starts out as {5, 6, 7, 8}, 
// it should become {8, 7, 6, 5}

void reverse_arr(int *arr, int sz) {
    int *new = (int *)malloc(sz * sizeof(int));
    int z = 0;
    for(int j = sz - 1; j >= 0; j--) {
        new[j] = *(arr + z);
        z++;
    }
    for(int k = 0; k < sz; k++) {
        *(arr + k) = new[k];
    }
}

int main() {
    int newarr[] = {5, 6, 7, 8, 9};
    int size = 5;
    reverse_arr(&newarr, size);
    // for(int l = 0; l < size; l++) {
    //     printf("%d", newarr[l]);
    // }

    return 0;
}

// void reverse_arr(int *arr, int sz) {
//     //
// }

// void reverse_arr(int *arr, int sz) {
//     int *new = (int *)malloc(sz);// size of??
//     int z = 0;
//     for(int j = sz - 1; j = 0; j--) {
//         new[j] = *(arr + z);
//         z++;
//     }
//     for(int k = 0; k < sz; k++) {
//         *(arr + k) = new[k];
//     }
// }


// int main() {
//     int newarr = {5, 6, 7, 8, 9};
//     int size = 5;
//     reverse_arr(&newarr, size);
//     for(int l = 0; l < size; l++) {
//         printf("%d", newarr[l]);
//     }

//     return 0;
// }