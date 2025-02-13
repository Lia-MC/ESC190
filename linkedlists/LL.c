#include "LL.h"
#include <stdlib.h>

void create_node(node **p_n, int data) {
    *p_n = (node *)malloc(sizeof(node))
    (*p_n)->data = data;
    (*p_n)->next = NULL;
}

// repeatedly create nodes and chain to heads to create LL
void create_LL_from_data(LL **p_LL, int *data_arr, int size) {
    *p_LL = (LL *)malloc(sizeof(LL)); // create the linked list
    (*p_LL)->head = NULL;
    (*p_LL)->sz = size;

    // (*p_LL)->head is initially null but we want it to be address of first node

    int i = 0; // nodes inserted so far
    node *prev = NULL;
    while (i < size) {
        node *cur; // type node *
        create_node(&cur, data_arr[0]); // set cur to smth that makes sense
        if(i == 0) {
            (*p_LL)->head = cur; // assign valid address to head which is also type node *
        } else {
            prev->next = cur;
        }
        prev = cur;
        i++;
    } // keep setting head of previous node to address of new node thats been created


}
// call using create_LL_from_data(&LL, data_arr, size)

