#include<stdio.h>
#include<stdlib.h>
struct queue{
    int capacity;
    int rear;
    int front;
    int *ptr;
};
struct queue* createQueue(int cap);

int isFull(struct queue* q);

void enqueue(struct queue* q,int data);

int isEmpty(struct queue* q);

void dequeue(struct queue* q);

void getRear(struct queue* q);

void getFront(struct queue* q);

int main(){
    struct queue* q = NULL;
    // Creating a queue with capacity 5
    q = createQueue(5);

    // Test cases for enqueue
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
    enqueue(q, 50);

    // Attempting to enqueue when the queue is full
    enqueue(q, 60); // This should print "Queue Overflow."

    // Test cases for dequeue
    dequeue(q); // Dequeue one element
    dequeue(q); // Dequeue another element

    // Test cases for getting front and rear elements
    getFront(q); // This should print "The front element is 30"
    getRear(q); // This should print "The Rear element is 50"

    // Test cases for additional dequeue operations
    dequeue(q);
    dequeue(q);
    dequeue(q); // Attempting to dequeue from an empty queue
    dequeue(q); // This should print "Queue UnderFlow"

    // Attempting to get front and rear elements from an empty queue
    getFront(q); // This should print "Queue is empty.."
    getRear(q); // This should print "Queue is empty.."

    // Freeing the allocated memory
    free(q->ptr);
    free(q);

    return 0;
}

//creating the queue

struct queue* createQueue(int cap){
    struct queue* temp;
    temp = (struct queue*)malloc(sizeof(struct queue));
    temp->capacity = cap;
    temp->rear=-1;
    temp->front=-1;
    temp->ptr=(int*)malloc(sizeof(int)*cap);
    return temp;
}

//to check if queue is full

int isFull(struct queue* q){
    if(q->rear==(q->capacity-1) && q->front==0 ){
        return 1;
    }
    else if((q->rear)+1==q->front){
        return 1;
    }
    else{
        return 0;
    }
}

//inserting the data

void enqueue(struct queue* q,int data){
    if(q==NULL){
        printf("Queue is not created Yet.\n");
        return;
    }
    else if(isFull(q)){
        printf("Queue Overflow.\n");
    }
    else if(q->rear==(-1)){
        q->rear=0;
        q->front=0;
        q->ptr[0]=data;
    }
    else if(q->rear==(q->capacity-1)){
        q->rear=0;
        q->ptr[q->rear]=data;
    }
    else{
        (q->rear)+=1;
        q->ptr[q->rear]=data;
    }
}

//to check if queue is empty

int isEmpty(struct queue* q){
    if(q==NULL){
        printf("Queue is not created Yet.\n");
        return 1;   
    }
    else if(q->rear==(-1)){
        return 1;
    }
    else{
        return 0;
    }
}

//deleting the data

void dequeue(struct queue* q){
    if(q==NULL){
        printf("Queue is not created Yet.\n");
        return;  
    }
    else if(isEmpty(q)){
        printf("Queue UnderFlow\n ");
    }
    else{
        if(q->rear==q->front)
            q->rear=q->front=-1;
        else if(q->front==q->capacity-1)
            q->front=0;
        
        else
            q->front++;
    }
}

//function to get front element

void getFront(struct queue* q){
    if(q==NULL){
        printf("Queue is not created yet..\n");
        return;
    }
    else{
        if(q->rear==(-1)){
            printf("Queue is empty..\n");
            return;
        }
        else{
            printf("The front element is %d\n",q->ptr[q->front]);
        }
    }
}

//function to get rear element

void getRear(struct queue* q){
    if(q==NULL){
        printf("Queue is not created yet..\n");
        return;
    }
    else{
        if(q->rear==(-1)){
            printf("Queue is empty..\n");
            return;
        }
        else{
            printf("The Rear element is %d\n",q->ptr[q->rear]);
        }
    }
}