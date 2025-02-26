// og strlen:

// Parameters: 
// str: It represents the string variable whose length we have to find.

// Return Value:
// This function returns the integral length of the string passed.


// mystrlen:
int mystrlen(char *str) {
    int i = 0;
    while (str[i] != '\0') {
        i++;
    }
    return i;
}