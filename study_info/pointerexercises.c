#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Q1. Define an integer variable a and initialize it to 42

int a = 42;

// Q2. Define a pointer to an integer variable p_a and initialize it to the address of a

int *p_a = &a;

// Q3. Using p_a and without directly using a, change the value of a to 43

*p_a = 43;

// Q4. Change the value of the pointer p_a to something else. Make sure that the value of a does not change

p_a = 4034542; // note this causes a memory leak, value of a isn't stored anywhere
// OR
int b = 44;
p_a = &b; // this prevents the value of a from being changed, a is still 43

// Q5. Define a function that takes in a pointer to an integer and changes the integer

void change_int(int *p_b) {
    *p_b = 3;
}

// Q6. Call the function from Q5 and pass in the address of a. Make sure that the value of a changes

int main() {
    change_int(&a);
    printf("%d\n", a); 
}

// Q7. Call the function named change_int without directly using a, but using p_a instead

int main2() {
    change_int(p_a);
    printf("%d\n", a); 
}

// Q8. Define a variable that would store the address of p_a

long int address_of_a = &p_a; // might not be wrong but not the "correct answer"
int **p_p_a = &p_a; // this is right, because p_a is of type int *

// Q9. make p_p_a point to p_a

// p_p_a->p_a; // wrong
p_p_a = &p_a; // "point to" means "set it to address of"

// Q10. Write a function that takes in a pointer to a pointer to an integer and changes the value of the integer to 46

void change_to_46(int **p_p_x) {
    *(*p_p_x) = 46; // i think this is fine
    **p_p_x = 46; // but this works too, and actually this works better
}

// Q11. Write a function that takes in a pointer to a pointer to an integer and 
// changes the value of the pointer to a new address where an integer can be stored. (You will need to use malloc)

void changeintaddress(int **p_p_int) {
    int *newmem = (int *)malloc(sizeof(int));
    *p_p_int = &newmem;
    // OR BETTER:
    *p_p_int = malloc(sizeof(int));
}

// Q12. Call the function from Q10 in order to change the value of a to 46. Do this using p_p_a, and using p_a.

int main3() {
    int c = 43;
    int *p_c = &c;
    int **p_p_c = &p_c;
    change_to_46(p_p_c);
    // could also do:
    change_to_46(&p_c);
}

// Q13. Call the function from Q11 in order to change the value of p_a to point to a new address. Don't use p_p_a.

int main4() {
    int d = 23;
    int *p_d = &d;
    changeintaddress(&p_d);
}

// Q14. Call the function from Q11 in order to change the value of p_a to point to a new address. Use p_p_a.

int main5() {
    int e = 23;
    int *p_e = &e;
    int **p_p_e = &p_e;
    changeintaddress(p_p_e);
}

// Q15. Declare an array of integers and initialize it to {5, 6, 7}

int main6() {
    // wrong initial guess:
    // int *[] = {5, 6, 7}; 
    // star wasn't needed, needed the array's name

    // proper way:
    int arr[3] = {5, 6, 7}; 
    // or 
    int arr2[] = {5, 6, 7};
}

// Q16. Write a function that takes in a pointer to the first element of an array of integers 
// and modifies the element at index 2 to 8

void modifyelem(int *first) {
    *(first + 2) = 8; // did this on my own
    // or:
    first[2] = 8; // answer key inspired
}

// Q17. Call the function from Q16 in order to change the value of an element of the array from Q15

int main7() {
    int arr3[] = {5, 6, 7};

    // my answer
    modifyelem(&arr3); 

    // better answer
    modifyelem(arr3); 
    // if you wanna modify elem in array, just pass in the array name,
    // the address will figure itself out
    
    // explanation
    // Note that if arr3 is an array (not a pointer returned by malloc), &arr3 would also work here, 
    // and arr3 and &arr3 are the same thing. But if arr3 is a pointer, then arr3 and &arr3 are different)

}

// Q18. Create a malloc-allocated block of memory that can store 3 integers. Store the address in the variable p_block. 
// Then use modifyelem to change the value at index 2

