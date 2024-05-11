#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct node{
    int content;
    struct node* next;
};
struct headerNode{
    int count;
    struct node* next;
};
struct headerNode* insertBegnning(struct headerNode* header,int value){
    struct node* temp;
    temp=header->next;
    struct node* newNode;
    newNode=(struct node*)malloc(sizeof(struct node));
    newNode->content=value;
    newNode->next=temp;
    header->next=newNode;
    header->count++;
    return header;
}
int main(){
    struct headerNode* start=(struct headerNode*)malloc(sizeof(struct headerNode));
    struct node* jump;
    start->count=0;
    start->next=NULL;
    start=insertBegnning(start,8);
    start=insertBegnning(start,9);
    start=insertBegnning(start,7);
    printf("no of nodes : %d",start->count);
    jump=start->next;
    for(int i=0;i<start->count;i++){
        printf("\n%dst node contain : %d",i+1,jump->content);
        jump=jump->next;
    }

    return 0;
}