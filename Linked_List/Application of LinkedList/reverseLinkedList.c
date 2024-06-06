#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct node{
    int content;
    struct node* next;
};

struct node* insertBeginning(struct node* head,int data);

void print(struct node* head);

struct node* reverse(struct node* head);

int main(){
    struct node *head;
    head=NULL;
    head = insertBeginning(head,5);
    head = insertBeginning(head,6);
    head = insertBeginning(head,7);
    head = insertBeginning(head,8);
    print(head);
    head = reverse(head);
    print(head);
}

//function to insert data into the list at the begnning.


struct node* insertBeginning(struct node* head,int data){
    struct node* temp=head;
    struct node* newNode=(struct node*)malloc(sizeof(struct node));
    newNode->content=data;
    newNode->next=temp;
    return newNode;
}

// for printing


void print(struct node* head){
    struct node* temp=head;
    if(head==NULL){
        printf("No node\n");
    }
    else{
        printf("Linked List is : \n");
        for(int i=0;temp!=NULL;i++){
            printf("%d",temp->content);
            temp=temp->next;
            if(temp != NULL){
                printf(" -> ");
            } else {
                printf("\n");
            }
        }
    }
    
}

// reverse a linked list

struct node* reverse(struct node* head) {
    // at start their is no prev so NULL

    struct node* prev = NULL;
    struct node* current = head;
    struct node* next = NULL;
    while(current != NULL){
        // Store next
        next = current->next;

        // Reverse current node's pointer
        current->next = prev;

        // Now make current pointer as previous pointer
        prev = current; 
        // Make next pointer as currect
        current = next;
    }
    head = prev;
}