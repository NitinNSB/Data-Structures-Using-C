#include<stdio.h>
#include<stdlib.h>

struct array {
    int capacity;
    int lastIndex;
    int *ptr;
};

struct array* createArray(int cap);

void appendValue(struct array * arr,int val);

void appendValueAtIndex(struct array * arr,int index,int val );

void displayElementAtIndex(struct array* arr,int index );

void editElement(struct array* arr ,int index ,int val);

void countElememt(struct array* arr);

void checkEmpty(struct array* arr);

void checkFull(struct array* arr);

void delElement(struct array* arr,int index);

void releaseMemory(struct array* arr);

void sortArray(struct array* arr);

void grstElement(struct array* arr);

void smlElement(struct array* arr);

void searchElement(struct array* arr,int element);

void sumOfElement(struct array* arr);

void avgOfElement(struct array* arr);

void secondLargestElement(struct array* arr);

void swapAtIndex(struct array* arr,int index1,int index2);

void duplicateRemover(struct array* arr);

void rotateArrayRight(struct array* arr);



int main(){
    struct array *arr;
    arr=createArray(4);
    appendValue(arr,8);
    appendValue(arr,3);
    appendValue(arr,8);
    appendValue(arr,3);
    duplicateRemover(arr);

    displayElementAtIndex(arr,0);
    displayElementAtIndex(arr,1);
    displayElementAtIndex(arr,2);
    displayElementAtIndex(arr,3);


}

//creating an array dynamically

struct array* createArray(int cap){
    struct array* arr;
    arr=(struct array*)malloc(sizeof(struct array));
    arr->capacity=cap;
    arr->lastIndex=-1;
    arr->ptr=(int *)malloc(sizeof(int)*cap);
    printf("Array created successfully.....\n");
    return arr;
}

//add value to an array

void appendValue(struct array *arr,int val){
    if((arr->lastIndex)<((arr->capacity)-1)){
        arr->ptr[(arr->lastIndex)+1]=val;
        (arr->lastIndex)++;  
        printf("Value Successfully appended in array....\n");
    }
    else{
        printf("Array overflow>>>>>>>>>\n");
    }
}

//Append the value at a given index in array

void appendValueAtIndex(struct array *arr,int index,int val){
    if(index<0 || index>((arr->lastIndex)+1)){
        printf("Invalid Index....");
    }else if((arr->lastIndex)==((arr->capacity)-1)){
        printf("Array Overflow>>>>");
    } else if(index==((arr->lastIndex)+1)){
        arr->ptr[(arr->lastIndex)+1]=val;
        (arr->lastIndex)++;  
        printf("Value Successfully appended in array....\n"); 
    }
    else{
        int temp=arr->lastIndex;
        int i;
        do{
            arr->ptr[temp+1]=arr->ptr[temp];
            temp--;
        }while(temp>index);
        arr->ptr[index]=val;
        printf("Value Successfully appended in array....\n"); 
        (arr->lastIndex)++;
    }
}

//display the element

void displayElementAtIndex(struct array* arr,int index){
    if(index>=0 && index<=arr->lastIndex)
        printf("Array value  at index %d is : %d\n",index,(arr->ptr[index]));
    else if(index>arr->lastIndex && index<arr->capacity)
        printf("This index is not filled yet...\n");
    else
        printf("Invalid Index..\n");
}

//edit the array

void editElement(struct array* arr,int index,int val){
    arr->ptr[index]=val;
    printf("Value is edited\n");
}

//count the elements in array

void countElememt(struct array* arr){
    printf("Number of element in array : %d\n",((arr->lastIndex)+1));
}

//check if array is empty

void checkEmpty(struct array* arr){
    if(arr->lastIndex==(-1)){
        printf("Array is Empty\n");
    }
    else{
        printf("Array is not empty\n");
    }
}

// check if array is full

void checkFull(struct array* arr){
    if(arr->lastIndex==(arr->capacity)-1){
        printf("Array is Full");
    }
    else{
        printf("Array has Some space");
    }
}

// deleting element of array

