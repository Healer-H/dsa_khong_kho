#include <iostream>
#include "heapify.cpp"
using namespace std;

int deleteMaxHeap(int arr[], int& arr_size)
{
    int top_element = arr[0];

    arr[0] = arr[arr_size - 1];

    arr_size = arr_size - 1;

    maxHeapify(arr, arr_size, 0);

    return top_element;
}

int deleteMinHeap(int arr[], int& arr_size)
{
    int top_element = arr[0];

    arr[0] = arr[arr_size - 1];

    arr_size = arr_size - 1;

    minHeapify(arr, arr_size, 0);

    return top_element;
}
