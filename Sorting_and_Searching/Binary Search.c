#include<stdio.h>
int binarySearch(int arr[],int arrayLength,int value);
int findFrequency(int arr[],int arrayLength,int value);
int main(){
    int maxSize,i,round,temp;

    /*
    Use of Variable length Array (VLA).VLAs are a feature introduced in C99,
    to allow arrays with sizes that can be determined at runtime.While VLAs 
    provide dynamic array capabilities, they are not included in the C11 standard and 
    later.
    */

    printf("Enter the max Size of array: ");
    scanf("%d",&maxSize);
    int array[maxSize];
    printf("Enter The Array:\n");
    for(i=0;i<maxSize;i++){
        scanf("%d",&array[i]);
    }

    //sorting array using bubble sort

    for(round=0;round<(maxSize-1);round++){
        int flag=0;
        for(i=0;i<(maxSize-round-1);i++){
            if(array[i]>array[i+1]){
                flag=1;
                temp=array[i+1];
                array[i+1]=array[i];
                array[i]=temp;
            }
        }
        if(flag==0){
            break;
        }
    }
    //Binary search
    
    int s;
    printf("Enter no to be searched:");
    scanf("%d",&s);
    printf("Number is at Index %d after sorting\n",binarySearch(array,maxSize,s));

   // frequency of each element present in the array

    printf("Frequency of each element present in the array : \n");
    for(int i=0;i<maxSize-1;i++){
        if(array[i]!=array[i+1]){
            printf("Frequency of %d is : %d\n",array[i],findFrequency(array,maxSize,array[i]));
        }
        if((i+2)==maxSize){
            printf("Frequency of %d is : %d\n",array[i+1],findFrequency(array,maxSize,array[i+1]));
        }
    }
    
}

/*Binary search  , it has Uncertainty with Duplicates,so i also added a improvement,in case of duplicate*/
/*Array need to be sorted before using this algo*/
/*https://youtu.be/Dz2-NUQMNH8?si=fGf0SQMRlUCxulz0&t=90 watch till 12:45*/
/*Time Complexity: 

    Best Case: O(1),i.e element found in first itteration.
    Average Case: O(log N)
    Worst Case: O(log N)
    
*/
int binarySearch(int arr[],int arrayLength,int value){
    int lowerLimit=0;
    int upperLimit=arrayLength-1;
    int mid=0;
    while(lowerLimit<=upperLimit){
        mid=(lowerLimit+upperLimit)/2;
        if(arr[mid]==value){
            //To find first occurence in case of duplicates.   
            while((arr[mid]==value) && (mid>=lowerLimit)){ 
                mid--;
            }
            return mid+1;
        }
        else if(arr[mid]<value){
            lowerLimit=mid+1;
        }
        else{
            upperLimit=mid-1;
        }
    }
    return -1;
}

//Find frequency of element

int findFrequency(int arr[],int arrayLength,int value){
   int i,count=0;
   int firstIndex=binarySearch(arr,arrayLength,value);
   for(i=firstIndex;(arr[i]==value) && (i<arrayLength);i++){
       count++;
   }
   return count;
}