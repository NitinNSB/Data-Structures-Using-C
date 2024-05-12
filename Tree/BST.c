#include<stdlib.h>
#include<stdio.h>

typedef struct node{
    struct node* left;
    struct node* right;
    int data;
}node;

node* searchPosition(node* t,int data);

void insert(node** t, int data);

void delete(node** t, int data);

void preorder(node*t);

void inorder(node* t);

int main(){

}

// Search Node  in BST.


node* searchPosition(node* t,int data) {
    if(t == NULL){
        return t;
    }else {
        if(t->data == data) {
           return t;
        }
        if(t->data < data) {
           return searchPosition(t->right, data);
        }
        else if(t->data > data) {
            return searchPosition(t->left, data);
        }
    }
    return NULL;
}

//Insert data at the searched place in BST.


void insert(node** t, int data) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    if (*t == NULL) {
        *t = newNode;
        return;
    }

    node* current = *t;
    node* parent = NULL;
     
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


void delete(node** t, int data) {
   // ****If tree is not been created yet.****
   if(*t == NULL){
        printf("ERROR: Tree Not created yet.\n");
        return;
   } 
    //Cases for node with no child,single child, double child.
    else {
        node* current = (*t);
        node* parent = NULL;

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

        //******Deleting the node with Two child.*******

        else if(current->left != NULL && current->right != NULL) {
            node* predecessor = current->left;
            node* parentPredecessor = current;
            
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

// Preorder Traverse in BST 


void preorder(node* t) {
    if (t != NULL) {
        printf("%d\n", t->data); // ***Print the current node's data***
        preorder(t->left);     // ***Traverse left subtree recursively***
        preorder(t->right);    // ***Traverse right subtree recursively***
    }
}

//Inorder Tranverse in BST
void inorder(node* t){
    if(t != NULL){
        inorder(t->left);       // First recur on left subtree
        printf("%d\n",t->data); // Now deal with the node
        inorder(t->right);      // Then recur on right subtree
    }
}