#if !defined(LL_H)

typedef struct node {
    struct node *next; // a pointer to itself must refer to itself by full name so struct node
    int data;
} node; // when do you write node versus not write anything

typedef struct LL {
    node *head;
    int sz;
} LL;

// LL will contain the head pointer: address of the first node in the linked list
// Each node has data as well as the address of the next node

void create_LL_from_data(LL **p_LL int *data_arr, int size);
// how we use create_LL_from_data()
// int main() {
//     LL *myLL;
//     create_LL_from_data(&myLL);
// }

void create_node(node **n, int data);

#endif