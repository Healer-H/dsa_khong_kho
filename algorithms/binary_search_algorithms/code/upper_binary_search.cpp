#include <bits/stdc++.h>

using namespace std;

int upper_binary_search(int arr[], int left, int right, int value)
{
    if(arr[right] <= value) 
        return right + 1;
    
    if(arr[left] > value)
        return left;

    int ans = -1;
    while(left <= right)
    {
        int mid = left + (right - left) / 2;
        if(arr[mid] > value)
        {
            ans = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    return ans;
}
int main()
{
    // give a sorted arr
    int arr[] = {-23, -2, 3, 5, 12, 12, 20, 25, 30};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    // give a value to find
    int value = 31;

    int index = upper_binary_search(arr, 0, arr_size - 1, value);
    if(index != arr_size)
        cout << "The minimun greater element than " << value << " is at index " << index << ". \n";
    else
        cout << "All elements is not greater than " << value << ".\n";
    
    return 0;
}