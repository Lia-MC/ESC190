// qsort + comp syntax
int comp(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}
int comp(const void *a, const void *b) {
    term *term_a = (term *)a;
    term *term_b = (term *)b;
    return strcmp(term_a->term, term_b->term);
}
// Less than zero (<0): If the first argument should be placed before the second argument.
// Zero (0): If both arguments are equal.
// Greater than zero (>0): If the first argument should be placed after the second argument.
qsort(arr, n, size, comp);
// Parameters:
// arr: Pointer to the first element of the array.
// n: Number of elements in the array.
// size: Size of each element.
// comp: Function pointer to a comparison function/comparator.
// NO RETURN

// when you're working with lists, make sure that malloc has been done 
// (condition for no malloc necessary: ___________________________________)

// when you have a malloc, make sure to free it

// add null character at the end of arrays

FILE *fp = fopen(filename, "r"); // check this syntax
fclose(fp); // close filepath

// proj 1 takeaways
// binary search takeaways
