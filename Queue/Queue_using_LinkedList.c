#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next ;
};

void enqueue(struct node** queue,struct node** rear,int value);

int isEmpty(struct node* queue);

void dequeue(struct node** queue,struct node** rear);

void getRear(struct node* queue);

void getFront(struct node* queue);

int main(){
    struct node* queue = NULL;
    struct node* rear = NULL;

    // Test cases for enqueue
    enqueue(&queue, &rear, 10);
    enqueue(&queue, &rear, 20);
    enqueue(&queue, &rear, 30);

    // Test cases for dequeue
    dequeue(&queue, &rear); // Remove one element
    dequeue(&queue, &rear); // Remove another element

    // Test cases for getting front and rear elements
    getFront(queue); // This should print "Front element is 30"
    getRear(rear); // This should print "Rear element is 30"

    // Additional dequeue operation
    dequeue(&queue, &rear);
    dequeue(&queue, &rear); // Attempting to dequeue from an empty queue
    dequeue(&queue, &rear); // This should print "Queue UnderFlow"

    // Attempting to get front and rear elements from an empty queue
    getFront(queue); // This should print "Queue is empty"
    getRear(rear); // This should print "Queue is empty"

    return 0;
}

// to add a new element in queue

void enqueue(struct node** queue,struct node** rear,int value){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next=NULL;
    if((*queue)==NULL){
        (*queue)=newNode;
        (*rear)=newNode;
        printf("Data added \n");
        return;
    }
    else{
        (*rear)->next=newNode;
        (*rear)=newNode;
         printf("Data added \n");
    }
}

// to check is queue is empty

int isEmpty(struct node* queue){
   if(queue==NULL){
    return 1;
   }
   return 0;
}

//to delete a element from the queue

void dequeue(struct node** queue,struct node** rear){
    if(isEmpty((*queue))){
        printf("Queue UnderFlow\n");
        return;
    }
    else{
        struct node* temp;
        temp=(*queue);
        (*queue)=(*queue)->next;
        free(temp);
        if((*queue)==NULL){
            (*rear)=NULL;
        }
        printf("data removed...\n");
    }
}

//to get rear element

void getRear(struct node* rear){
    if(isEmpty(rear)){
        printf("Queue is empty\n");
        return;
    }
    else{
        printf("Rear element is %d\n",rear->data);
    }
}

//to get front element

void getFront(struct node* queue){
    if(isEmpty(queue)){
        printf("Queue is empty\n");
        return;
    }
    else{
        printf("Front element is %d\n",queue->data);
    }
}