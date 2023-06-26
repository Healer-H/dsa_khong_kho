# Searching Algorithm

## 1. Linear Search

### Ý tưởng

Tìm kiếm tuần từ từ đầu này sang đầu kia đến khi tìm thấy giá trị thì dừng

### Mã giả

```
for i: 0 --> n - 1
    if(a[i] == to_find)
        return i
    return -1
```

### Code

```cpp
int linearSearch(int arr[], int n, int to_find)
{
    for(int i = 0; i < n; i++)
    {
        if(a[i] == to_find)
            return i;
        return -1; //not find
    }
}
```

### Độ phức tạp

*Time Complexity:*

    Best Case: O(1)
    Avg Case: O(N)
    Worst Case: O(N)

*Space Complexity:* O(1)

## 2. Binary Search

### Ý tưởng

Tìm kiếm giá trị trên một mảng đã sắp xếp bằng cách giảm một nửa phạm vi tìm kiếm sau mỗi bước.

### Mã giả

```
left = 0, right = n - 1
while: left <= right
    mid = (left + right) / 2
    if: arr[mid] = to_find
        return mid
    if: arr[mid] > to_find
        right = mid - 1
    else
        left = mid + 1

return -1
```

### Code

```cpp
int binary_seach(int arr[], int left, int right, int to_find)
{
    while(left <= right)
    {
        int mid = (left + right) / 2;
        if(arr[mid] == to_find)
            return mid;
        if(arr[mid] > to_find)
            right = mid - 1;
        else 
            left = mid + 1;
    }
    return -1;
}
```

### Độ phức tạp

*Time Complexity:*

    Best Case: O(1)
    Avg Case: O(logN) 
    Worst Case: O(logN)

*Space Complexity:* O(1)

## 3. Interpolation Search

### Ý tưởng

Tìm kiếm giá trị trên một mảng đã sắp xếp bằng cách tìm kiếm trên vùng gần với giá trị cần tìm hơn.

### Mã giả

```
left = 0, right = n - 1
while: left <= right
    mid = left + (right - left) * (to_find - arr[left]) / (arr[right] - arr[left])
    if: arr[mid] = to_find
        return mid
    if: arr[mid] > to_find
        right = mid - 1
    else
        left = mid + 1

return -1
```

### Code

```cpp
int interpolation_search(int arr[], int left, int right, int to_find)
{
    while(left <= right)
    {
        int mid = left + (right - left) * (to_find - arr[left]) / (arr[right] - arr[left]);
        if(arr[mid] == to_find)
            return mid;
        if(arr[mid] > to_find)
            right = mid - 1;
        else 
            left = mid + 1;
    }
    return -1;
}
```

### Độ phức tạp

*Time Complexity:*

    Best Case: O(1) // mới vô tìm thấy ngay
    Avg Case: O(loglogN) 
    Worst Case: O(N) // khi tập dữ liệu phân bố không đều

*Space Complexity:* O(1)