int main8() {
    int *p_block = malloc(sizeof(int) * 3);
    modifyelem(p_block);
}

// Q19. Use change_int from Q5 to change the value of the integer stored in the block of memory from Q18

// void change_int(int *p_b) {
//     *p_b = 3;
// }

int main9() {
    // my solution
    int *p_blockkk = malloc(sizeof(int) * 3);
    // modifyelem(p_blockkk);
    change_int(*(p_blockkk + 2));

    // answer key
    change_int(p_blockkk);
}

// Q20. Use change_int_ptr from Q11 to change the value of p_block to point to a new address

// void changeintaddress(int **p_p_int) {
//     int *newmem = (int *)malloc(sizeof(int));
//     *p_p_int = &newmem;
//     // OR BETTER:
//     *p_p_int = malloc(sizeof(int));
// }

int main10() {
    int *p_block2 = malloc(sizeof(int) * 3);
    changeintaddress(&p_block2);
}

// Q21. Create an object of type student, with char name[1000] and int age, and initialize it

// my attempt:
// typedef student s1(char *theirname, int theirage) {
//     char name[1000] = theirname;
//     int age;
// } student

// solutions:
typedef struct student{ // don't need ()
    char name[1000];
    int age;
}; // need a semi colon at the end

// initializing it:
// student s = {"Jenny", 20}; 
// technically undefined but this would be called in a diff file from header file and header is where typedef is stored

// Q22. Change the name of the student to "Jennifer"

void changename() {
    typedef struct student{ // don't need ()
    char name[1000];
    int age;
    };

    student s = {"Jenny", 20}; 

    // my solution:
    // s->name = "Jennifer";

    // real solution:
    strcpy(s.name, "Jennifer"); 
    // can't use equal sign, must use strcpy
    // if we do equals, it's only equal to the address of the first char but we need the whole memory to change from jenny to jennifer
}

// Q23. Change the age of the student to 21

void changeage() {
    typedef struct student{ // don't need ()
    char name[1000];
    int age;
    };

    student s = {"Jenny", 20}; 

    // my solution:
    // s->age = 6;

    // real solution:
    s.age = 6; // we don't have a pointer so we look at the age property of the student object
    // im pretty sure these are equivalent //  never mind

    // what i learned:
    // -> operator dereferences the pointer and accesses the member in a single operation.
    // . operator just accesses members of a structure or class when you have an instance (object) of that structure or class
}

// Q24. Create a pointer p_s to the student and initialize it to the address of the student

void create_p_s() {
    typedef struct student{ // don't need ()
    char name[1000];
    int age;
    };

    student s = {"Jenny", 20}; 

    student *p_s = &s;
}

// Q25. Change the name of the student to "Jenny", using p_s

void change_name_p_s() {
    typedef struct student{ // don't need ()
        char name[1000];
        int age;
    };

    student s = {"Jenny", 20}; 

    student *p_s = &s;

    // my answer:
    p_s->name = "Jenny"; // again, can't just do '='

    // right answer:
    strcpy(p_s->name, "Jenny"); // do strcpy for what i had before 
    // or 
    strcpy((*p_s).name, "Jenny"); // use address of pointer and get its property and change it

    // essentially, everything about changing the name of an object requires strcpy
}

// Q26. Change the age of the student to 20, using p_s

void change_age_p_s() {
    typedef struct student{ // don't need ()
        char name[1000];
        int age;
    };

    student s = {"Jenny", 20}; 

    student *p_s = &s;

    // my answer:
    *(p_s->age) = 20;

    // the solution:
    p_s->age = 20; // we have pointer of s so just p_s->age is fine
    // or 
    (*p_s).age = 20;
}

// LESSON LEARNED:
// if we have a pointer to the object, use -> to get the property, if we have the object, use . to get the property

// Q27. Create a function that takes in a pointer to a student and changes the name to "Jenny"

void change_to_jenny(student *p_s) {
    strcpy(p_s->name, "Jenny"); // YAY!
}

// Q28. Create a function that takes in a pointer to a student and changes the age to 20

