#include <stdio.h>
#include <stdlib.h>
// Write a function that takes in a filename of a text file, and prints the file’s contents.

void printfilecontents(char *filename) {
    // load file
    // open file
    // go through line by line
    // print each line 
    FILE *fp = fopen(filename, "r");
    char line[200]; // how do we do unlimited...??
    // printf("%s", fgets(line, sizeof(line), fp)); // only gets ONE line
    char *curline = fgets(line, sizeof(line), fp);
    while (curline != NULL) { // fgets returns null when reached end of file
        printf("%s", curline);
        curline = fgets(line, sizeof(line), fp);
    }
    fclose(fp);
}


// Write a function that takes in a filename that contains integers, one integer per line, and outputs the
// average of those integers. You can use the library function atoi

void averageintsfromfile(char *filename) {
    // initialize sum and counter to 0
    // go through line by line
    // for each line, go until newline char, and do atoi to convert the string of numbers to an int
    // add the int to the sum and increment counter
    // print the average

    int sum = 0;
    int counter = 0;

    FILE *fp = fopen(filename, "r");
    char line[200];
    char *curline = fgets(line, sizeof(line), fp);
    while (curline != NULL) {
        counter++;
        sum = sum + atoi(curline);
        printf("%d, %d, \n", counter, sum);
        curline = fgets(line, sizeof(line), fp);
    }

    printf("%f", ((float) sum / counter)); // make sure at least one of the values in division is float if you want float result

    fclose(fp);

}

int main() {
    // printfilecontents("testing.txt");
    averageintsfromfile("testavg.txt");
}


// hints:

// - The following code can be used to read in N lines of a text file line-by-line.
// char line[200];
// FILE *fp = fopen(filename, "r");
// for(int i = 0; i < N; i++){
// fgets(line, sizeof(line), fp); //read in at most sizeof(line) characters
// //(including ’\0’) into line.
// }
// fclose(fp);

// - The function fgets returns NULL when it has reached the end of the file, so you can use
// while(fgets(line, sizeof(line), fp)) {
// ... process line
// }
// in order to process all the lines in the file.