#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    int pNo;
    struct node* next;
}Queue;

int isEmpty(Queue* Q);

void insertData(Queue** Q, int data, int pNo);

int maxPriorityNum(Queue* Q);

void deleteNode(Queue** Q);

void displayQueue(Queue* Q) {
    if (isEmpty(Q)) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Priority Queue:\n");
    while (Q != NULL) {
        printf("Data: %d, Priority: %d\n", Q->data, Q->pNo);
        Q = Q->next;
    }
}

int main(){
    Queue* pq = NULL;

    // Test case 1: Ascending Priority Numbers
    insertData(&pq, 10, 1);
    insertData(&pq, 20, 2);
    insertData(&pq, 30, 3);
    insertData(&pq, 40, 4);
    insertData(&pq, 50, 5);

    // Test case 2: Descending Priority Numbers
    insertData(&pq, 60, 5);
    insertData(&pq, 70, 4);
    insertData(&pq, 80, 3);
    insertData(&pq, 90, 2);
    insertData(&pq, 100, 1);

    // Test case 3: Random Priority Numbers
    insertData(&pq, 110, 3);
    insertData(&pq, 120, 1);
    insertData(&pq, 130, 5);
    insertData(&pq, 140, 2);
    insertData(&pq, 150, 4);

    // Display the priority queue after all insertions
    displayQueue(pq);

    printf("\nMax Num :  %d",maxPriorityNum(pq));

    deleteNode(&pq);
    return 0;
}

//to check is Queue is empty


int isEmpty(Queue* Q){
    if(Q == NULL){
        return 1;
    }
    return 0;
}

//to insert data in Priority-Queue


void insertData(Queue** Q, int data, int pNo){
    Queue* newNode = (Queue*)malloc(sizeof(Queue));
    newNode->data = data;
    newNode->pNo = pNo;
    
    if(isEmpty(*Q)){ //in case Queue is empty
        newNode->next = NULL;
        (*Q) = newNode;
    }
    else{
        if((*Q)->pNo < pNo){  
            //in case the the new element has higher priority then first element
            //in that case changes should be made to header.
            newNode->next = (*Q);
            (*Q) = newNode;
            return;
        }
        //for further nodes,i have mainted a prev pointer.
        Queue* jump = (*Q);
        Queue* prev = NULL;
        while(jump->next){
            prev = jump;
            jump = jump->next;
            if(jump->pNo < pNo){
                //if node with less priority found insert the newnode before it.
                //using prev pointer.
                newNode->next = jump;
                prev->next = newNode;
                return;
            }else if(jump->pNo == pNo){
                // for equal priority,newnode should be added after all the nodes with equal priority
                //i.e  example:  3->2->2->(next 2 insert here)->1 
                if(jump->next == NULL || jump->next->pNo != pNo){
                    newNode->next = jump->next;
                    jump->next = newNode;
                    return;
                }
            }
        } 
        //if no node with equal or less priority found insert at the end of queue
        newNode->next = jump->next;
        jump->next = newNode;
    }
}

//to get the element With max priority.


int maxPriorityNum(Queue* Q) {
    if (isEmpty(Q)) {
        return -101;
    } else {
        return Q->data;
    }
}

//to remove the node with maximum priority


void deleteNode(Queue** Q) {
    if (isEmpty(*Q)) {
        printf("***UnderFlow***\n");
    } else {
        Queue* temp = (*Q);
        (*Q) = (*Q)->next;
        free(temp);
    }
}