void change_to_20(student *p_s) {
    p_s->age = 20; // good
}

// Q29. Call the function from Q27 in order to change the name of the student to "Jenny". Use p_s but not s

int main11() {
    typedef struct student {
        char name[1000];
        int age;
    };

    student s = {"aloha", 300};

    student *p_s = &s;

    change_to_jenny(p_s);
}

// Q30. Call the function from Q28 in order to change the age of the student to 20. Use s but not p_s

int main12() {
    typedef struct student {
        char name[1000];
        int age;
    };
    student newstu = {"lia", 39};
    change_to_20(&newstu);
}

// Q31. Create an array of 5 student objects

void create_arr_5_stus() {
    typedef struct student {
        char name[1000];
        int age;
    };

    student fivestudents[5]; // identifier name[#ofelems]
}

// Q32. Use the functions from Q27 and Q28 on the element at index 2 of the array

void change_vals() {
    typedef struct students {
        char name[1000];
        int age;
    };
    student fivestudents[5];

    // my ways:
    change_to_jenny(fivestudents[2]); // to do it properly, send in the address of this (address of elem at index 2)
    change_to_20(fivestudents[2]); // to do it properly, send in the address of this

    // solutions ways:
    change_to_jenny(&(fivestudents[2])); 
    // or 
    change_to_jenny(fivestudents + 2); // this works because fivestudents is the address of the elem at index 0

    change_to_20(fivestudents + 2); 
    // or 
    change_to_20(&(fivestudents[2]));
}

// Q33. Create a malloc-allocated block of memory that can store 5 students. Store the address in the variable p_block_s

void storesfivestudents() {
    typedef struct student {
        char name[1000];
        int age;
    };
    student *p_block_s = (student *)malloc(sizeof(student) * 5); 
    // i don't need to cast, it's the same type
    // pointer to void returned by malloc is automagically converted to the correct type

    // when do you cast a malloc?
    // only when you want the right-hand side and the left-hand side to be the same type explicitly
}

// Q34. Make a function that takes in a pointer to an address of student, 
// and sets that pointer to point to a new address where a student can be stored

// my solution is better than the website's
void newaddy(student **addy) {
    *addy = (student *)malloc(sizeof(student));
}

// solution:
// void create_student(student **p_p_s)
//         {
//             *p_p_s = malloc(sizeof(student));
//         }

// Q35. Call the function from Q34 in order to change the value of p_block_s to point to a new address

int main13() {
    typdef struct student {
        char name[12];
        int age;
    } student;
    student *p_block_s = (student *)malloc(sizeof(student) * 5);
    newaddy(&p_block_s); // yes this
}

// Q36. Call the function from Q27 in order to change the name of the student at index 2 of the 
// block of memory from Q33. Use p_block_s

// where: Q27. Create a function that takes in a pointer to a student and changes the name to "Jenny"
void change_to_jenny(student *p_s) {
    strcpy(p_s->name, "Jenny"); // YAY!
}

// and where Q33. Create a malloc-allocated block of memory that can store 5 students. Store the address in the variable p_block_s
void storesfivestudents() {
    typedef struct student {
        char name[1000];
        int age;
    };
    student *p_block_s = (student *)malloc(sizeof(student) * 5); 
}

int main14() {
    typedef struct student {
        char name[1000];
        int age;
    };
    student *p_block_s = (student *)malloc(sizeof(student) * 5);
    change_to_jenny(p_block_s[2]); // WRONG
    change_name(p_block_s + 2); // i needed to add 2 to the pointer itself
    // or 
    change_name(&(p_block_s[2])); // i needed to get the address of the 2nd index student because arr[ind] dereferences (finds the OBJECT)
}

// Q37. Create a variable p_p_s to store the address of p_block_s

student **p_p_s = &p_block_s; // perfect

// Q38. Without calling any function except strcpy, and using only p_p_s, change the name of the student at index 2 to "Jennifer"

strcpy(&(*p_p_s[2]), "Jennifer"); // WRONG because does not point to name property

