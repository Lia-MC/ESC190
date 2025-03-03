if !defined(Q)
#include "ArrayList.h"
#include "stdlib.h"
#define Q
typedef struct queue {
    AL *list;
} queue;

void create_queue(queue **q);
void enqueue(queue **q);
void destroy_queue(queue **q);
void dequeue(queue **q);


// void create_queue(queue **q) {
//     (*p_q) = malloc(sizeof(queue));
//     create_list(&((*p_q)->list));
// }

// void destroy_queue(queue **q) {
//     //
// }

#endif