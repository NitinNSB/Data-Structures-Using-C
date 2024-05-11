#include<stdio.h>
#include<stdlib.h>
struct node{
    int item;
    struct node* next;
    struct node* prev;
};

void insBeg(struct node** head,int data);

void insEnd(struct node** head,int data);

struct node* searchNode(struct node* head,int data);

void insAfter(struct node** head,struct node* afterNode,int data);

void delBeg(struct node** head);

void delLast(struct node** head);

void delSpecificNode(struct node** head,struct node* spcNode);

void print(struct node* head);

int main(){
    struct node* head=NULL;
    struct node* s=NULL;
    insBeg(&head,43);
    insBeg(&head,98);
    insBeg(&head,67);
    insBeg(&head,56);
    //print(head); 
    //delBeg(&head);
    print(head);
    s=searchNode(head,67);
    delSpecificNode(&head,s);
    print(head);

}

//insert at the beggining

void insBeg(struct node** head,int data){
    struct node* newNode;
    newNode=(struct node*)malloc(sizeof(struct node));
    newNode->item=data;
    if((*head)==NULL){
        (*head)=newNode;
        newNode->next=(*head);
        newNode->prev=(*head);
        return;
    }
    else{
        newNode->next=(*head);
        newNode->prev=(*head)->prev;
        (*head)->prev->next=newNode;
        (*head)->prev=newNode;
        (*head)=newNode;
    }
}

//insert at the end

void insEnd(struct node** head,int data){
    struct node* newNode;
    newNode=(struct node*)malloc(sizeof(struct node));
    newNode->item=data;
    if((*head)==NULL){
        (*head)=newNode;
        newNode->next=(*head);
        newNode->prev=(*head);
        return;
    }
    else{
       newNode->next=(*head); 
       newNode->prev=(*head)->prev;
       (*head)->prev->next=newNode;
       (*head)->prev=newNode;
    }
}

//to search a node with given data

struct node* searchNode(struct node* head,int data){
    struct node* t=head;
    if(head==NULL){
        printf("List is empty...Item can't be searched\n");
        return NULL;
    }
    else{
        do{
            if((t->item)==data){
                return t;
            }
            t=t->next;
        }while(t!=head);
    }
    return NULL;
}

//method to insert data after a specific node

void insAfter(struct node** head,struct node* afterNode,int data){
    if(afterNode==NULL || (*head)==NULL){
        printf("Not a valid address to Enter data or List is Empty..\n");
        return;
    }
    else if(afterNode==(*head)->prev){
        insEnd(head,data);
        return;
    }
    else{
        struct node* newNode=(struct node*)malloc(sizeof(struct node));
        newNode->item=data;
        newNode->next=afterNode->next;
        newNode->prev=afterNode;
        afterNode->next=newNode;
        return;
    }
}

//delete first node from list

void delBeg(struct node** head){
    if((*head)==NULL){
        printf("List is empty,can't deleted empty list...\n");
        return;
    }
    else if((*head)==(*head)->next){
        free(*head);
        *head=NULL;
    }
    else{
        struct node* t=(*head);
        (*head)->prev->next=(*head)->next;
        (*head)=t->next;
        (*head)->prev=t->prev;
        free(t);
    }
}

//delete last node of list

void delLast(struct node** head){
    if((*head)==NULL){
        printf("List is empty,can't deleted empty list...\n");
        return;
    }
    else if((*head)==(*head)->next){
        free(*head);
        *head=NULL;
    }
    else{
        struct node* t=(*head)->prev;
        (*head)->prev=t->prev;
        t->prev->next=(*head);
        free(t);
    }
}

//delete a given node

void delSpecificNode(struct node** head,struct node* spcNode){
    if(spcNode==NULL || (*head)==NULL){
        printf("Not a valid address to delete node or List is Empty..\n");
        return;
    }
    else if(spcNode==(*head)->prev){
        delLast(head);
        return;
    }
    else if(spcNode==(*head)){
        delBeg(head);
    }
    else{
        spcNode->prev->next=spcNode->next;
        spcNode->next->prev=spcNode->prev;
        free(spcNode);
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
        do{
            printf("%d\n",temp->item);
            temp=temp->next;
        }while(temp!=head);
    }
}