// solution says:
strcpy(((*p_p_s) + 2)->name, "Jennifer"); // the pointer is dereferenced once to get index 0 addy, then add 2 for index 2
                                          // since it's a pointer, we can get the name of it using -> because it's not an object
// or 
strcpy((*p_p_s)[2].name, "Jennifer"); // go to the second object, then get the name using . since its an object

// Q39. In the name of the second student in the block pointed to by p_p_s, change the first letter to 'j'. 
// Propose four valid ways to do that with one line that don't involve calling a function

// my solutions:
(((*p_p_s)[2]).name)[0] = 'j';
(&((*p_p_s)[2]))->name[0] = 'j';

// solutions:
((*(p_p_s))[1]).name[0] = 'j'; // dereferences to get pointer to the first elem in block, access student at the index (object)
// get the name field of the object, and then get the first char in the name
(*p_p_s + 1)->name[0] = 'j'; // dereference block to get address of first elem of block and add one to get addy of second elem, 
// then using ->, dereference address and get name property at once and get first char in name
(*(*p_p_s + 1)).name[0] = 'j'; // dereference the address of the block to get the address of first elem, 
// then add 1 to get addy of second elem in the block, then dereference to get the object at that addy, and get the name of object
// using dot, then get the first char in name
p_p_s[0][1].name[0] = 'j'; // dereference using [0] to get the block object, and then get the first student object and 
// get its name property and get the first index of it

// Q40. Write a function that takes in a pointer to the first element of a block of addresses of students, 
// and changes the name of the student at index 2 to "Jenny"

void change2tojenny(student **p_block_addr_s) {
    ((*p_block_addr_s)[2]).name = "Jenny"; // WRONG // update i think this is equivalent
    strcpy((*p_block_addr_s) + 2, "Jenny"); // WRONG
    strcpy(p_p_s[2]->name, "Jenny");
    // just do strcpy for arrays of char
} // ask copilot if equivalent

// Q41. Create a pointer to a block of 10 pointers to students, and store it in the variable p_block_addr_s

student *p_block_ten = (student *) malloc(10 * sizeof(student));
p_block_ten_add = &p_block_ten;

// or per solution:
student **p_block_addr_s = malloc(10 * sizeof(student *)); // this does it all in one line

// Q42. Call the function from Q40 in order to change the name of the student at index 2. Use p_block_addr_s

change2tojenny(p_block_addr_s); // not change2tojenny(&p_block_addr_s); because its already the block address' address

// Q43. Write a function that takes in the first address of a student in a block of addresses of students, 
// and changes the name of the student at index 2 to "Jenny"

void index2tojenny(student *first) {
    strcpy((*(first + 2)).name, "Jenny");
}

// answer:
// void change_name3(student **p_block_addr_s)
//         {
//             strcpy(p_block_addr_s[2]->name, "Jenny");  
//         }

// Q44. Call the function from Q43 in order to change the name of the student at index 2. Use p_block_addr_s

change_name3(p_block_addr_s);


// ones to redo

// 36, 38

// Q36. Call the function from Q27 in order to change the name of the student at index 2 of the block of memory from Q33. 
// Use p_block_s

// where: Q27. Create a function that takes in a pointer to a student and changes the name to "Jenny"
void change_to_jenny(student *p_s) {
    strcpy(p_s->name, "Jenny"); // YAY!
}

// and where Q33. Create a malloc-allocated block of memory that can store 5 students. Store the address in the variable p_block_s
void storesfivestudents() {
    typedef struct student {
        char name[1000];
        int age;
    };
    student *p_block_s = (student *)malloc(sizeof(student) * 5); 
}

int main15() {
    student *block_s = (student *)malloc(sizeof(student) * 5);
    student **p_block_s = &block_s;

    
}

// Q38. Without calling any function except strcpy, and using only p_p_s, change the name of the student at index 2 to "Jennifer"

strcpy((p_p_s[2]).name, "Jennifer"); // close but i need to dereference first to get address of student at first index and then go on
strcpy(((*p_p_s) + 2)->name, "Jennifer"); 
// or 
strcpy((*p_p_s)[2].name, "Jennifer");