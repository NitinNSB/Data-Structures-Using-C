#include<stdio.h>
#include<stdlib.h>

typedef struct Queue{
    int capacity;
    int maxPriority;
    int** ptr;
    int* front;
    int* rear;
}PriorityQueue;

PriorityQueue* createPriorityQueue(int capacity, int maxPriority);

int isEmpty(PriorityQueue* pq, int priority);

int dataAtMaxP(PriorityQueue* pq);

void insertData(PriorityQueue* pq, int data, int priority);

int dataAtMaxP(PriorityQueue* pq);

void deleteMaxPriorityData(PriorityQueue* pq);

// Display Priority Queue Contents
void displayPriorityQueue(PriorityQueue* pq) {
    if (pq == NULL) {
        printf("Priority Queue is not created yet.\n");
        return;
    }
    printf("Priority Queue Contents:\n");
    for (int priority = 0; priority <= pq->maxPriority; priority++) {
        printf("Priority %d:", priority);
        if (isEmpty(pq, priority)) {
            printf(" Empty\n");
        } else {
            printf(" ");
            int front = pq->front[priority];
            int rear = pq->rear[priority];
            int i = front; // Initialize i to the front index
            do {
                printf("%d ", pq->ptr[priority][i]);
                i = (i + 1) % pq->capacity; // Move to the next index in a circular manner
            } while (i != (rear + 1) % pq->capacity); // Loop until we reach (rear + 1)
            printf("\n");
        }
    }
}

int main(){
    PriorityQueue* pq = NULL;
    pq = createPriorityQueue(5, 2);
    insertData(pq, 10, 0); // Insert data 10 at priority 0
    insertData(pq, 20, 1); // Insert data 20 at priority 1
    insertData(pq, 30, 2); // Insert data 30 at priority 2

    printf("%d\n",isEmpty(pq, 0)); // Check if priority 0 is empty
    printf("%d\n",isEmpty(pq, 1)); // Check if priority 1 is empty
    printf("%d\n",isEmpty(pq, 2)); // Check if priority 2 is empty

    insertData(pq, 40, 0); // Insert data 40 at priority 0
    insertData(pq, 50, 2); // Insert data 50 at priority 2
    
    displayPriorityQueue(pq);

    printf("%d\n",dataAtMaxP(pq)); // Retrieve data at max priority
    deleteMaxPriorityData(pq);
    
    printf("%d\n",dataAtMaxP(pq));
    deleteMaxPriorityData(pq);
    
    printf("%d\n",dataAtMaxP(pq));


    deleteMaxPriorityData(pq);
    printf("%d\n",dataAtMaxP(pq));

    

    displayPriorityQueue(pq);

    deleteMaxPriorityData(pq);
    printf("%d\n",dataAtMaxP(pq));

    deleteMaxPriorityData(pq);
    printf("%d\n",dataAtMaxP(pq));

    displayPriorityQueue(pq);



    

    // Insert elements to fill up the queue at a specific priority level
    // Note: Adjust the capacity and priorities according to your implementation
    insertData(pq, 60, 1);
    insertData(pq, 70, 1);
    insertData(pq, 80, 1);
    insertData(pq, 90, 1);
    // Attempt to insert more elements to trigger overflow
    insertData(pq, 100, 1);

    


}

//For creating a Priority Queue

PriorityQueue* createPriorityQueue(int capacity, int maxPriority) {
    PriorityQueue* temp = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    if (temp == NULL) {
        // Handle error, maybe return NULL or exit program
        return NULL;
    }
    temp->capacity = capacity;
    temp->maxPriority = maxPriority;
    temp->ptr = (int**)malloc(sizeof(int)*(maxPriority + 1));
    for(int i = 0; i <= maxPriority; i++) {
        temp->ptr[i] = (int*)malloc(sizeof(int)*capacity);
    }
    temp->front = (int*)malloc(sizeof(int)*(maxPriority+1));
    temp->rear = (int*)malloc(sizeof(int)*(maxPriority+1));
    for(int i=0; i <= maxPriority; i++ ) {
        temp->front[i] = -1;
        temp->rear[i] = -1;
    }
    return temp;
}

//TO check if given Priority Array is empty.


int isEmpty(PriorityQueue* pq, int priority){
    if(pq == NULL){
        printf("Error : Queue Not created yet\n");
        return 0;
    }
    if( pq->rear[priority] == -1) {
        return 1;
    }
    return 0;
}

//Insert Element in Priority Queue

void insertData(PriorityQueue* pq, int data, int priority){
    if(priority < 0 || priority > pq->maxPriority){
        printf("Error:Invalid Priority\n");
        return;
    }
    if(pq == NULL) {
        printf("ERROR : Queue is Not been created yet");
        return;
    } else {
        if(isEmpty(pq, priority)) {
            pq->rear[priority] = 0;
            pq->front[priority] =0;
            pq->ptr[priority][pq->front[priority]] = data;
        }
        else{
            if((pq->rear[priority] == pq->capacity-1) && (pq->front[priority] == 0)) {
                printf("OVERFLOW : Queue at %d priority level is Full\n",priority);
            } else if((pq->rear[priority] == pq->front[priority]-1)) {
                printf("OVERFLOW : Queue at %d priority level is Full\n",priority);
            } else if((pq->front[priority] != 0) && (pq->rear[priority] == pq->capacity-1)) {
                pq->rear[priority] = 0;
                pq->ptr[priority][pq->rear[priority]] = data;
            }
            else{
                pq->rear[priority]++;
                pq->ptr[priority][pq->rear[priority]] = data;
            }
        }
    }
}

//To get the maxPriority


int maxPriority(PriorityQueue* pq) {
    if(pq == NULL){
        printf("Error : Queue Not created yet\n");
        return -1;
    }
    return pq->maxPriority;
}

//To get data at max priority

int dataAtMaxP(PriorityQueue* pq) {
    if(pq == NULL){
        printf("Error : Queue Not created yet\n");
        return -1;
    }
    int maxP = maxPriority(pq);
    for (int i = maxP; i >= 0; i--){
        if(!(isEmpty(pq, i))) {
            return pq->ptr[i][pq->front[i]];
        }
    }
    return -1;
}

//Function to release Memory of priority Queue.

void releaseMemory(PriorityQueue** pq){
    if((*pq) == NULL) {
        printf("**UNDERFLOW**\n");
    } else {
        for(int i = 0; i<= (*pq)->maxPriority; i++) {
            free((*pq)->ptr[i]);
        }
        free((*pq)->ptr);
        free((*pq)->front);
        free((*pq)->rear);
        free((*pq));
    }
    (*pq) = NULL;
}

//TO delete the highest number from the highest priority queue
void deleteMaxPriorityData(PriorityQueue* pq){
    if(pq == NULL){
        printf("Error : Queue Not created yet\n");
        return;
    }
    int maxP = maxPriority(pq);
    for (int i = maxP; i >= 0; i--){
        if(!(isEmpty(pq, i))) {
            if( pq->front[i] == pq->rear[i]){
                pq->front[i] = -1;
                pq->rear[i] = -1;
            } else if( pq->front[i] == pq->capacity-1) {
                pq->front[i] = 0;
            } else {
                pq->front[i]++;
            }
            i=0;
        }
    }
}