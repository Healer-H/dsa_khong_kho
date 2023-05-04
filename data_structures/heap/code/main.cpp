#include <bits/stdc++.h>
// #include "deletion.cpp"
#include "insertion.cpp"

using namespace std;

int main()
{
    // give an array
    int arr[10] = {123, -2, 23, 1, 5, 45, -5, 6};
    int size = 8;

    // minHeapify(arr, size, 0);

    // for(int i = 0; i < size; i++)
    //     cout << arr[i] << " ";
    // cout << endl;

    // maxHeapify(arr, size, 1);

    // for(int i = 0; i < size; i++)
    //     cout << arr[i] << " ";

    buildMaxHeap(arr, size);


    for(int x : arr)
        cout << x << " ";
    cout << endl;
    // deleteMinHeap(arr, size);

    insertMaxHeap(arr, size, 21);
    for(int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}