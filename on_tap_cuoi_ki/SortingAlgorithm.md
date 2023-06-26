# Sorting Algorithm

## 1. Bubble Sort

### Ý tưởng

Duyệt tuần tự từ đầu đến đuôi, nếu gặp cặp giá trị không thỏa mãn thứ tự thì tiến hành đổi chỗ cho nhau.

### Mã giả

```
for i: 0 --> n - 2
    for j: i + 1 --> n - 1
        if: arr[i] > arr[j]
            swap(arr[i], arr[j])
```

### Code

```cpp
void bubble_sort(int arr[], int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(arr[i] > arr[j])
                swap(arr[i], arr[j]);
        }
    }
}
```

### Độ phức tạp

*Time Complexity:*

    Best Case: O(N^2)
    Avg Case: O(N^2)
    Worst Case: O(N^2)

*Space Complexity:* O(1)

## 2. Selection Sort

### Ý tưởng

Tìm phần tử nhỏ nhất (hoặc lớn nhất) trong mảng chưa được sắp xếp và hoán đổi với phần tử đầu tiên của mảng chưa được sắp xếp.

### Mã giả

```
for i: 0 --> n - 2
    int minIndex = i
    for j: i + 1 --> n - 1
        if: arr[j] < arr[minIndex]
            minIndex = j
    if: minIndex != i
        swap(arr[i], arr[minIndex])

```

### Code

```cpp
void selection_sort(int arr[], int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for(int j = i + 1; j < n; j++)
        {
            if(arr[j] < arr[minIndex])
               minIndex = j;
        }
        if(i != minIndex)
            swap(arr[i], arr[minIndex]);
    }
}
```

### Độ phức tạp

*Time Complexity:*

    Best Case: O(N^2)
    Avg Case: O(N^2)
    Worst Case: O(N^2)

*Space Complexity:* O(1)

## 3. Insertion Sort

### Ý tưởng

Tại mỗi bước, ta đưa phần tử đầu tiên của mảng chưa được sắp xếp vào vị trí đúng của nó trong mảng đã được sắp xếp.

### Mã giả

```
for i: 1 --> n - 1
    j = i - 1
    key = arr[i]
    while: j >= 0 && key < arr[j] 
        arr[j + 1] = arr[j]
        j = j - 1
    arr[j + 1] = key
```

### Code

```cpp
void insertion_sort(int arr[], int n)
{
    for(int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1; 
        while(j >= 0 && key < arr[j])
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
```

### Độ phức tạp

*Time Complexity:*

    Best Case: O(N) //khi mà thứ tự của mảng gần như là đúng
    Avg Case: O(N^2)
    Worst Case: O(N^2)

*Space Complexity:* O(1)

## 4. Merge Sort

### Ý tưởng

Thực hiện thao tác chia để trị: chia mảng lớn thành các mảng nhỏ hơn cho tới khi mảng đã có thứ tự thì tiến hành gộp các mảng để tạo thành mảng có thứ tứ.

### Mã giả

```
Tham khảo code bên dưới
```

### Code

```cpp
void merge(int arr[], int left, int mid, int right)
{
    int* sorted_arr = new int[right - left + 1];
    int id = 0; // current index of sorted_arr

    int i = left, j = mid + 1;
    while(i <= mid && j <= right)
    {
        if(arr[i] < arr[j])
        {
            sorted_arr[id] = arr[i];
            i++;
        }
        else
        {
            sorted_arr[id] = arr[j];
            j++;
        }
        id++;
    }
    while(i <= mid)
    {
        sorted_arr[id] = arr[i];
        i++;
        id++;
    }
    while(j <= right)
    {
        sorted_arr[id] = arr[j];
        j++;
        id++;
    }
    for(int i = 0; i < id; i++)
    {
        arr[left + i] = sorted_arr[i];
    }
    delete [] sorted_arr;
}

void merge_sort(int arr[], int left, int right)
{
    // base case
    if(left == right)
        return;
    int mid = (left + right) / 2;
    merge_sort(arr, left, mid);
    merge_sort(arr, mid + 1, right);
    merge(arr, left, mid, right);
    
}
```

### Độ phức tạp

*Time Complexity:*

    Best Case: O(NlogN)
    Avg Case: O(NlogN)
    Worst Case: O(NlogN)

*Space Complexity:* O(N)

## 5. Quick Sort

## 6. Heap Sort

### Ý tưởng

Sử dụng cấu trúc dữ liệu Heap để lưu trữ các phần tử chưa được sắp xếp, lấy lần lượt từng phần tử nhỏ nhất trong cây heap để đưa vào mảng đã sắp xếp.

### Mã giả

```
Tham khảo code bên dưới
```

### Code

```cpp
void heapify(int arr[], int n, int id)
{
    int leftChild = 2 * id + 1;
    int rightChild = 2 * id + 2;
    int maxIndex = id;

    if(leftChild < n && arr[leftChild] > arr[maxIndex])
        maxIndex = leftChild;
    if(rightChild < n && arr[rightChild] > arr[maxIndex])
        maxIndex = rightChild;
    
    if(maxIndex != id)
    {
        swap(arr[maxIndex], arr[id]);
        heapify(arr, n, maxIndex);
    }
}

void buildHeap(int arr[], int n)
{
    for(int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
}

void heapSort(int arr[], int n)
{
    buildHeap(arr, n);
    int heapSize = n;

    while(heapSize > 0)
    {
        swap(arr[0], arr[heapSize - 1]);
        heapSize--;
        heapify(arr, heapSize, 0);
    }
}
```

### Độ phức tạp

*Time Complexity:*

    Best Case: O(NlogN)
    Avg Case: O(NlogN)
    Worst Case: O(NlogN)

*Space Complexity:* O(N)
