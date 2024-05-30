#include<stdio.h>
#include<stdlib.h>
typedef struct array{
   int index;
   int capacity;
   int* ptr;
}heap;


heap* createHeap(int capacity);

void insert(heap* hp, int data);

int top(heap* hp);

void delete(heap* hp);

int main(){
    // Edge Case 1: Create a heap with zero capacity
    heap* zero_capacity_heap = createHeap(0);
    if (zero_capacity_heap == NULL || zero_capacity_heap->ptr == NULL) {
        printf("Heap with zero capacity could not be created or has no storage.\n");
    }

    // Normal Case: Create a heap with an initial capacity of 5
    heap* hp = createHeap(5);
    if (hp == NULL) {
        printf("Failed to create heap.\n");
        return 1;
    }

    // Edge Case 2: Insert into an empty heap
    printf("Inserting 10 into the heap.\n");
    insert(hp, 10);
    printf("Top element after inserting 10: %d\n", top(hp));  // Should be 10

    // Insert more elements into the heap
    insert(hp, 20);
    insert(hp, 5);
    insert(hp, 30);
    insert(hp, 15);

    // Print the top element
    printf("Top element: %d\n", top(hp));  // Should be 30

    // Edge Case 3: Insert into a heap that requires dynamic resizing
    printf("Inserting 25 into the heap (should trigger resizing).\n");
    insert(hp, 25);
    printf("Top element after inserting 25: %d\n", top(hp));  // Should be 30

    // Delete the top element
    delete(hp);
    printf("Top element after deletion: %d\n", top(hp));  // Should be 25

    // Insert another element
    insert(hp, 40);
    printf("Top element after inserting 40: %d\n", top(hp));  // Should be 40

    // Edge Case 4: Delete from an empty heap
    delete(hp); // 40
    delete(hp); // 25
    delete(hp); // 20
    delete(hp); // 15
    delete(hp); // 10
    delete(hp); // 5 (heap is now empty)
    printf("Top element after deleting all elements: %d\n", top(hp));  // Should be 0

    // Edge Case 5: Get top element from an empty heap
    printf("Top element from an empty heap: %d\n", top(hp));  // Should handle gracefully

    // Edge Case 6: Delete from an empty heap
    delete(hp);  // Should handle gracefully with an error message

    // Free the heap memory
    free(hp->ptr);
    free(hp);

    return 0;
}

//Function to create heap.


heap* createHeap(int capacity){
   heap* hp = (heap*)malloc(sizeof(heap));
   if (hp == NULL) {
       return NULL;  // memory allocation failed
   }
   hp->index = -1;
   hp->capacity = capacity;
   hp->ptr = (int*)malloc(sizeof(int)*capacity);
   if (hp->ptr == NULL) {
       free(hp);  // free the previously allocated memory
       return NULL;  // memory allocation failed
   }
   return hp;
}

// function to insert data in heap.


void insert(heap* hp, int data){
   if(hp == NULL){
      printf("ERROR: Heap not created yet.\n");
      return;
   } else if(hp->index == hp->capacity-1) {
      hp->capacity *= 2;
      int* new_ptr = (int*)realloc(hp->ptr,hp->capacity * sizeof(int));
      if(new_ptr == NULL){
         printf("ERROR: Heap is full and Reallocation failed.\n");
         return;
      }
      hp->ptr = new_ptr;
   }
   hp->index++;
   hp->ptr[hp->index] = data;
   int tempIndex = hp->index;
   while(tempIndex >0){
      int i = (tempIndex - 1) / 2;
      if(hp->ptr[i] >= hp->ptr[tempIndex]){
         break;
      }
      int temp = hp->ptr[i];
      hp->ptr[i] = hp->ptr[tempIndex];
      hp->ptr[tempIndex] = temp;
      tempIndex = i;
   }
}

// Function to return top element from heap


int top(heap* hp){
   if(hp == NULL ) {
      printf("ERROR: Heap not created.\n");
      return -1;
   } else if(hp->index == -1){
      return 0;
   }
   return hp->ptr[0];
}


// Function to delete an element from heap


void delete(heap* hp) {
   if(hp == NULL ) {
      printf("ERROR: Heap not created.\n");
   } else if(hp->index == -1) {
      printf("ERROR: Heap is empty.\n");
   } else if(hp->index == 0) {
      hp->index = -1;
   } else {
      int lastElement = hp->ptr[hp->index];
      hp->ptr[0] = lastElement;
      hp->index--;
      int i = 0;
      while(1) {
         int left = 2 * i + 1;
         int right = 2 * i + 2;
         int largest = i;
         if(left <= hp->index && hp->ptr[left] > hp->ptr[largest]) {
            largest = left;
         }
         if(right <= hp->index && hp->ptr[right] > hp->ptr[largest]) {
            largest = right;
         }
         if(largest != i) { 
            hp->ptr[i] = hp->ptr[largest];
            hp->ptr[largest] = lastElement;
            i = largest;
         } else{
            break;
         }
      }
   }
}
