// The sorting you are doing ,way before you know types of sorting is called selection sort.
// Complexity Analysis of Selection Sort

// Time Complexity: The time complexity of Selection Sort is O(N2) as there are two nested loops:

//     One loop to select an element of Array one by one = O(N)
//     Another loop to compare that element with every other Array element = O(N)
//     Therefore overall complexity = O(N) * O(N) = O(N*N) = O(N2)

// Auxiliary Space: O(1) as the only extra memory used is for temporary variables while swapping two values in Array. 
// The selection sort never makes more than O(N) swaps and can be useful when memory writing is costly. 
#include<stdio.h>


void selectionSort(int* arr, int size){
    int i ,j;    
    for(i =0; i < size-1; i++){
        int smallest = i;
        for(j = i+1 ;j < size; j++){
            if(arr[smallest] > arr[j]){
                smallest = j;
            }
        }
        if(smallest != i){
           int temp = arr[i];
           arr[i] = arr[smallest];
           arr[smallest] = temp;
        }
 
    }
}
int main(){
    int arr[6] = {11,2,22,7,0,1};
    selectionSort(arr, 6);
    for(int i=0; i < 6; i++){
        printf("%d",arr[i]);
        if(i != 5){
            printf(" -> ");
        }
    }
}