// og strcat

// Parameters: 
// dest: This is a pointer to the destination array, which should contain a C string, and should be large enough to contain the concatenated resulting string.
// src: This is the string to be appended. This should not overlap the destination.

// Return value:
// The strcat() function returns dest, the pointer to the destination string.


// my strcat:

char *mystrcat(char *dest, char *src) {
    int i = 0;
    int d_sz = strlen(dest);
    int s_sz = strlen(src);
    char *temp = (char *) malloc(d_sz + s_sz + 1);
    strcpy(temp, dest);
    dest = (char *) malloc(d_sz + s_sz + 1);
    strcpy(dest, temp);
    
    while (dest[i] != '\0') {
        i++;
    }
    int j = 0;
    while(src[j] != '\0') {
        dest[i] = src[j];
        i++;
        j++;
    }
    dest[i] = '\0';
    return dest;
}


// not accounting for the potential lack of space in dest

// char *mystrcat(char *dest, char *src) {
//     int i = 0;
//     while (dest[i] != '\0') {
//         i++;
//     }
//     int j = 0;
//     while(src[j] != '\0') {
//         dest[i] = src[j];
//         i++;
//         j++;
//     }
//     dest[i] = '\0';
//     return dest;
// }

// i needed to refer to the logic to understand what this actually does:
// C strcat() function appends the string pointed to by src to the end of the string pointed to by dest. 
// It will append a copy of the source string in the destination string. plus a terminating Null character. 
// The initial character of the string(src) overwrites the Null-character present at the end of the string(dest).


// draft

// char *mystrcat(char *dest, char *src) {
//     int available = 0;
//     int i = 0;
//     while (dest[i] != '\0') {
//         i++;
//     }
//     w
//     return dest;
// }