#include <stdio.h>

// Function to heapify a subtrees of perticular node.

void heapify(int* arr, int size, int i){
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int largest = i;
    if(left < size && arr[left] > arr[largest] ) {
        largest = left;
    }
    if(right < size && arr[right] > arr[largest]) {
        largest = right;
    }
    if(largest != i){
        int temp = arr[largest];
        arr[largest] = arr[i];
        arr[i] = temp;
        heapify(arr, size, largest);
    }
}

// this function will pass each node, from last non leafNode to heapify function

void buildHeap(int* arr, int size){
    for(int i = (size / 2 - 1); i >= 0; i--) {
        heapify(arr, size, i);
    }
}

//Utility function to print array

void printArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


// main function
int main() {
    int arr[] = {22,9,0,8,6,5,7};
    int size = sizeof(arr) / sizeof(arr[0]);
    int temp;

    printf("Original array:\n");
    printArray(arr, size);
    // This loop repeatly build max-heap then extract root element.
    for(int i = size; i > 0 ;i--){
        buildHeap(arr, i);
        temp = arr[0];
        arr[0] = arr[i-1];
        arr[i-1] = temp;
    }
    
    printf("Sorted array:\n");
    printArray(arr, size);

    return 0;
}
