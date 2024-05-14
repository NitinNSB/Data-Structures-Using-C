#include<stdio.h>
#include<stdlib.h> 

typedef struct Bnode{
    struct Bnode* left;
    struct Bnode* right;
    int data;
}Bnode;

struct node{
    Bnode* address;
    struct node* next;
};
struct node* stack = NULL;

struct node* stack_2 = NULL;

void insert(Bnode** t, int data);

void delete(Bnode** t, int data);

void push(struct node** stack,Bnode* address);

Bnode* pop(struct node** stack);

int checkEmpty(struct node** stack);

void inorderTraversal(Bnode* root);

void preorderTraversal(Bnode* root);

void postorderTraversal(Bnode* root);

int main() {
    Bnode* root = NULL; // Initialize an empty tree

    // Test case 1: Insertion
    insert(&root, 50);
    insert(&root, 30);
    insert(&root, 20);
    insert(&root, 40);
    insert(&root, 70);
    insert(&root, 60);
    insert(&root, 80);
    //inorderTraversal(root);
    //preorderTraversal(root);
    //postorderTraversal(root);
    return 0;

}


void insert(Bnode** t, int data) {
    Bnode* newNode = (Bnode*)malloc(sizeof(Bnode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    if (*t == NULL) {
        *t = newNode;
        return;
    }

    Bnode* current = *t;
    Bnode* parent = NULL;
     
    //Find the appropriate position to insert the new Node
    while(current != NULL) {
        parent = current;
        if(current->data > data){
            current = current->left;
        } else {
            current = current->right;
        }
    }

    //Update the appropriate child pointer of the parent node
    if(parent->data > data){
        parent->left = newNode;
    } else {
        parent->right = newNode;
    }
}

// Function to delete an item from BST.


void delete(Bnode** t, int data) {
   // ****If tree is not been created yet.****
   if(*t == NULL){
        printf("ERROR: Tree Not created yet.\n");
        return;
   } 
    //Cases for node with no child,single child, double child.
    else {
        Bnode* current = (*t);
        Bnode* parent = NULL;

        //Finding a the position of node to delete and its parent.
        
        while(current != NULL && current->data != data){
            parent = current;
            if(current->data > data){
                current = current->left;
            } else {
                current = current->right;
            }
        }
        //**** Case If data to be deleted is not in the tree.*****.

        if (current == NULL) {
            printf("Error: Data %d not found in the tree.\n",data);
            return;
        }

        //*******Deleting the node with no child.********


        if(current->left == NULL && current->right == NULL) {
            if(current == (*t)){ // ****If the node to be deleted is Root node*****
                (*t) = NULL;
            }
            else if(current->data > parent->data) {
                parent->right = NULL;
            } else {
                parent->left = NULL;
            }
            free(current);
            current = NULL;
        }

        //******Deleting the Bnode with Two child.*******

        else if(current->left != NULL && current->right != NULL) {
            Bnode* predecessor = current->left;
            Bnode* parentPredecessor = current;
            
            while(predecessor->right != NULL){
                parentPredecessor = predecessor;
                predecessor = predecessor->right;
            }
            
            //Changing the node data, to be deleted, with the predecessor.
            
            current->data = predecessor->data;

            // If predecessor has no child.

            if(predecessor->left == NULL) {
                if(predecessor->data > parentPredecessor->data) {
                    parentPredecessor->right = NULL;
                } else {
                    parentPredecessor->left = NULL;
                }
                free(predecessor);
                predecessor = NULL;
            }

            // If predecessor has one child.i.e left child

            else {
                // Update the parent's right pointer, to the left child of predecessor.
                parentPredecessor->right = predecessor->left;
                free(predecessor);
                predecessor = NULL;
            }
        }

        //*****Deleting the node with single child

        else {
            parent->data = current->data;
            if(parent->data > current->data) {
                parent->left = NULL;
            } else {
                parent->right = NULL;
            }
            free(current);
            current = NULL;
        }
    }
}

// pusing address of node in stack


void push(struct node** stack, Bnode* address){
   struct node* newNode;
   newNode=(struct node*)malloc(sizeof(struct node));
   newNode->address = address;
   newNode->next = (*stack);
   (*stack) = newNode;
}

//popping node and returning address of node in BST,so that we can reach to that node in bst
//i have stored the address of node of bst ,in the stack.


Bnode* pop(struct node** stack){
    if(*stack==NULL){
        printf("Stack is empty...i.e underFlow\n");
        return NULL;
    }
    else{
        struct node* temp = *stack;
        Bnode* address = temp->address;
        *stack = temp->next;
        free(temp);
        return address;
    }
}

// check if stack is empty


int checkEmpty(struct node** stack){
    return (*stack) == NULL;
}

//Inorder Traversal Non_Recursive approach

void inorderTraversal(Bnode* root){
    while(root != NULL || !checkEmpty(&stack)){
        while(root != NULL){
            push(&stack, root);
            root = root->left;
        }
        Bnode* temp = pop(&stack);
        printf("%d\n",temp->data);
        root = temp->right;
    }
}

// Preorder Traversal without recursion.


void preorderTraversal(Bnode* root){
    while(root != NULL || !checkEmpty(&stack)) {
        while(root != NULL){
            push(&stack, root);
            printf("%d\n",root->data);
            root = root->left;
        }
        Bnode* temp = pop(&stack);
        root = temp->right;
    }
}

// Postorder Traversal without recursion.


void postorderTraversal(Bnode* root) {
    // Push the root node onto the stack
    push(&stack, root);
    
    // Loop until the stack is empty
    while (!checkEmpty(&stack)) {
        // Pop a node from the stack
        Bnode* temp = pop(&stack);
        
        // Push the popped node onto stack_2
        push(&stack_2, temp);
        
        // If the popped node has a left child, push it onto the stack
        if (temp->left) {
            push(&stack, temp->left);
        }
        
        // If the popped node has a right child, push it onto the stack
        if (temp->right) {
            push(&stack, temp->right);
        }
    }
    
    // Print the nodes in postorder from stack_2
    printf("Postorder traversal: ");
    while (!checkEmpty(&stack_2)) {
        Bnode* temp = pop(&stack_2);
        printf("%d ", temp->data);
    }
}
