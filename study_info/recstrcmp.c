// strcmp recursive

// strcmp returns 1 if str2 is earlier in alphabet, -1 if str1 is earlier in the alphabet, 0 if equal

int myrecstrcmp(char *str1, char *str2) {
    if (str1[0] == '\0' && str2[0] != '\0') {
        return -1;
    } else if (str2[0] == '\0' && str1[0] != '\0') {
        return 1;
    } else if (str1[0] == '\0' && str2[0] == '\0') {
        return 0;
    } else if (str1[0] > str2[0]) {
        return 1;
    } else if (str2[0] > str1[0]) {
        return -1;
    } else {
        return myrecstrcmp(str1 + 1, str2 + 1);
        // return (myrecstrcmp(str1[1], str2[1])); // wrong, this is just the next char but i want to pass next char's pointer
    }
}