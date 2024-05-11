#include<stdio.h>
#include<stdlib.h>
struct node{
    int item;
    struct node* prev;
    struct node* next;
};

void insBeginning(struct node**head,int value);

void insLast(struct node**head,int value);

struct node* searchNode(struct node* head,int value);

void insAfter(struct node* afterNode,int value);

void delFirst(struct node** head);

void delLast(struct node* head);

void delSpecificNode(struct node** head,struct node* spcNode);

void print(struct node* head);

int main(){
    struct node* head;
    struct node* result;
    head=NULL;
    insBeginning(&head,5);
    insLast(&head,7);
    insLast(&head,8);
    insLast(&head,10);
    print(head);
    result=searchNode(head,5);
    delSpecificNode(&head,result);
    print(head);

}

//insertion at beginning

void insBeginning(struct node**head,int value){
    struct node* newNode;
    newNode=(struct node*)malloc(sizeof(struct node));
    newNode->item=value;
    newNode->prev=NULL;
    newNode->next=*head;
    *head=newNode;
    printf("NEW node inserted at beggining successfully..\n");
}

//insertion at last

void insLast(struct node**head,int value){
    struct node* t=*head;
    if(*head==NULL){
        printf("Linked List is empty...Inserting as first node\n");
        insBeginning(head,value);
    }
    else{
        struct node* newNode;
        newNode=(struct node*)malloc(sizeof(struct node));
        newNode->item=value;
        newNode->next=NULL;
        while(t->next!=NULL){
            t=t->next;
        }
        newNode->prev=t;
        t->next=newNode;
        printf("NEW node inserted at Last successfully..\n");
    }
}

//search node

struct node* searchNode(struct node* head,int value){
    if(head==NULL){
        printf("List is Empty.../n");
        return NULL;
    }
    else{
        struct node* t=head;
        while(t->item!=value){
            t=t->next;
        }
        return t;
    }
}

//insert after a specified node

void insAfter(struct node* afterNode,int value){
    if(afterNode==NULL){
        printf("**NULL** Can't Do insertion...\n");
    }
    else{
        struct node* newNode;
        newNode=(struct node*)malloc(sizeof(struct node));
        newNode->item=value;
        newNode->next=afterNode->next;
        newNode->prev=afterNode;
        afterNode->next=newNode;
    }
}

//delete first node from the list 

void delFirst(struct node** head){
    if(*head==NULL){
        printf("List is empty..\n");
    }
    else{
        struct node* t=*head;
        *head=t->next;
        (*head)->prev=NULL;
        free(t);
    }
    
}

//delete last node from the list

void delLast(struct node* head){
    if(head==NULL){
       printf("List is empty..\n");
    }
    else{
        struct node* t=head;
        while(t->next!=NULL){
            t=t->next;
        }
        t->prev->next=NULL;
        free(t);
    }
}

//method to delete a specific node

void delSpecificNode(struct node** head,struct node* spcNode){
    if(spcNode==NULL){
        printf("You have provided a NULL Pointer../n");
    }
    else if(spcNode==(*head)){
        delFirst(head);
    }
    else{
        struct node* t=*head;
        while(t->next!=NULL && t->next!=spcNode){
            t=t->next;
        }
        if(t->next->next==NULL){
            delLast(*head);
        }
        else if(t->next==spcNode){
            struct node* temp;
            temp=t->next->next;
            free(t->next);
            temp->prev=t;
            t->next=temp;
        }
        else{
            printf("You have given invalid address\n");
        }
    }
}

//Function to print linked list data.

void print(struct node* head){
    struct node* temp=head;
    if(head==NULL){
        printf("No node\n");

    }
    else{
        printf("Linked List is : \n");
        for(int i=0;temp!=NULL;i++){
            printf("%d\n",temp->item);
            temp=temp->next;
        }
    }
    
}