void delElement(struct array* arr,int index){
    int i;
    if(index>arr->capacity-1 || index<0){
        printf("Invalid index");
    }
    else {
        for(i=index;i<arr->capacity;i++){
            arr->ptr[i]=arr->ptr[i+1];
        }
        arr->ptr[i-1]=0;
        arr->lastIndex-=1;
    }
}

//Memory Release

void releaseMemory(struct array* arr){
    free(arr->ptr);
    free(arr);
    printf("\nMemory Released SuccessFully");
}

//sorting element of array

void sortArray(struct array* arr){
    int temp,i,j;
    for(i=0;i<=arr->lastIndex;i++){
        for(j=i+1;j<=arr->lastIndex;j++){
            if(arr->ptr[i]>arr->ptr[j]){
                temp=arr->ptr[j];
                arr->ptr[j]=arr->ptr[i];
                arr->ptr[i]=temp;
            }
        }
    }
}

//greatest element of array

void grstElement(struct array* arr){
    int temp=arr->ptr[0],i;
    for(i=1;i<=arr->lastIndex;i++){
        if(temp<arr->ptr[i]){
            temp=arr->ptr[i];
        }
    }
    printf("\nGreatest element : %d\n",temp);
}

//smallest Element of array

void smlElement(struct array* arr){
    int temp=arr->ptr[0],i;
    for(i=1;i<=arr->lastIndex;i++){
        if(temp>arr->ptr[i]){
            temp=arr->ptr[i];
        }
    }
    printf("\nSmallest element : %d\n",temp);
}

//search element

void searchElement(struct array* arr,int element){
    int i ;
    for(i=0;i<=arr->lastIndex;i++){
        if(arr->ptr[i]==element){
            printf("Element %d is at index %d\n",element,i);
            break;
        }
    }
    if(i>(arr->lastIndex)){
         printf("Element %d not found\n",element);
    }
}

//element sum

void sumOfElement(struct array* arr){
    int sum=0,i;
    for(i=0;i<=arr->lastIndex;i++){
        sum=sum+(arr->ptr[i]);
    }
    printf("Sum of elements : %d\n",sum);
}

//average of element

void avgOfElement(struct array* arr){
    int sum=0,i;
    for(i=0;i<=arr->lastIndex;i++){
        sum=sum+(arr->ptr[i]);
    }
    printf("\nAverage of elements : %d",(sum/(arr->capacity)));
}

//rotate an array toward right by one position
void rotateArrayRight(struct array* arr){
    int temp,i;
    if(arr->lastIndex==(arr->capacity-1)){
        temp=arr->ptr[arr->lastIndex];
        for(i=arr->lastIndex;i>=0;i--){
            arr->ptr[i]=arr->ptr[i-1];
        }
        arr->ptr[0]=temp;
    }
    else{
        for(i=arr->lastIndex;i>=0;i--){
            arr->ptr[i+1]=arr->ptr[i];
        }
        arr->ptr[0]=0;
    }
}
//remove duplicate element in an array
void duplicateRemover(struct array* arr){
    int temp,i,j,k;
    for(i=0;i<=arr->lastIndex;i++){
        for(j=i+1;j<=arr->lastIndex;j++){
            if(arr->ptr[i]==arr->ptr[j]){
                for(k=j;k<=arr->lastIndex;k++){
                    arr->ptr[k]=arr->ptr[k+1];
                }
                arr->ptr[arr->lastIndex]=0;
                arr->lastIndex--;
            }
        }
    }
}
//second largest element in an array
void secondLargestElement(struct array* arr){
    int temp=arr->ptr[0],i;
    int temp1=arr->ptr[0];
    for(i=1;i<=arr->lastIndex;i++){
        if(temp<arr->ptr[i]){
            temp=arr->ptr[i];
        }
    }
    for(i=1;i<=arr->lastIndex;i++){
        if(temp1<arr->ptr[i]){
            if(arr->ptr[i]!=temp){
                temp1=arr->ptr[i];
            }
             
        }
    }
    printf("\nSecond largest element is %d ",temp1);
}

//swap element with specified indices in the array

void swapAtIndex(struct array* arr,int index1,int index2){
    int temp;
    temp=arr->ptr[index1];
    arr->ptr[index1]=arr->ptr[index2];
    arr->ptr[index2]=temp;
}