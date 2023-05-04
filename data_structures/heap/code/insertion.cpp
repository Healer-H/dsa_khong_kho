#include "heapify.cpp"

void insertMaxHeap(int arr[], int& arr_size, int insertValue)
{
    arr_size = arr_size + 1;

    arr[arr_size - 1] = insertValue;

    int curr_index = arr_size - 1;
    int parent_index = (curr_index - 1) / 2;

    while(curr_index > 0 && arr[parent_index] <= arr[curr_index])
    {
        swap(arr[curr_index], arr[parent_index]);

        curr_index = parent_index;
        parent_index = (curr_index - 1) / 2;
    }
}

void insertMinHeap(int arr[], int& arr_size, int insertValue)
{
    arr_size = arr_size + 1;

    arr[arr_size - 1] = insertValue;

    int curr_index = arr_size - 1;
    int parent_index = (curr_index - 1) / 2;

    while(curr_index > 0 && arr[parent_index] >= arr[curr_index])
    {
        swap(arr[curr_index], arr[parent_index]);

        curr_index = parent_index;
        parent_index = (curr_index - 1) / 2;
    }
}