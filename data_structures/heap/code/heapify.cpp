#include <iostream>

using namespace std;

void minHeapify(int arr[], int arr_size, int heapify_index)
{
    int left = 2 * heapify_index + 1;
    int right = 2 * heapify_index + 2;

    int min_position = heapify_index;
    
    if(left < arr_size && arr[left] < arr[min_position])
        min_position = left;

    if(right < arr_size && arr[right] < arr[min_position])
        min_position = right;
    
    if(min_position != heapify_index)
    {
        swap(arr[min_position], arr[heapify_index]);
        minHeapify(arr, arr_size, min_position);
    }
}

void maxHeapify(int arr[], int arr_size, int heapify_index)
{
    int left = 2 * heapify_index + 1;
    int right = 2 * heapify_index + 2;

    int max_position = heapify_index;
    
    if(left < arr_size && arr[left] > arr[max_position])
        max_position = left;

    if(right < arr_size && arr[right] > arr[max_position])
        max_position = right;
    
    if(max_position != heapify_index)
    {
        swap(arr[max_position], arr[heapify_index]);
        minHeapify(arr, arr_size, max_position);
    }
}

void buildMaxHeap(int arr[], int arr_size)
{
    for(int i = arr_size / 2  - 1; i >= 0; i--)
        maxHeapify(arr, arr_size, i);
}


void buildMinHeap(int arr[], int arr_size)
{
    for(int i = arr_size / 2  - 1; i >= 0; i--)
        minHeapify(arr, arr_size, i);
}

