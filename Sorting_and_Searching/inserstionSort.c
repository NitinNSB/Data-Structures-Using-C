/*Insertion Sort = Insert an element from unsorted array to its correct position in the sorted array*/

/*ish sorting algo mai tu do part laita hai ,sorted and unsorted. starting mai 1st element sorted hai,or 
baki unsorted.Toh loop index 1 sai chalaiga.Or fir 2 do -do element karkai agai badiaga.then sorted unsorted part 
mai changes hunga*/ 

/*https://youtu.be/3GC83dh4cf0?si=n-uq_f2-1nJF_80v&t=39    watch till 3:20*/

/*Time Complexity of Insertion Sort

    @ The worst-case time complexity of the Insertion sort is O(N^2)
    @ The average case time complexity of the Insertion sort is O(N^2)
    @ The time complexity of the best case is O(N).

    https://youtu.be/4Zpw8pxnf2M?si=5EaUHBojzjFB9KiS&t=551   watch till 10:30

*/

/*Space Complexity of Insertion Sort

    @ The auxiliary space complexity of Insertion Sort is O(1)

*/

/*Insertion sort is adaptive in nature, i.e. it is appropriate for data sets that are already 
partially sorted. Basically, Insertion sort is efficient for small data values*/ 
   


#include<stdio.h>
#include<stdlib.h>
void insertionSort(int array[] ,int size);
void main(){
    int* array;
    int num;
    printf("Enter the no of elements in array : ");
    scanf("%d",&num);
    array=(int*)malloc(sizeof(int)*num);
    printf("Enter the Array Element:\n");
    for(int i=0;i<num;i++){
        scanf("%d",&array[i]);
    } 
    insertionSort(array,num);
    printf("Array After Sorting:\n");
    for(int i=0;i<num;i++){
        printf("%d\n",array[i]);
    }

}

//Insertion Sort function

void insertionSort(int* array ,int size){
    int temp=0;
    for(int i=1;i<size;i++){
        if(array[i]<array[i-1]){
            temp=array[i];
            array[i]=array[i-1];
            array[i-1]=temp;
            for(int j=(i-1);j>0 && (array[j]<array[j-1]) ;j--){
                temp=array[j];
                array[j]=array[j-1];
                array[j-1]=temp;
            }
        }
    }
}
