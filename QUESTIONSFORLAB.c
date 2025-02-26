// 1. When do know to cast a malloc (when do I need to be explicit about the types)?
*p_LL = (LL *)malloc(sizeof(LL)); // do this every time
// versus
*p_LL = malloc(sizeof(LL));

// 2. When do we write the type after we write typedef?
// eg.
typedef struct person {
    char name[10];
    int age;
} person; // can use as just person
// versus
typedef struct person {
    char name[10];
    int age;
}; // have to use as struct person

// 3. What's the difference between when we write the typedef in a header file versus in the same file as main?
nothing

// 4. when to use . versus ->

void change_age(person *p, int a){
    (*p).age = a; // this and
    p->age = a; // this are
    // the exact same
}

person p;
person *personsaddres = &p;
int i;
p.name = 
p.age = 
person* p = (person*) malloc(sizeof(person));



person p;
p.name = 
p.age = 

int i = 0;

person* p = (person*) malloc(sizeof(person));
int* i_ptr = (int*)malloc