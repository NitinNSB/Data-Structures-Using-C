#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct node{
    int content;
    struct node* next;
};

void insertLast(struct node** head,int data);

struct node* insertBeginning(struct node* head,int data);

void  insertAfter(struct node* head,int data,int afterData);

struct node* insertBefore(struct node* head,int data,int afterData);

void delLast(struct node** head);

void delBeg(struct node** head);

void delAfter(struct node* head,int afterData);

void delBefore(struct node** head,int beforeData);

void print(struct node* head);

void printReverse(struct node* head);

void main(){
    struct node *head;
    head=NULL;
    head=insertBeginning(head,5);
    insertLast(&head,6);
    insertLast(&head,7);
    insertLast(&head,8);
    print(head);
    delBefore(&head,7);
    print(head);
   

    getch(); 
}
//function to insert data into the list at the begnning.
struct node* insertBeginning(struct node* head,int data){
    struct node* temp=head;
    struct node* newNode=(struct node*)malloc(sizeof(struct node));
    newNode->content=data;
    newNode->next=temp;
    return newNode;
}

//function to insert data into the list at the Last.

void insertLast(struct node** head,int data){
    struct node* jump;
    if((*head)==NULL){
        (*head)=(struct node*)malloc(sizeof(struct node));
        (*head)->content=data;
        (*head)->next=NULL;
    }
    else{
        jump=*head;
        while(jump->next!=NULL){
            jump=jump->next;
        }
        jump->next=(struct node*)malloc(sizeof(struct node));
        jump->next->content=data;
        jump->next->next=NULL;
    }
}

//function to insert data into the list after the given data.

void insertAfter(struct node* head,int data,int afterData){
    struct node* jump;
    struct node* newNode;
    jump=head;
    for(int i=0;(jump!=NULL)&&(jump->content!=afterData);i++){
        jump=jump->next;
    }
    if(jump==NULL){
        printf("\nNode with given data not found.\n");
    }
    else{
        newNode=(struct node*)malloc(sizeof(struct node));
        newNode->content=data;
        newNode->next=jump->next;
        jump->next=newNode;
    }
    
}

//function to insert data into the list before the given data.

struct node* insertBefore(struct node* head,int data,int beforeData){
    struct node* jump=head;
    struct node* newNode;
    if(jump==NULL){
        printf("list is empty");
        return jump;
    }
    if(jump->content==beforeData){
        head=insertBeginning(jump,data);
        return head;
    }
    else{
        for(int i=0;(jump!=NULL)&&((jump->next)->content!=beforeData);i++){
            jump=jump->next;
        }
        if(jump==NULL){
            printf("\nNode with given data not found.\n");
            return head;
        }
        else{
            newNode=(struct node*)malloc(sizeof(struct node));
            newNode->content=data;
            newNode->next=jump->next;
            jump->next=newNode;
            return head;
        }
    }
    
}

//function to delete last data in the list .

void delLast(struct node** head){
    if (*head == NULL) {
        printf("NO NODE");
        return;
    }
    if((*head)->next==NULL){
        free(*head);
        *head=NULL;
        
    }
    else{
        struct node* jump=*head;
        for(int i=0;(jump->next->next)!=NULL;i++){
            jump=jump->next;
        }
        free(jump->next);
        jump->next=NULL;
    }
}

//function to delete  beginning data in the list .

void delBeg(struct node** head){
    if((*head)==NULL){
        printf("list is empty");
        return;
    }
    else{
        struct node* jump=*head;
        jump=jump->next;
        free(*head);
        *head=jump;

    }
}

//function to delete   data after a given data in the list .

void delAfter(struct node* head,int afterData){
    if(head==NULL){
        printf("List is empty\n");
        return;
    }
    else if(head->content==afterData && head->next==NULL){
        printf("It is the first node\n");
        return;
    }
    else if(head->content!=afterData && head->next==NULL){
        printf("Node with given data not found\n");
        return;
    }
    struct node* jump=head;
    for(int i=0;(jump!=NULL) && (jump->content!=afterData);i++){
        jump=jump->next;
    }
    if(jump==NULL || jump->next==NULL){
        printf("node with given data not found or it is the last node\n");
        return;
    }
    else{
        struct node* current;
        current=jump->next;
        jump->next=current->next;
        free(current);
    }
}

//function to delete data before the given data of list

void delBefore(struct node** head,int beforeData){
     if((*head)==NULL){
        printf("List is empty\n");
        return;
    }
    else if((*head)->content==beforeData){
        printf("It is the first node\n");
        return;
    }
    else if((*head)->next==NULL){
        printf("Node with given data not found\n");
        return;
    }
    struct node* jump=(*head);
    struct node* prev=NULL;
    while(jump->next!=NULL){
        if(jump->next->content==beforeData && prev==NULL){
           (*head)=jump->next;
           free(jump);
           return;
        }
        prev=jump;
        jump=jump->next;
        if(jump->next->content==beforeData){
            prev->next=jump->next;
            free(jump);
            break;
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
            printf("%d\n",temp->content);
            temp=temp->next;
        }
    }
    
}

//Function to print linked list data in reverse order

void printReverse(struct node* head){
    struct node* temp=head;
    struct node* temp2=head;
    int count=0;
    if(head==NULL){
        printf("No node\n");
    }
    else{
        printf("Before reversing\n");
        for(int i=0;temp!=NULL;i++){
            printf("%d\n",temp->content);
            temp=temp->next;
            count++;
        }

        int *arr;
        arr=(int*)malloc(sizeof(int)*count);
        
        for(int i=0;temp2!=NULL;i++){
            arr[i]=temp2->content;
            temp2=temp2->next;
        }

        printf("After reversing\n");

        for(int i=count-1;i>=0;i--){
            printf("%d\n",arr[i]);
        }
        free(arr);
    }
    
}
