# Cấu trúc dữ liệu: Heap

## Khái niệm

* Heap là một cấu trúc dữ liệu xây dựng trên một cây nhị phân hoàn chỉnh *(complete binary tree)*.

* Có hai loại Heap là Min Heap và Max Heap

  * Max Heap: giá trị tại gốc lớn hơn giá trị của hai con và mỗi cây con cũng là một Max Heap.

  * Min Heap: giá trị tại gốc nhỏ hơn giá trị của hai con mỗi cây con cũng là một Min Heap.

## Các thao tác trên Heap (Operations of Heap Data Structure)

* **Heapify**: thao tác hiệu chỉnh cây Heap tại một node trong array.

* **Deletion**: thao tác xóa phần tử gốc của Heap và cập nhật lại cây Heap.
* **Insertion**: thao tác chèn một phần tử.

### Heapify

Thao tác Heapify tại một node sẽ thay đổi mảng sao cho node đó trở thành gốc của một cây Heap.

*Lưu ý: Heapify không có tác dụng xây dựng nên một cây Heap thực sự. Muốn xây dựng một cây Heap ta cần phải thực hiện  thao tác Heapify từ cuối về đầu.*

Dưới đây là code tham khảo hàm $minHeapify()$

C++

```cpp
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
```

### Deletion

Thao tác Deletion sẽ xóa phần tử nằm ở gốc của cây Heap. Ý tưởng của thao tác này là swap giá trị của phần tử ở gốc và phần tử cuối cùng $\rightarrow$ bỏ phần tử cuối cùng $\rightarrow$ Heapify tại vị trí gốc.

Code tham khảo:

```cpp
int deleteMinHeap(int arr[], int& arr_size)
{
    int top_element = arr[0];

    arr[0] = arr[arr_size - 1];

    arr_size = arr_size - 1;

    minHeapify(arr, arr_size, 0);

    return top_element;
}
```

### Insertion

Thao tác chèn một phần tử có ý tưởng tương tự như thao tác xóa: tăng kích thước của mảng lên sau đó đưa phần tử cần chèn vào cuối mảng. Điểm khác nhau ở chỗ cách tìm vị trí đúng cho phần tử được thêm vào này. Để ý rằng với một cây Heap có trước, ta chỉ cần đổi chỗ phần tử mới thêm vào với phần tử cha của nó (một số lần nhất định) cho tới khi phần tử mới được đặt đúng vị trí mà không cần phải gọi hàm Heapify.

Code tham khảo:

```cpp
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
```

## Xem thêm tại

1. [Heap Data Structure - Geeksforgeeks](https://www.geeksforgeeks.org/heap-data-structure/)
2. [Heap và Priority Queue của C++ - Viblo](https://viblo.asia/p/heap-va-priority-queue-cua-c-gAm5ymYX5db)
