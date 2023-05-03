#include <bits/stdc++.h>

using namespace std;

// return the index of value in arr[left..right]
// return -1 if not find the value
int binary_search(int arr[], int left, int right, int value)
{
    while(left <= right)
    {
        int mid = left + (right - left) / 2;
        if(arr[mid] == value)
            return mid;
        if(arr[mid] > value)
            right = mid - 1;
        else
            left = mid + 1; 
    }
    return -1;
}

int main()
{
    // give a sorted arr
    int arr[] = {-23, -2, 3, 5, 12, 12, 20, 25, 30};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    // give a value to find
    int value = 20;

    int index = binary_search(arr, 0, arr_size - 1, value);
    
    if(index != -1)
        cout << "Found " << value << " at position " << index << ". \n";
    else
        cout << "Not found " << value << ". \n"; 
    
    return 0;
}