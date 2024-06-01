#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int pno;
    int data;
}node;

typedef struct priorityQueue{
    int capacity;
    int index;
    node* ptr;
}priorityQueue;

// creating a pQueue


priorityQueue* createQ(int capacity){
    priorityQueue* pq = (priorityQueue*)malloc(sizeof(priorityQueue));
    pq->capacity = capacity;
    pq->index = -1;
    pq->ptr = (node*)malloc(sizeof(node) * capacity);
    return pq;
}

// inserting data in PQueue


void insert(priorityQueue* pq, int data, int pno){
    if(pq == NULL){
        printf("ERROR: pQueue is not created yet.\n");
        return;
    }else if(pq->index == pq->capacity-1){
        pq->capacity *=2; 
        node* temp = (node*)realloc(pq->ptr,sizeof(node) * (pq->capacity));
        if(temp == NULL){
            printf("ERROR: PQueue is full and Reallocation failed.\n");
            return;
        }
        pq->ptr = temp;
    }
    pq->index++;
    pq->ptr[pq->index].data = data;
    pq->ptr[pq->index].pno = pno;
    int i = pq->index;
    while(i > 0){
        if(pq->ptr[(i-1)/2].pno >= pq->ptr[i].pno){
            break;
        }
        node temp = pq->ptr[(i-1)/2];
        pq->ptr[(i-1)/2] = pq->ptr[i];
        pq->ptr[i] = temp;
        i = (i-1)/2;
    }
}


// Note : Why i used " . " instead of " -> " in insert() function.

// The -> operator is used to access members of a struct through a pointer to that struct.
// The . operator is used to access members of a struct when you have a direct instance of that struct, 
// not a pointer.

// In my code, pq->ptr is a pointer to an array of node structs. When you access pq->ptr[i], you get a 
// direct instance of the node struct, not a pointer to it. Therefore, you should use the . operator to access 
// its members.


//*** deleting data in pQueue***

void delete(priorityQueue* pq) { 
    if(pq == NULL) {
        printf("ERROR: Pqueue is not created Yet.\n");
        return;
    } else if(pq->index == -1){
        printf("ERROR: PQueue is Empty.\n");
        return;
    } else if(pq->index == 0) {
        pq->index = -1;
    } else {
        node temp = pq->ptr[pq->index];
        pq->index--;
        pq->ptr[0] = temp;
        int i = 0;
        while(1){
            int left = 2 * i + 1;
            int right = 2* i + 2;  
            int largest = i;
            if(left < pq->index && pq->ptr[left].pno > pq->ptr[i].pno ){
                largest = left;
            } 
            if(right < pq->index && pq->ptr[right].pno > pq->ptr[i].pno ){
                largest = right;
            }
            if(largest != i){
                pq->ptr[i] = pq->ptr[largest];
                pq->ptr[largest] = temp;
                i = largest;
            } else {
                break;
            }
        }
    }
}


// function to display Queue

void display(priorityQueue* pq) {
    if (pq == NULL) {
        printf("ERROR: pQueue is not created yet.\n");
        return;
    }
    printf("Priority Queue:\n");
    for (int i = 0; i <= pq->index; i++) {
        printf("Data: %d, Priority: %d\n", pq->ptr[i].data, pq->ptr[i].pno);
    }
}

int main() {
    priorityQueue* pq = createQ(5);
    insert(pq, 10, 2);
    insert(pq, 20, 1);
    insert(pq, 30, 3);
    insert(pq, 40, 2);
    insert(pq, 50, 1);
    display(pq);
    delete(pq);
    display(pq);
    delete(pq);
    display(pq);
    delete(pq);
    display(pq);
    delete(pq);
    delete(pq);
    delete(pq);

    // Free the allocated memory
    free(pq->ptr);
    free(pq);

    return 0;
}