//selection sort
#include <stdio.h>
void swap(int*a, int*b){
  int c = *a;
  *a = *b;
  *b = c;
}
//selection sort
void selectionSort(int arr[], int n)
{
    int i, min_idx;
 
    // One by one move boundary of unsorted subarray
    for (i = 0; i < n-1; i++)
    {
        // Find the minimum element in unsorted array
      min_idx = i;
      for (int j = i+1;j<n;j++){
        if(arr[min_idx]>arr[j])
          min_idx = j;
      }
        // Swap the found minimum element with the first element
      if (arr[min_idx]<arr[i])    
       swap(&arr[min_idx], &arr[i]);
    }
}
//bubble sort
void bubbleSort(int*arr, int n)
{
  for(int i = 0;i<n-1;i++){
     for (int j = 0; j < n - i - 1; j++){
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);}
    }
  }
//insertion sort
void insertionSort(int array[], int size) {
  for (int step = 1; step < size; step++) {
    int key = array[step];
    int j = step - 1;

    // Compare key with each element on the left of it until an element smaller than
    // it is found.
    // For descending order, change key<array[j] to key>array[j].
    while (key < array[j] && j >= 0) {
      array[j + 1] = array[j];
      --j;
    }
    array[j + 1] = key;
  }
