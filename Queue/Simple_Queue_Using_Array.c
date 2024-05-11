#include<stdio.h>
#include<stdlib.h>
struct Queue{
    int capacity;
    int rear;
    int front;
    int* ptr;
};

struct Queue* createQueue(int cap);

void enqueue(struct Queue* q,int data);

void dequeue(struct Queue* q);

void getFront(struct Queue* q);

void getRear(struct Queue* q);

void checkEmptyFull(struct Queue* q);

int main(){

}

//function to  create a Queue

struct Queue* createQueue(int cap){
    struct Queue* temp;
    temp = (struct Queue*)malloc(sizeof(struct Queue));
    temp->capacity=cap;
    temp->rear=-1;
    temp->front=-1;
    temp->ptr=(int*)malloc(sizeof(int)*cap);
    return temp;
}

//functiom to insert the data in Queue

void enqueue(struct Queue* q,int data){
    if(q==NULL){
        printf("Queue is not created yet..\n");
        return;
    }
    else{
        if(q->rear==(-1)){
            q->rear=0;
            q->front=0;
            q->ptr[0]=data;    
        }
        else if((q->rear)!=(q->capacity-1)){
            q->rear+=1;
            q->ptr[q->rear]=data;
        }
        else{
            printf("Queue is full...\n");
            return;
        }

    }
}

//function to delete the data in queue;

void dequeue(struct Queue* q){
    if(q==NULL){
        printf("Queue is not created yet..\n");
        return;
    }
    else{
        if(q->rear==(-1)){
            printf("Queue is empty..\n");
            return;
        }
        else if(q->rear==q->front){
            q->rear=-1;
            q->front=-1;
        }
        else{
            for(int i=0;i<(q->rear);i++){
                q->ptr[i]=q->ptr[i+1];
            }
            (q->rear)-=1;
            (q->front)=0;
            return;
        }
    }
}

//function to get front element

void getFront(struct Queue* q){
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
            printf("The front element is %d\n",q->ptr[0]);
        }
    }
}

//function to get rear element

void getRear(struct Queue* q){
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

//check empty and full queue

void checkEmptyFull(struct Queue* q){
    if(q==NULL){
        printf("Queue is not created yet..\n");
        return;
    }
    else{
        if(q->rear==(-1)){
            printf("Queue is empty..\n");
            return;
        }
        else if(q->rear==(q->capacity-1)){
            printf("Queue is full\n");
        }
        else{
            printf("Queue has some space\n");
        }  
    }
}

/*there is a another way of doing enqueue ,jismai tujai shifting ki jarurat nahi hoti hai.
see  another file