#include<stdio.h>
#include<stdlib.h>
struct DynArray{
    int capacity;
    int lastIndex;
    int* ptr;
};
struct DynArray* createArray(int size);

void doubleArray(struct DynArray* Arr);

void halfArray(struct DynArray* Arr);

void appendElement(struct DynArray* Arr,int val);

void insertElementAtIndex(struct DynArray* Arr,int index,int value);

int getValueAtIndex(struct DynArray* Arr,int index);

void editValueAtIndex(struct DynArray* Arr,int index,int value);

int countElement(struct DynArray* Arr);

void checkEmpty(struct DynArray* Arr);

void checkFull(struct DynArray* Arr);

void releaseMemory(struct DynArray* Arr);

void deleteElementAtIndex(struct DynArray* Arr,int index);

void main(){
    struct DynArray * Array;
    Array=NULL;
    Array=createArray(2);
    appendElement(Array,5);
    appendElement(Array,7);
    printf("\n%d\n",getValueAtIndex(Array,0));
    printf("%d\n",getValueAtIndex(Array,1));
    printf("capacity = %d\n",Array->capacity);
    appendElement(Array,8);
    printf("%d\n",getValueAtIndex(Array,2));
    printf("capacity = %d\n",Array->capacity);
    deleteElementAtIndex(Array,0);
    printf("capacity = %d\n",Array->capacity);
    printf("%d\n",getValueAtIndex(Array,0));
    printf("%d\n",getValueAtIndex(Array,1));
    printf("%d\n",getValueAtIndex(Array,2));
    deleteElementAtIndex(Array,0);
    printf("capacity = %d\n",Array->capacity);
    printf("%d\n",getValueAtIndex(Array,0));
    printf("%d\n",getValueAtIndex(Array,1));
    printf("%d\n",getValueAtIndex(Array,2));
    deleteElementAtIndex(Array,0);
    printf("capacity = %d\n",Array->capacity);
    printf("%d\n",getValueAtIndex(Array,0));
    appendElement(Array,8);
    printf("capacity = %d\n",Array->capacity);
    printf("%d\n",getValueAtIndex(Array,0));
    appendElement(Array,9);
    printf("capacity = %d\n",Array->capacity);
    printf("%d\n",getValueAtIndex(Array,1));
}


// Function to Create Array variable dynamically and initilize member variable.
struct DynArray* createArray(int size){
    struct DynArray* Arr;
    Arr=(struct DynArray*)malloc(sizeof(struct DynArray));
    Arr->capacity=size;
    Arr->lastIndex=-1;
    Arr->ptr=(int*)(malloc(sizeof(int)*size));
    printf("Array crerated Successfully...");
    return Arr;
}
// method doubleArray() to increase the size of array by  double of its size.

void doubleArray(struct DynArray* Arr){
    int* temp;
    temp=(int*)malloc(sizeof(int)*Arr->capacity*2);
    Arr->capacity=Arr->capacity*2;
    for(int i=0;i<=Arr->lastIndex;i++){
      temp[i]=Arr->ptr[i];
    }
    free(Arr->ptr);
    Arr->ptr=temp;
}

//method halfArray() to decrease the size of array by half
 
 void halfArray(struct DynArray* Arr){
    int* temp;
    temp=(int*)malloc(sizeof(int)*(Arr->capacity/2));
    Arr->capacity=Arr->capacity/2;
    for(int i=0;i<=Arr->lastIndex;i++){
      temp[i]=Arr->ptr[i];
    }
    free(Arr->ptr);
    Arr->ptr=temp;
}

//append value in an array.

void appendElement(struct DynArray* Arr,int val){
    if(Arr==NULL){
        printf("Array is not created Yet\n");
    }
    else{ 
        if(Arr->lastIndex==Arr->capacity-1){
            doubleArray(Arr);
        }
        Arr->lastIndex++;
        Arr->ptr[Arr->lastIndex]=val;
    }
    
}

// insert value at a given index.

void insertElementAtIndex(struct DynArray* Arr,int index,int value){
    if(Arr==NULL){
        printf("Array is not created Yet\n");
    }
    else if(index<0||index>Arr->lastIndex+1){
        printf("Invalid index.\n");
    }
    else {
        if(Arr->lastIndex==Arr->capacity-1){
            doubleArray(Arr);
        }
        if(index==Arr->lastIndex+1){
            Arr->ptr[index]=value;
            Arr->lastIndex++;
        }
        else{
            for(int i=Arr->lastIndex;i>=index;i--){
                Arr->ptr[i+1]=Arr->ptr[i];
            }
            Arr->ptr[index]=value;
            Arr->lastIndex++;
        }
    }
}

//get value at a given index.

int getValueAtIndex(struct DynArray* Arr,int index){
    if(Arr==NULL){
        printf("Array is not created Yet. ");
        return -1;
    }
    else if(index<0||index>Arr->capacity-1){
        printf("Invalid index. ");
        return -1;
    }
    else if(index>Arr->lastIndex){
        printf("These index Are not Filled Yet. ");
        return -1;
    }
    else{
        return Arr->ptr[index];
    }
}

//edit a value at given index

void editValueAtIndex(struct DynArray* Arr,int index,int value){
    if(Arr==NULL){
        printf("Array is not created Yet\n");
    }
    else if(index<0||index>Arr->lastIndex){
        printf("Invalid index.\n");
    }
    else{
        Arr->ptr[index]=value;
    }
}

//count number of element present in array.

int countElement(struct DynArray* Arr){
    if(Arr==NULL){
        printf("Array is not created Yet ");
        return -1;
    }
    else
        return Arr->lastIndex+1;
}

//check if array is empty

void checkEmpty(struct DynArray* Arr){
    if(Arr==NULL){
        printf("Array is not created Yet\n");
    }
    else if(Arr->lastIndex==(-1)){
        printf("Array is empty.\n");
    }
    else
        printf("Array is not Empty.\n");
}

//check if array is full

void checkFull(struct DynArray* Arr){
    if(Arr==NULL){
        printf("Array is not created Yet\n");
    }
    else if(Arr->lastIndex==(Arr->capacity-1)){
        printf("Array is Full.\n");
    }
    else
        printf("Array is not Full.\n");
}

//Systematic Memory Release

void releaseMemory(struct DynArray* Arr){
    if(Arr==NULL){
        printf("Array is not created Yet\n");
    }
    else{
        free(Arr->ptr);
        free(Arr);
    }
}

//define a function to delete an element of array.

void deleteElementAtIndex(struct DynArray* Arr,int index){
        if(Arr==NULL){
        printf("Array is not created Yet\n");
    }
    else if(index<0||index>Arr->lastIndex){
        printf("Invalid Index\n");
    }
    else{
        if(index==Arr->lastIndex){
            Arr->lastIndex--;
        }
        else{
            for(int i=index;i<Arr->lastIndex;i++){
                Arr->ptr[i]=Arr->ptr[i+1];
            }
            Arr->lastIndex--;
        }
        if(((Arr->lastIndex)>=0)&&(countElement(Arr)<=Arr->capacity/2)){
            halfArray(Arr);
        }
    }
}
