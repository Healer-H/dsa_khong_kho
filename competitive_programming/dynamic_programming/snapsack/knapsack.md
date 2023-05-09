# 0|1 Knapsack Problem

Link: <https://atcoder.jp/contests/dp/tasks/dp_e>

## Approach

### Dynamic Programing

Để giải quyết bài toán Knapsack bằng Dynamic Programming thì ta dùng một mảng hai chiều $f[m][n]$ để lưu kết quả với ý nghĩa là 'maximun value' khi ta xét tới chiếc túi thứ $m$ trong dãy biết rằng $weight \leq n$. Như vậy khi xét tới chiếc túi thứ $m + 1$, ta có hai phương án

* Lấy chiếc túi thứ $m + 1$ với trọng lượng $w_{n+1} $ và giá trị $v_{m+1} $. Khi đó trọng lượng còn trống sẽ là $n - w_{m + 1}$ và ta chỉ cần gọi đến giá trị $f[m + 1][n - w_{m + 1}]$.

* Không lấy chiếc túi thứ $m + 1$. Khi đó trọng lượng tối đa bằng với trọng lượng tối đa của $m$ chiếc túi trước đó với cùng trọng số $n$.

Do vậy ta có công thức quy hoạch động

$$f[m][n] = \max(f[m - 1][n], f[m - 1][n - w_m] + v_m)$$

Ta có thể dụng một bảng 2 chiều để trực quan hóa công thức này một cách dễ hơn.

Ta chú ý đến các base-case $f[0][i] = 0$ và $f[i][0] = 0$ đồng thời nếu chỉ số truyền vào $ < 0$ thì ta xem như biểu thức đó không tồn tại.

*Algorithm Analysis*

* Time Complexity: $O(M \times N)$
* Space Complexity: $O(M \times N)$

We can use this algorithm when $M \times N \leq 1e7$ and get the AC verdict.
