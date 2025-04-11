#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Q1. Define an integer variable a and initialize it to 42

int a = 42;

// Q2. Define a pointer to an integer variable p_a and initialize it to the address of a

int *p_a = &a;

// Q3. Using p_a and without directly using a, change the value of a to 43

*p_a = 43;

// Q4. Change the value of the pointer p_a to something else. 
// Make sure that the value of a does not change

p_a = 10;

// Q5. Define a function that takes in a pointer to an integer and changes the integer

void changeint(int *p_point) {
    *p_point = 100;
}

// Q6. Call the function from Q5 and pass in the address of a. Make sure that the value of a changes

int main1() {
    changeint(&a);
}

// Q7. Call the function named change_int without directly using a, but using p_a instead

int main2() {
    changeint(p_a);
}

// Q8. Define a variable that would store the address of p_a

int **p_p_a = &p_a;


// Q9. make p_p_a point to p_a

int **p_p_a = &p_a; // how is this different from q8?

// Q10. Write a function that takes in a pointer to a pointer to an integer and 
// changes the value of the integer to 46

void changeto46(int **p_p_int) {
    **p_p_int = 46;
}


// Q11. Write a function that takes in a pointer to a pointer to an integer and 
// changes the value of the pointer to a new address where an integer can be stored. 
// (You will need to use malloc)

void newaddy(int **p_p_int) {
    int *newaddress = (int *)malloc(sizeof(int));
    *p_p_int = newaddress;
}

// Q12. Call the function from Q10 in order to change the value of a to 46. 
// Do this using p_p_a, and using p_a.

int main3() {
    int b = 33;
    int *p_b = &b;
    int **p_p_b = &p_b;
    changeto46(p_p_b);
    printf(b);
}

// Q13. Call the function from Q11 in order to change the value of p_a to point to a new address. Don't use p_p_a.

int main4() {
    newaddy(&p_a);
}

// Q14. Call the function from Q11 in order to change the value of p_a to point to a new address. Use p_p_a.

int main5() {
    newaddy(p_p_a);
}

// Q15. Declare an array of integers and initialize it to {5, 6, 7}

int *arr = {5, 6, 7}; // when do i need to specify the number of elements in the array?

// Q16. Write a function that takes in a pointer to the first element of an array of integers 
// and modifies the element at index 2 to 8

void modifyto8(int *first) {
    first[2] = 8;
}

// Q17. Call the function from Q16 in order to change the value of an element of the array from Q15

int main6() {
    modifyto8(arr);
    printf(arr[2]);
}

// Q18. Create a malloc-allocated block of memory that can store 3 integers. Store the address in the variable p_block. 
// Then use modifyelem to change the value at index 2

int main7() {
    int *p_block = (int *)malloc(sizeof(int) * 3);
    modifyto8(p_block);
}

// Q19. Use change_int from Q5 to change the value of the integer stored in the block of memory from Q18

//////////////

// Q20. Use change_int_ptr from Q11 to change the value of p_block to point to a new address

//////////////

// Q21. Create an object of type student, with char name[1000] and int age, and initialize it

typedef struct student {
    char name[1000];
    int age;
} student;

// i am forgetting to initialize, i need to review this really badly
student student1;
student1.name = "Jenny";
student1->age = 22;

// Q22. Change the name of the student to "Jennifer"

student1

// Q23. Change the age of the student to 21

//////////////

// Q24. Create a pointer p_s to the student and initialize it to the address of the student

//////////////

// Q25. Change the name of the student to "Jenny", using p_s

//////////////

// Q26. Change the age of the student to 20, using p_s

//////////////

// Q27. Create a function that takes in a pointer to a student and changes the name to "Jenny"

//////////////

// Q28. Create a function that takes in a pointer to a student and changes the age to 20

//////////////

// Q29. Call the function from Q27 in order to change the name of the student to "Jenny". Use p_s but not s

//////////////

// Q30. Call the function from Q28 in order to change the age of the student to 20. Use s but not p_s

//////////////

// Q31. Create an array of 5 student objects

//////////////

// Q32. Use the functions from Q27 and Q28 on the element at index 2 of the array

//////////////

// Q33. Create a malloc-allocated block of memory that can store 5 students. Store the address in the variable p_block_s

//////////////

// Q34. Make a function that takes in a pointer to an address of student, 
// and sets that pointer to point to a new address where a student can be stored

//////////////

// Q35. Call the function from Q34 in order to change the value of p_block_s to point to a new address

//////////////

// Q36. Call the function from Q27 in order to change the name of the student at index 2 of the 
// block of memory from Q33. Use p_block_s

//////////////

// Q37. Create a variable p_p_s to store the address of p_block_s

//////////////

// Q38. Without calling any function except strcpy, and using only p_p_s, change the name of the student at index 2 to "Jennifer"

//////////////

// Q39. In the name of the second student in the block pointed to by p_p_s, change the first letter to 'j'. 
// Propose four valid ways to do that with one line that don't involve calling a function

//////////////

// Q40. Write a function that takes in a pointer to the first element of a block of addresses of students, 
// and changes the name of the student at index 2 to "Jenny"

//////////////

// Q41. Create a pointer to a block of 10 pointers to students, and store it in the variable p_block_addr_s

//////////////

// Q42. Call the function from Q40 in order to change the name of the student at index 2. Use p_block_addr_s

//////////////

// Q43. Write a function that takes in the first address of a student in a block of addresses of students, 
// and changes the name of the student at index 2 to "Jenny"

//////////////

// Q44. Call the function from Q43 in order to change the name of the student at index 2. Use p_block_addr_s

//////////////