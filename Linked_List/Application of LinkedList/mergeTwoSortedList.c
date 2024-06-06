# include<stdio.h>
# include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}node;

node* insert(node* list, int data);

void print(node*);

node* merge(node* list1, node* list2);

int main(){
    node* list1 = NULL;
    node* list2 = NULL;
    node* result = NULL;
    printf("<<<<<<<- lists ->>>>>>>\n");
    list1 = insert(list1, 4);
    list1 = insert(list1, 3);
    list1 = insert(list1, 5);
    list1 = insert(list1, 60);
    printf("Inserted List items in sorted order : \n");
    print(list1);
    list2 = insert(list2, 60);
    list2 = insert(list2, 13);
    list2 = insert(list2, 57);
    list2 = insert(list2, 18);
    list2 = insert(list2, 41);
    printf("Inserted List items in sorted order : \n");
    print(list2);
    result = merge(list1, list2);
    print(result);
    
}

// to insert data in list in sorted order


node* insert(node* list, int data){
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;
    if(list == NULL || list->data > data){
        newNode->next = list;
        list = newNode;
    } else{
        node* jump = list;
        while(jump->next != NULL && jump->next->data < data){
            jump = jump->next;
        }
        newNode->next = jump->next;
        jump->next = newNode;
    }
    return list;
}

// Function to print the list


void print(node* list){
    if(list == NULL){
        printf("ERROR: List is empty.\n");
        return;
    } 
    while(list != NULL){
        printf("%d",list->data);
        list = list->next;
        if(list == NULL){
            printf("\n");
        }else{
            printf(" -> ");
        }
    }
    
}


node* merge(node* list1, node* list2) {
    node* jump = list1;
    node* jump2 = list2;
    node* result = NULL;
    while(jump != NULL && jump2 != NULL) {
        if(jump->data < jump2->data){
            result = insert(result, jump->data);
            jump = jump->next;
        } else if(jump->data > jump2->data) {
            result = insert(result, jump2->data);
            jump2 = jump2->next;
        } else {
            result = insert(result, jump->data);
            result = insert(result, jump->data);
            jump = jump->next;
            jump2 = jump2->next;
        }
    }
    while(jump != NULL){
        result = insert(result, jump->data);
        jump = jump->next;
    }
    while(jump2 != NULL){
        result = insert(result, jump2->data);
        jump2 = jump2->next;
    }
    return result;
}