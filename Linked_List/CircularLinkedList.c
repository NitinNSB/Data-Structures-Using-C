#include<stdio.h>
#include<stdlib.h>
struct node{
    int item;
    struct node* next;
};

void insBeg(struct node** last,int value);

void insEnd(struct node** last,int value);

struct node* searchNode(struct node* last,int value);

void insAfter(struct node** last,struct node* afterNode,int value);

void delFirst(struct node* last);

void delLast(struct node** last);

void delSpecificNode(struct node** last,struct node* afterNode);

void printNodes(struct node* last);

int main (){
    struct node* last=NULL;
    struct node* s;
    insBeg(&last,43);
    insBeg(&last,98);
    insBeg(&last,67);
    insBeg(&last,56);
    printNodes(last);
    s=searchNode(last,56);
    //delFirst(last);
    delSpecificNode(&last,s);
    printNodes(last);
}

// function to insert data at the beggining.

void insBeg(struct node** last,int value){
    struct node* newNode;
    newNode=(struct node*)malloc(sizeof(struct node));
    newNode->item=value;
     // If the list is empty.
    if((*last)==NULL){
        // The new node is now the last node, and it points to itself.
        (*last)=newNode;
        newNode->next=(*last);
    }
    else{
        newNode->next=(*last)->next;
        (*last)->next=newNode;
    }
}

// function to insert data at the End.

void insEnd(struct node** last,int value){
    struct node* newNode;
    newNode=(struct node*)malloc(sizeof(struct node));
    newNode->item=value;
    // If the list is empty.
    if((*last)==NULL){
        // The new node is now the last node, and it points to itself.
        (*last)=newNode;
        newNode->next=(*last);
    }
    else{
        newNode->next=(*last)->next;
        (*last)->next=newNode;
        (*last)=newNode;
    }
}

//function to search a node with given item;

struct node* searchNode(struct node* last,int value){
    if(last==NULL){
        printf("List is empty,item can't be searched...\n");
        return NULL;
    }
    else{
        struct node* t=last->next;
        do{
            t=t->next;
        }while((t!=last->next) && (t->item)!=value);
        if(t->item==value)
            return t;
        else
            return NULL;
    }
}

//insert data after a specified node

void insAfter(struct node** last,struct node* afterNode,int value){
    if(afterNode==NULL){
        printf("Can't insert a new node,Not a valid address..\n");
    }
    else if(afterNode==(*last)){
        insEnd(last,value);
    }
    else{
       struct node* newNode;
       newNode=(struct node*)malloc(sizeof(struct node));
       newNode->item=value;
       newNode->next=afterNode->next;
       afterNode->next=newNode;
    }

}

//delete first node from the list

void delFirst(struct node* last){
    printf("\n2st\n");
    if(last==NULL){
        printf("List is empty..\n");
        return;
    }
    struct node* t=last;
    t=t->next->next;
    free(last->next);
    last->next=t;
}

//delete last node from the list

void delLast(struct node**last){
    if((*last)==NULL){
        printf("List is empty\n..");
        return;
    }
    else if((*last)==(*last)->next){
        free((*last));
        (*last)=NULL;
        return;
    }
    struct node* t=(*last);
    while((t->next)!=(*last)){
        t=t->next;
    }
    t->next=(*last)->next;
    free((*last));
    (*last)=t;
}

//delete a specific node

void delSpecificNode(struct node** last,struct node* sfcNode){
     if(sfcNode==NULL){
        printf("Can't delete node,Not a valid address..\n");
    }
    else if(sfcNode==(*last)){
        delLast(last);
    }
    else{
        struct node* t=(*last)->next;
        struct node* prev=NULL;
        do{    
            if(t==sfcNode){
                delFirst(*last);
                return;  
            }
            prev=t;
            t=t->next;
        }while(t!=(*last)->next && t!=sfcNode);
        if(t==sfcNode){
            prev->next=t->next;
            free(t);
        }
    }
}

//to print all nodes

void printNodes(struct node* last){
    if(last==NULL){
        printf("List is empty,nothing to print...\n");
        return;
    }
    else{
        struct node* t=last->next;
        do{
            printf("%d\n",t->item);
            t=t->next;
        }while(t!=last->next);
    }
}

