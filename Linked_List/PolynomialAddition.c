#include<stdio.h>
#include<stdlib.h>
struct node{
    int coff;
    int pow;
    struct node* next;
};

void takePoly(struct node** poly);

void insert(struct node** poly,int power,int coefficient);

int main(){
    struct node* poly1=NULL;
    struct node* poly2=NULL;
    struct node* result=NULL;

}
void takePoly(struct node** poly){
    int num=0,coefficient=0,power=0;
    printf("Enter the no of terms in polynomial => ");
    scanf("%d",&num);
    for(int i=0;i<num;i++){
        printf("Enter the %d term power : ",(i+1));
        scanf("%d",&power);
        printf("Enter the %d term coefficient : ",(i+1));
        scanf("%d",&coefficient);
        insert(poly,power,coefficient);
    }
}
void insert(struct node** poly,int power,int coefficient){
    
}