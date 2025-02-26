// og strcmp

// Parameters:
// s1: First string.
// s2: Second string.

// Return Value:
// Zero (0): It returns zero when all of the characters at given indexes in both strings are the same.
// Greater than Zero ( > 0 ): Returns a value greater than zero is returned when the first not-matching 
// character in s1 has a greater ASCII value than the corresponding character in s2.
// Lesser than Zero ( < 0 ): Returns a value less than zero is returned when the first not-matching 
// character in s1 has a lesser ASCII value than the corresponding character in s2.


// my strcmp:

// return 0 if same, 1 if s1 has GREATER ASCII VALUE (aka s2 comes first in alphabet), -1 if s1 comes first in alphabet

int mystrcmp(char *s1, char *s2) {
    int i = 0;
    while (s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] > s2[i]) {
            return 1; // s1 is greater ascii (aka comes later in alphabet)
        } else if (s1[i] < s2[i]) {
            return -1; // s1 is smaller ascii (aka comes earlier in alphabet)
        }
        i++;
    }
    if (s1[i] == '\0' && s2[i] != s1[i]) {
        return -1; // s1 ends first gj
    } else if (s2[i] == '\0' && s2[i] != s1[i]) {
        return 1; // s2 ends first gj
    }
    return 0; // theyre equal!
}