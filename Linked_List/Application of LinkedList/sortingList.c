#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct node{
    int content;
    struct node* next;
};

struct node* insertBeginning(struct node* head,int data);

void print(struct node* head);

struct node* sort(struct node* head);

int main(){
    struct node *head;
    head=NULL;
    head = insertBeginning(head,-1);
    head = insertBeginning(head,0);
    head = insertBeginning(head,99);
    head = insertBeginning(head,0);
    print(head);
    head = sort(head);
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

// Sorting a Linked List

struct node* sort(struct node* head){
    if( head == NULL ){
        printf("ERROR : List is empty.\n");
        return NULL;
    }
    struct node* jump = head;
    struct node* jump2 = NULL;
    while(jump != NULL){
            jump2 = jump->next;
            while(jump2 != NULL){
                int temp;
                if(jump->content > jump2->content){
                    temp = jump->content;
                    jump->content = jump2->content;
                    jump2->content = temp;
                }
                jump2 = jump2->next;
            }
            jump = jump->next;
        }
    return head;
}