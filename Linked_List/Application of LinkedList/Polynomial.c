#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    float coef;
    int exp;
    struct node* link;
}node;

node* createEquation();

node* insert(node* head, float coef, int exp);

void print(node* head);

int main(){
    node* head = NULL;
    printf(" <<<<<<<- Enter the Quadratic equation ->>>>>>>> \n");
    head = createEquation();
    print(head);
}

// for creation of equation


node* createEquation(){
    node* head = NULL;
    float coef;
    int exp;
    int n;
    printf("Enter the number of terms : ");
    scanf("%d",&n);
    for(int i =0; i < n; i++){
        printf("\nEnter the coefficient of %d term : ",i+1);
        scanf("%f",&coef);
        printf("\nEnter the exponent of %d term : ",i+1);
        scanf("%d",&exp);
        head = insert(head, coef, exp);
    }
    return head;
}

//for insertion of data in eqution.

node* insert(node* head, float coef, int exp){
    node* newNode = (node*)malloc(sizeof(node));
    newNode->coef = coef;
    newNode->exp = exp;
    newNode->link = NULL;

    if(head == NULL || head->exp < exp){
        newNode->link = head;
        head = newNode;
    } else {
        node* jump = head;
        while(jump->link != NULL && jump->link->exp < exp){
            jump = jump->link;
        }
        newNode->link = jump->link;
        jump->link = newNode;
    }
    return head;
}

// to print the polynomial 


void print(node* head){
    if(head == NULL){
        printf("/n <<<<< Error : Polynomial is empty >>>> ");
    } else {
        printf("\nPolynomial is : \n");
        while (head->link != NULL){
            printf("(%.1fx^%d)",head->coef,head->exp);
            head = head->link;
            printf(" + ");
        }
        printf("(%.1fx^%d) ",head->coef,head->exp);
    }
}