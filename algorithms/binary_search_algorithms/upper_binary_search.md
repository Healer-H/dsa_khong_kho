# **Bài toán**
**Cho một mảng đã được sắp xếp _(a sorted array)_ và một giá trị $value$. Hãy viết chương trình trả về chỉ số của phần tử nhỏ nhất lớn hơn $value$. Nếu không tìm được phần tử như vậy, trả về chỉ số sau phần tử lớn nhất.**

# **Ý tưởng**
**Sử dụng Binary Search: tại mỗi bước kiểm tra xem giá trị $middle$ đã vượt qua $value$ hay chưa**
* Nếu chưa $\Rightarrow$ tăng giá trị $middle$
* Nếu rồi $\Rightarrow$ lưu giá trị $middle$ lại vào biến $ans$ và giảm giá trị $middle$ để xét xem còn số nào nhỏ hơn nữa hay không.

# **Code**
```cpp
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
```
# **Sử dụng hàm sẵn có trong thư viện STL**
*Thư viện STL của C++ cung cấp sẵn hàm _upper_bound()_ với công dụng gần tương tự như trên. Điểm khác biệt nằm ở tham số truyền vào _(args)_ và giá trị trả về _(return value)_.*

- **Tham số:** _upper_bound(Start_Iterator, End_Iterator, Value)_

    - Ví dụ: `upper_bound(arr, arr + n, 24);`, `upper_bound(vec.begin(), vec.end(), 24)`

- **Return Value:** trả về địa chỉ trỏ vào phần tử thỏa mãn.

*Tip:* vì hàm _upper_bound()_ trả về giá trị con trỏ trỏ vào phần tử cần tìm nên chúng ta có thể:
- Lấy giá trị mong muốn bằng toán tử giải địa chỉ '*': 
```
cout << *upper_bound(arr, arr + n, 24); 
\\in ra giá trị nhỏ nhất lớn hơn 24
```
- Lấy chỉ số của phần tử bằng cách trừ cho con trỏ trỏ vào phần tử đầu tiên: 
```
int index = upper_bound(arr, arr + n, 24) - arr; \\lúc này arr[index] là giá trị nhỏ nhất lớn hơn 24
```



