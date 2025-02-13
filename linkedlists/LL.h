#if !defined(LL_H)

typedef struct node {
    struct node *next; // a pointer to itself must refer to itself by full name so struct node
    int data;
} node;

typedef struct LL {
    node *head;
    int sz;
} LL;

void create_LL_from_data(LL **p_LL int *data_arr, int size);
// how we use create_LL_from_data()
// int main() {
//     LL *myLL;
//     create_LL_from_data(&myLL);
// }

void create_node(node **n, int data);

#endif