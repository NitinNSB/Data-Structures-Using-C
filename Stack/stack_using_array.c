//A stack is a linear data structure that follows the Last-In-First-Out (LIFO) principle.

//***Real life Example** : Travelling Bag, plates in functions are kept one on other,you 
//can pick from top ,i.e the plate kept at last.

//***Programming example***: nested calls of function i.e one function call inside another 
//one ,  recursion. 

#include<stdio.h>
#include<stdlib.h>
struct stack{
    int capacity;
    int top;
    int* ptr;
};

struct stack* createStack(int cap);

void push(struct stack* s,int data);

void checkEmpty(struct stack* s);

void peek(struct stack* s);

void pop(struct stack* s);

void release(struct stack* s);

int main(){
    struct stack* s=NULL;
    s=createStack(3);
    push(s,6);
    push(s,9);
    push(s,10);
    push(s,11);
    printf("%d\n",s->ptr[s->top]);
    printf("%d\n",s->ptr[(s->top)-1]);
    printf("%d\n",s->ptr[(s->top)-2]);
}

//function to create stack

struct stack* createStack(int cap){
    struct stack* temp;
    temp=(struct stack*)malloc(sizeof(struct stack));
    temp->capacity=cap;
    temp->top=-1;
    temp->ptr=(int*)malloc(sizeof(int)*cap);
    printf("Stack of size %d created successfully\n",cap);
    return temp;
}

//function to add data in stack

void push(struct stack* s,int data){
    if(s==NULL){
        printf("Stack is not created..\n");
        return;
    }
    else if(s->top==(s->capacity)-1){
        printf("Not enough space...Stack overflow..\n");
        return;
    }
    else{
        (s->top)+=1;
        s->ptr[s->top]=data;
        printf("Data added successfully..\n");
    }
}

//function to check if stack is empty

void checkEmpty(struct stack* s){
    if(s==NULL){
        printf("Stack is not created yet\n");
        return;
    }
    else{
        if(s->top==(-1)){
            printf("Stack is empty.\n");
        }
        else{
            printf("Stack has elements.\n");
        }
    }
}

//function to peek top element of stack

void peek(struct stack* s){
    if(s==NULL){
        printf("Stack is not created yet\n");
        return;
    }
    else{
        printf("The top element is : %d\n",s->ptr[s->top]);
    }
}

//function to pop out the top element

void pop(struct stack* s){
    if(s==NULL){
        printf("Stack is not created yet\n");
        return;
    }
    else{
        (s->top)-=1;
        printf("Top item pooped out successfully...\n");
    }
}

//to release memory

void release(struct stack* s){
    if(s!=NULL){
        free(s->ptr);
        free(s);
    }
}