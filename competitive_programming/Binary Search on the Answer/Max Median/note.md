# Problem Max Median - Codeforces

## Link

<https://codeforces.com/problemset/problem/1486/D>

## Key Points

* Output cần tìm là _maximun median_ $\in \left [ 1, n\right ]$. Ý tưởng là nếu ta tìm được một con số _median_ thỏa điều kiện bài toán thì ta kỳ vọng có thể tìm được một  con _median_ khác nhỏ hơn _median_ hiện tại. Ngược lại, nếu ta có một con số _median_ không thỏa được điều kiện đề bài, những số nhỏ hơn _median_ đều không thể là trung bị của một đoạn nào đó thỏa đề bài được.
* Nếu số số bé hơn $value$ ít hơn số số lớn hơn hoặc bằng $value$ thì có một đoạn nào đó mà $value$ làm trung vị. Đồng thời ta có thể tính chính xác độ dài lớn nhất của đoạn nhận $value$ làm giá trị trung vị.
* Mối quan hệ mà ta quan tâm ở đây là $<$ và $\geqslant$, không cần nắm rõ giá trị cụ thể, do đó mà ta có thể "nén số" bằng cách thay đổi tất cả các giá trị $<$ $value$ thành $-1$ và các giá trị $\geqslant$ $value$ thành $1$ trước rồi mới xử lý.

## Solution

Thực hiện Binary Search the Answer. Chọn giá trị _median_, tièn xử lý mảng theo nhận xét bên trên, kiểm tra _median_ có thỏa điều kiện không và tiến hành cập nhật.

## Code

```cpp


```

### Complexity Anysis

* _Time Complexity:_
* _Space Complexity:_

## Comment
