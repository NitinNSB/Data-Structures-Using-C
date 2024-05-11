#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
    struct node* prev;
}Deque;

void insertAtFront(Deque** front,Deque** rear, int data);

void insertAtRear(Deque** front, Deque** rear, int data);

int isEmpty(Deque* front);

void deleteAtFront(Deque** front, Deque** rear);

void deleteAtRear(Deque** front, Deque** rear);

void printDeque(Deque* front) {
    printf("Deque: ");
    while (front != NULL) {
        printf("%d ", front->data);
        front = front->next;
    }
    printf("\n");
}

int main(){
    Deque* front = NULL;
    Deque* rear = NULL;
}

//Insertion at front of Deque.


void insertAtFront(Deque** front, Deque** rear, int data){
    Deque* newNode = (Deque*)malloc(sizeof(Deque));
    newNode->data = data;
    newNode->prev = NULL;
    if((*front) == NULL){
        newNode->next = NULL;
        (*front) = (*rear) = newNode;
        return;
    }
    newNode->next = (*front);
    (*front)->prev = newNode;
    (*front) = newNode;
}

//Insertion at rear of Deque.


void insertAtRear(Deque** front, Deque** rear, int data){
    Deque* newNode = (Deque*)malloc(sizeof(Deque));
    newNode->data = data;
    newNode->next = NULL;
    if((*rear) == NULL){
        newNode->prev = NULL;
        (*front) = (*rear) = newNode;
        return;
    }
    newNode->prev = (*rear);
    (*rear)->next = newNode;
    (*rear) = newNode;
}

//To check if Deque is Empty.


int isEmpty(Deque* front){
    if(front == NULL){
        return 1;
    }
    return 0;
}

//To delete element in Deque from Front.


void deleteAtFront(Deque** front, Deque** rear){
    if(isEmpty(*front)){
        printf("**UNDERFLOW**");
    }else if((*front) == (*rear)){
        free(*front);
        (*front) = (*rear) = NULL;
    }else{
        Deque* temp = (*front);
        (*front) = (*front)->next;
        (*front)->prev = NULL;
        free(temp);
    }
}

//To delete element in Deque from rear.


void deleteAtRear(Deque** front, Deque** rear){
    if(isEmpty(*front)){
        printf("**UNDERFLOW**");
    }else if((*front) == (*rear)){
        free(*front);
        (*front) = (*rear) = NULL;
    }else{
        Deque* temp = (*rear);
        (*rear) = (*rear)->prev;
        (*rear)->next = NULL;
        free(temp);
    }
}