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

node* add(node* head, node* head2);

int main(){
    node* head = NULL;
    node* head2 = NULL;
    node* result = NULL;

    // Test Case 1
    printf("Test Case 1:\n");
    printf("Enter the first polynomial (quadratic equation):\n");
    head = createEquation();
    print(head);
    
    printf("Enter the second polynomial (quadratic equation):\n");
    head2 = createEquation();
    print(head2);
    
    result = add(head, head2);
    printf("Resultant polynomial after addition:\n");
    print(result);

    // Test Case 2
    printf("\nTest Case 2:\n");
    node* head3 = NULL;
    node* head4 = NULL;
    node* result2 = NULL;
    
    // Manually creating first polynomial: 5x^2 + 4x + 2
    head3 = insert(head3, 5.0, 2);
    head3 = insert(head3, 4.0, 1);
    head3 = insert(head3, 2.0, 0);
    printf("First polynomial:\n");
    print(head3);

    // Manually creating second polynomial: 3x^2 + 2x + 1
    head4 = insert(head4, 3.0, 2);
    head4 = insert(head4, 2.0, 1);
    head4 = insert(head4, 1.0, 0);
    printf("Second polynomial:\n");
    print(head4);

    result2 = add(head3, head4);
    printf("Resultant polynomial after addition:\n");
    print(result2);

    // Clean up memory
    // Free allocated memory for all lists (head, head2, result, head3, head4, result2)

    return 0;
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
        while(jump->link != NULL && jump->link->exp > exp){
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
        printf("(%.1fx^%d) \n",head->coef,head->exp);
    }
}

// Addition of polynomial 

node* add(node* head, node* head2){
    node* result = NULL;
    node* jump = head;
    node* jump2 = head2;
    float coef;
    while(jump != NULL && jump2 != NULL){
        if(jump->exp == jump2->exp){
            coef = jump->coef + jump2->coef;
            result = insert(result, coef, jump->exp);
            jump = jump->link;
            jump2 = jump2->link;
        }else if(jump->exp > jump2->exp){
            coef = jump->coef;
            result = insert(result, coef, jump->exp);
            jump = jump->link;
        }else{
            coef = jump2->coef;
            result = insert(result, coef, jump2->exp);
            jump2 = jump2->link;
        }
    }
    while(jump != NULL){
        result = insert(result, jump->coef, jump->exp);
        jump = jump->link;
    }
    while(jump2 != NULL){
        result = insert(result, jump2->coef, jump2->exp);
        jump2 = jump2->link;
    }
    return result;
}