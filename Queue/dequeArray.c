#include<stdio.h>
#include<stdlib.h>
struct deque
{
    int capacity;
    int front, rear;
    int *ptr;
};
struct deque *createDeque(int cap);
int isEmpty(struct deque *d);
int isFull(struct deque *d);
void insertAtFront(struct deque *d, int data);
void insertAtRear(struct deque *d, int data);
int getFront(struct deque *d);
int getRear(struct deque *d);
void deleteFront(struct deque *d);
void deleteRear(struct deque *d);
void displayDeque(struct deque *d);

int main(){
    // Testing with a deque of capacity 5
    struct deque *d = createDeque(5);

    // Test inserting at front and rear
    insertAtFront(d, 10);
    insertAtRear(d, 20);
    insertAtFront(d, 5);
    insertAtRear(d, 15);

    // Test getting front and rear elements
    printf("Front element: %d\n", getFront(d)); // Expecting 5
    printf("Rear element: %d\n", getRear(d));   // Expecting 15

    // Test deleting front and rear elements
    deleteFront(d);
    deleteRear(d);

    // Test if deque is empty
    printf("Deque is%s empty.\n", isEmpty(d) ? "" : " not"); // Expecting not empty

    // Test inserting to cause overflow
    insertAtFront(d, 25);
    insertAtFront(d, 30);
    insertAtRear(d, 35);
    insertAtRear(d, 40);
    insertAtRear(d, 45); // Overflow expected

    // Test deleting to cause underflow
    deleteFront(d);
    deleteFront(d);
    deleteFront(d);
    deleteRear(d);
    deleteRear(d);
    deleteRear(d);
    deleteFront(d); // Underflow expected

    // Test when deque becomes empty
    printf("Deque is%s empty.\n", isEmpty(d) ? "" : " not"); // Expecting empty

    // Freeing memory
    free(d->ptr);
    free(d);

    return 0;
}

struct deque *createDeque(int cap){
    struct deque* d;
    d=(struct deque*)malloc(sizeof(struct deque));
    d->capacity=cap;
    d->front=-1;
    d->rear=-1;
    d->ptr=(int*)malloc(sizeof(int)*cap);
    return d;
}

int isEmpty(struct deque *d){
    if(d->rear==(-1))
        return 1;
    return 0;
}

int isFull(struct deque *d){
    if(d->front==0 && d->rear==d->capacity-1){
        return 1;
    }
    else if(d->rear+1==d->front){
        return 1;
    }
    else{
        return 0;
    }
}

void insertAtFront(struct deque *d, int data){
    if(isFull(d)){
        printf("Queue OverFlow..\n");
    }
    else{
        if(isEmpty(d)){
            d->front=0;
            d->rear=0;
        }
        else if(d->front==0){
            d->front=d->capacity-1;
        }
        else{
            (d->front)-=1;
        }
        d->ptr[d->front]=data;
    }
}

void insertAtRear(struct deque *d, int data){
    if(isFull(d)){
        printf("Queue OverFlow..\n");
    }
    else{
        if(isEmpty(d)){
            d->front=0;
            d->rear=0;
        }
        else if(d->rear==d->capacity-1){
            d->rear=0;
        }
        else{
            (d->rear)+=1;
        }
        d->ptr[d->rear]=data;
    }
}
int getFront(struct deque *d)
{
    if(!isEmpty(d))
        return d->ptr[d->front];
    else
    {
        printf("Deque is empty");
        return -1;
    }
}
int getRear(struct deque *d)
{
    if(!isEmpty(d))
        return d->ptr[d->rear];
    else
    {
        printf("Deque is empty");
        return -1;
    }
}

void deleteFront(struct deque *d){
    if(isEmpty(d)){
        printf("Queue UnderFlow\n");
        return;
    }
    else{
        if(d->rear==d->front){
            d->rear=-1;
            d->front=-1;
        }
        else if(d->front==d->capacity-1){
            d->front=0;
        }
        else{
            (d->front)+=1;
        }
    }
}

void deleteRear(struct deque *d){
    if(isEmpty(d)){
        printf("Queue UnderFlow\n");
        return;
    }
    else{
        if(d->rear==d->front){
            d->rear=-1;
            d->front=-1;
        }
        else if(d->rear==0){
            d->rear=d->capacity-1;
        }
        else{
            (d->rear)-=1;
        }
    }
}

void displayDeque(struct deque *d) {
    if (isEmpty(d)) {
        printf("Deque is empty\n");
        return;
    }
    
    printf("Deque contains: ");
    
    int i = d->front;
    do {
        printf("%d ", d->ptr[i]);
        i = (i + 1) % d->capacity; // Moves to the next index, wrapping around if necessary
    } while (i != (d->rear + 1) % d->capacity); // Loop until we reach rear + 1, handling wrap-around
    printf("\n");
}







