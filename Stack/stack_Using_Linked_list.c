// A stack is a linear data structure that follows the Last-In-First-Out (LIFO) principle.

#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};

void push(struct node** stack,int value);

void checkEmpty(struct node* stack);

void peek(struct node* stack);

void pop(struct node**stack);

void release(struct node**stack);

int main(){
    struct node* stack = NULL;
    push(&stack,6);
    push(&stack,7);
    push(&stack,8);
    peek(stack);
    release(&stack);
    peek(stack);

}

// function to create a stack
/*

 Isme tu hamaisa naya element start mai insert karagaiga. jissai vo last inserted element toh rahaiga hi
 or usai delete or insert karnai kai liyai bar bar traverse bhi ni karna padaiga.

 In a stack, elements are added (pushed) and removed (popped) from the same end, following the 
 Last In, First Out (LIFO) principle. Therefore, adding elements to the end of the list is not efficient, 
 especially when the stack grows large, because each push operation would require traversing the entire list. 
 A more efficient approach is to add new elements at the beginning of the list.

*/

void push(struct node** stack,int value){
   struct node* newNode;
   newNode=(struct node*)malloc(sizeof(struct node));
   newNode->data=value;
   newNode->next=(*stack);
   (*stack)=newNode;
   printf("New Element is added Successfully..\n");
}

//Function to check is stack is empty or not

void checkEmpty(struct node* stack){
    if(stack==NULL){
        printf("Stack is empty...\n");
    }
}

//to peek the top element

void peek(struct node* stack){
  if(stack==NULL){
        printf("Stack is empty...\n");
    }
  else{
    printf("Top element is : %d\n",stack->data);
  }
}

//to pop top element

void pop(struct node**stack){
    if((*stack)==NULL){
        printf("Stack is empty...i.e underFlow\n");
    }
    else{
        struct node*temp=(*stack);
        (*stack)=temp->next;
        free(temp);
    }
}

//to release memory

void release(struct node**stack){
    while(*stack){
        pop(stack);
    }
}