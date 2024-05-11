/*In Bubble Sort algorithm, 

    @ Traverse from left and compare adjacent elements and the higher one is placed at right side. 
    @ In this way, the largest element is moved to the rightmost end at first. 
    @ This process is then continued to find the second largest and place it and so on until the data is sorted.

*/
/*
    https://youtu.be/jpK5TwdIfSs?si=7cABey9f7uShnF0v&t=295 watch till 8:14.
*/

/*
    This algorithm is not suitable for large data sets as its average and worst-case time complexity is quite 
    high.
*/

/*  Time Complexity

    @ Best Case Complexity - It occurs when there is no sorting required, i.e. the array is already sorted. 
      The best-case time complexity of bubble sort is O(n).

    @ Average Case Complexity - It occurs when the array elements are in jumbled order that is not properly 
      ascending and not properly descending. The average case time complexity of bubble sort is O(n2).

    @ Worst Case Complexity - It occurs when the array elements are required to be sorted in reverse order. 
      That means suppose you have to sort the array elements in ascending order, but its elements are in 
      descending order. The worst-case time complexity of bubble sort is O(n2).

*/
/*  Space Complexity
    
    @ The space complexity of bubble sort is O(1). It is because, in bubble sort, 
      an extra variable is required for swapping.
    @The space complexity of optimized bubble sort is O(2). It is because two extra variables are 
      required in optimized bubble sort.

*/

#include<stdio.h>
int main(){
    int maxSize,i,round,temp;
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
        /*Ish variable ka use isliyai kiya hai ki tujai pata lag jayai ki ish itteration mai koi 
        swappping nahi hue hai,iska matlab hai ki array sorted hai,so you can break the loop*/
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
    printf("After sorting :\n");
    for(int i=0;i<maxSize;i++){
        printf("%d\n",array[i]);
    }
    return 0;
}