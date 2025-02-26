// og strcpy:

// Parameters:
// dest: Pointer to the destination character array where the content is to be copied.
// src: Pointer to the source character array which is to be copied.

// Return Value:
// This function returns a pointer to dest string.


// my strcpy:

char *mystrcpy(char *dest, char *src) { // whats the data type for pointers? -> instead of void * we want char * or int *
    int i = 1; // accounts for null character
    while (src[i] != '\0') {
        i++;
    } // now we have i, the length of src including null character
    dest = (char *)malloc(i);
    int j = 0;
    while (src[j] != '\0') {
        dest[j] = src[j];
        j++;
    }
    dest[j] = '\0';
    return dest;
}