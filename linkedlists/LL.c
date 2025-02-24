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

void get_i(LL *p_LL, int i) {
    if (p_LL->sz >= i) {
        exit(1);
    }
    int j = 0;
    node *cur = p_LL->head;
    while (j < i) {
        cur = cur->next;
    }
    // after ive run the while loop, cur is the nth node that contains the ith elem
    return cur->data;
}

void append(LL *p_LL, int data) {
    // my sol:
    // int j = 0;
    node *cur = p_LL->head;
    // while (j != '\0') {
    //     cur = cur->next;
    // }

    // his sol:
    if (p_LL->head == NULL) {
        node *newnode;
        create_node(&newnode, data);
        p_LL->head= newnode;
        return;
    }
    while (cur->next != NULL) {
        cur = cur->next;
    }
    node *newnode;
    create_node(&newnode, data);
    cur->next = newnode;
    p_LL->sz += 1;
}

int main() {
    int data_ints[] = {5, 10, 23, 10, 24};
    LL *p_LL; // a random address 
    create_LL_from_data(&p_LL, data_ints, sizeof(data_ints) / sizeof(int)); // if it's an array defined IN MAIN i can do this if not i cant

}