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

// solution:
// int b = 44; p_a = &b; // a is still 43

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

int **p_p_a = &p_a; // how is this different from q8? its not, although define doesnt imply initialize

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

// solution:
void newaddysol(int **p_p_int) {
    *p_p_int = malloc(sizeof(int));
}

// Q12. Call the function from Q10 in order to change the value of a to 46. 
// Do this using p_p_a, and using p_a.

int main3() {
    int b = 33;
    int *p_b = &b;
    int **p_p_b = &p_b;
    changeto46(p_p_b);
    printf(b);

    // other way according to solution:
    changeto46(&p_b);
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

// wrong
int *arr = {5, 6, 7}; // when do i need to specify the number of elements in the array?

// solutions
// method 1:
int arr[] = {5, 6, 7};
// method 2:
int arr[3] = {5, 6, 7};
// lesson learned:
// when declaring and initializing arrays, dont use *, just use []

// Q16. Write a function that takes in a pointer to the first element of an array of integers 
// and modifies the element at index 2 to 8

void modifyto8(int *first) {
    first[2] = 8;

    // alternative solution:
    *(first + 2) = 8; // dereference the address at index first + 2
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

// Q5:
void changeint(int *p_point) {
    *p_point = 100;
}
// so:
int main8() {
    int *p_block = (int *)malloc(sizeof(int) * 3);
    changeint(p_block);
}

// Q20. Use change_int_ptr from Q11 to change the value of p_block to point to a new address

// Q11:
void newaddy(int **p_p_int) {
    int *newaddress = (int *)malloc(sizeof(int));
    *p_p_int = newaddress;
}
// so:
int main9() {
    int *p_block = (int *)malloc(sizeof(int) * 3);
    newaddy(&p_block);
}

// Q21. Create an object of type student, with char name[1000] and int age, and initialize it

// this is fine:
typedef struct student {
    char name[1000];
    int age;
} student;

// i am forgetting to initialize, i need to review this really badly
// student student1;
// student1.name = "Jenny";
// student1->age = 22;

// solution for the initializing part:
student student1 = {"Jenny", 22};

// Q22. Change the name of the student to "Jennifer"

// wrong 1:
// student1[0] = "Jennifer";

// wrong 2:
// char *newname = "Jennifer";
// *(student1) = newname;

// solution:
int main10() {
    student student2 = {"ellie", 13};
    strcpy(student2.name, "Jennifer");
}

// Q23. Change the age of the student to 21

int main11() {
    student student2 = {"tester", 0};
    student2.age = 21;
}

// Q24. Create a pointer p_s to the student and initialize it to the address of the student

int main12() {
    student stu = {"ahhh", 21};
    student *p_s = &stu;
}

// Q25. Change the name of the student to "Jenny", using p_s

int main13() {
    student stu = {"ahhh", 21};
    student *p_s = &stu;
    strcpy(p_s->name, "Jenny");
}

// Q26. Change the age of the student to 20, using p_s

int main14() {
    student stu = {"ahhh", 21};
    student *p_s = &stu;
    p_s->age = 20;
}
// Q27. Create a function that takes in a pointer to a student and changes the name to "Jenny"

void changetojenny(student *p_s) {
    strcpy(p_s->name, "Jenny");
}

// Q28. Create a function that takes in a pointer to a student and changes the age to 20

void changetotwenty(student *p_s) {
    p_s->age = 20;
}

// Q29. Call the function from Q27 in order to change the name of the student to "Jenny". Use p_s but not s

// Q27
void changetojenny(student *p_s) {
    strcpy(p_s->name, "Jenny");
}

int main15() {
    student *p_s = (student *)malloc(sizeof(student));
    changetojenny(&p_s); // wrong, it should be:
    changetojenny(p_s);
}

// Q30. Call the function from Q28 in order to change the age of the student to 20. Use s but not p_s

// Q28
void changetotwenty(student *p_s) {
    p_s->age = 20;
}
int main16() {
    student s = {"newstu", 100};
    changetotwenty(&s);
}

// Q31. Create an array of 5 student objects

// i think wrong:
void arroffivestu() {
    student *arrrrr[5] = (student *)malloc(sizeof(student) * 5);
}
// solution:
void rightarroffivestu() {
    student arr[5];
}

// Q32. Use the functions from Q27 and Q28 on the element at index 2 of the array

// Q27
void changetojenny(student *p_s) {
    strcpy(p_s->name, "Jenny");
}
// Q28
void changetotwenty(student *p_s) {
    p_s->age = 20;
}

int main17() {
    rightarroffivestu();
    // arr[2];
    // student *p_s = (student *)malloc(sizeof(student));
    changetojenny(arr[2]); // this is wrong because im passing in the student object located at index 2, recall i need addy
    changetotwenty(arr[2]);
}

// solution:
int main18() {
    changetojenny(&(arr[2]));
    changetotwenty(&(arr[2]));
    // or this is wrong:
    changetojenny(*arr + 2);
    changetotwenty(*arr + 2);
    // but this is right:
    changetojenny(arr + 2);
    changetotwenty(arr + 2);
}

// Q33. Create a malloc-allocated block of memory that can store 5 students. Store the address in the variable p_block_s

int main19() {
    student *p_block_s = (student *)malloc(5 * sizeof(student));
}

// Q34. Make a function that takes in a pointer to an address of student, 
// and sets that pointer to point to a new address where a student can be stored

void newaddyforstu(student **p_p_stu) {
    student *newaddy = (student *)malloc(sizeof(student));
    *p_p_stu = newaddy;
}

// Q35. Call the function from Q34 in order to change the value of p_block_s to point to a new address

// Q34
void newaddyforstu(student **p_p_stu) {
    student *newaddy = (student *)malloc(sizeof(student));
    *p_p_stu = newaddy;
}

int main20() {
    student *p_block_s = (student *)malloc(5 * sizeof(student));
    newaddy(&p_block_s); // yeah this is right, i want to send in a student ** so that means i need to take the addy of p_block_s
}

// Q36. Call the function from Q27 in order to change the name of the student at index 2 of the 
// block of memory from Q33. Use p_block_s

// Q27
void changetojenny(student *p_s) {
    strcpy(p_s->name, "Jenny");
}
int main21() {
    student *p_block_s = (student *)malloc(5 * sizeof(student));
    changetojenny(p_block_s + 2); 
    // or 
    changetojenny(&(p_block_s[2]));
}

// Q37. Create a variable p_p_s to store the address of p_block_s

int main22() {
    student *p_block_s = (student *)malloc(sizeof(student) * 5);
    student **p_p_s = &p_block_s;
}

// Q38. Without calling any function except strcpy, and using only p_p_s, change the name of the student at index 2 to "Jennifer"

int main23() {
    student *p_block_s = (student *)malloc(sizeof(student) * 5);
    student **p_p_s = &p_block_s;
    // wrong, if im using [2] i need to use . because its an object, if im using + 2 then i should use -> because pointer
    //strcpy(((*p_p_s)[2])->name, "Jennifer");
    
    // solutions:
    strcpy(((*p_p_s) + 2)->name, "Jennifer"); 
    // or 
    strcpy((*p_p_s)[2].name, "Jennifer");

}

// Q39. In the name of the second student in the block pointed to by p_p_s, change the first letter to 'j'. 
// Propose four valid ways to do that with one line that don't involve calling a function

int main24() {
    student *p_block_s = (student *)malloc(sizeof(student) * 5);
    student **p_p_s = &p_block_s;

    // method 1:
    ((*p_p_s)+1)->name[0] = 'j';

    // method 2:
    ((*p_p_s)[1]).name[0] = 'j';

    // BAD method 3:
    // &(((*p_p_s)+2)->name) = 'j';

    // method 3:
    (p_p_s[0])[1].name[0] = 'j';

    // method 4: // i think this is wrong
    ((p_p_s[0])+1)->name[0] = 'j';


    // solutions:
    ((*(p_p_s))[1]).name[0] = 'j'; // my method 2
    (*p_p_s + 1)->name[0] = 'j'; // my method 1
    (*(*p_p_s + 1)).name[0] = 'j'; // what i tried to do in method 4
    p_p_s[0][1].name[0] = 'j'; // my method 3
}

// Q40. Write a function that takes in a pointer to the first element of a block of addresses of students, 
// and changes the name of the student at index 2 to "Jenny"

void ind2tojenny(student **p_block_s) {
    // student *p_block_s = (student *)malloc(5 * sizeof(student));

    // remember, for any strings, you always have to strcpy it
    // p_block_s[2].name = "Jenny";
    // (p_block_s + 2)->name = "Jenny";
    
    // my solution
    // strcpy((p_block_s + 2)->name, "Jenny"); // this is for an arry of stus

    // solution:
    // student **p_p_s = (student **)malloc(sizeof(student *) * 5);
    // strcpy(p_p_s[2]->name, "Jenny");
    strcpy(p_block_s[2]->name, "Jenny");
}

// Q41. Create a pointer to a block of 10 pointers to students, and store it in the variable p_block_addr_s

int main25() {
    student **p_block_addr_s = (student **)malloc(10 * sizeof(student *));
}

// Q42. Call the function from Q40 in order to change the name of the student at index 2. Use p_block_addr_s

// Q40
void ind2tojenny(student **p_p_s) {
    strcpy(p_p_s[2]->name, "Jenny");
}
int main26() {
    student **p_block_addr_s = (student **)malloc(10 * sizeof(student *));
    ind2tojenny(p_block_addr_s);
}

// Q43. Write a function that takes in the first address of a student in a block of addresses of students, 
// and changes the name of the student at index 2 to "Jenny"

void morejenny(student **p_block_addr_s) {
    strcpy((*(p_block_addr_s + 2))->name, "Jenny");
}

// solution (equivalent to my solution):
void change_name3(student **p_block_addr_s) {
    strcpy(p_block_addr_s[2]->name, "Jenny");  
}


// Q44. Call the function from Q43 in order to change the name of the student at index 2. Use p_block_addr_s

int main27() {
    student **p_block_addr_s = (student **)malloc(10 * sizeof(student *));
    strcpy((*(p_block_addr_s+2))->name, "Jenny");
    // or equialently:
    change_name3(p_block_addr_s);
}