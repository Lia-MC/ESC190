// Question 2. [10 marks]
// In C, write a function which takes in a string, and replaces every occurrence of "winter" (in lowercase)
// with "summer" (in lowercase).
// char s[] = "In the winter, I will rest and enjoy the sun. Winter is great!
// Wait, actually I mean winter."
// replace_ws(s);
// s is now "In the summer, I will rest and enjoy the sun. Winter is great!
// Wait, actually I mean summer."
// "Winter" with the upper-case W was not replaced.
// For this question, do not worry about newlines.

#include <stdio.h>
#include <stdlib.h>

void replace_ws(char *s) {
    int i = 0;
    char *winter = "winter";
    char *summer = "summer";
    while(s[i] != NULL) {
        int j = 0;
        int winterfound = 0;
        while (s[j] != '\0') { // cant say NULL for string null terminators in c apparently
            if (s[i + j] != winter[j]) {
                winterfound = 1;
            }
        }
        if (winterfound == 1) {
            while (s[j] != NULL) {
                s[i + j] = summer[j];
            }
        }
    }
}



// credit to copilot:
// personally i feel like uhm its maybe a lil too much???

#include <stdio.h>
#include <string.h>

void replace_ws(char *s) {
    char *pos;
    char winter[] = "winter";
    char summer[] = "summer";
    int winter_len = strlen(winter);
    int summer_len = strlen(summer);

    while ((pos = strstr(s, winter)) != NULL) {
        memmove(pos + summer_len, pos + winter_len, strlen(pos + winter_len) + 1);
        memcpy(pos, summer, summer_len);
    }
}

int main() {
    char s[] = "In the winter, I will rest and enjoy the sun. Winter is great! Wait, actually I mean winter.";
    replace_ws(s);
    printf("%s\n", s);
    return 0;
}
