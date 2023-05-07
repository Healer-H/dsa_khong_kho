# Problem: Longest Common Subsequence

## Link: <https://vjudge.net/problem/UVA-10405>

Difficulty: > Easy

## Phân tích

* Bài toán yêu cầu tìm một số - độ dài dãy con chung lớn nhất của hai chuỗi $\Rightarrow$ ý tưởng liên quan tới Quy hoạch động.

* Bài toán con: tại vị trí thứ $i$ của chuỗi thứ nhất và vị trí thứ $j$ của chuỗi thứ hai thì chuỗi con dài nhất là bao nhiêu $\Rightarrow$ ý tưởng quy hoạch động là xây dựng mảng hai chiều $dp[i][j]$ lưu kết quả.

* Mối liên hệ:

  * Nếu $firstString[i] \neq secondString[j]$ thì dễ thấy $dp[i][j] = \max(dp[i - 1][j], dp[i][j - 1])$

  * Nếu  $firstString[i] = secondString[j]$ thì sẽ có các tình huống sau xảy ra

    * $dp[i][j] = dp[i - 1][j - 1] + 1$: ta chấp nhận ký tự đang xét ở hai chuỗi vào trong chuỗi chung có độ dài lớn nhất

    * $dp[i][j] = \max(dp[i - 1][j], dp[i][j - 1]) $: ta không chấp nhận ký tự đang xét vào chuỗi chung có độ dài lớn nhất.

    Do vậy, trong tình huống này thì $dp[i][j] = \max(dp[i - 1][j - 1] + 1, dp[i][j - 1], dp[i - 1][j]) $.

* Base-case: để cho thuận tiện tính toán ta xem các ký tự trong string được đánh số từ 1 thay vì 0. Có nghĩa là base-case là $dp[i][0] = 0 $ và $dp[0][j] = 0$.

## Học được gì từ bài này

* Cách xây dựng bảng phương án là một mảng hai chiều.

* Cách xử lý base-case

* Xử lý khi $firstString[i] \neq secondString[j]$: vì base-case đã 'phủ' một lớp ở phía dưới nên ta có thể tự tin gọi đến các giá trị ở lớp nhỏ hơn mà không sợ nó chưa được khởi tạo.

* Xử lý khi $firstString[i] = secondString[j]$: tránh phạm sai lầm vì nghĩ chỉ có tình huống $dp[i][j] = dp[i - 1][j - 1] + 1$ mà bỏ qua tình huống không chấp nhận ký tự vào trong chuỗi.

* So sánh với mối quan hệ truy hồi trong Toán học: mối quan hệ truy hồi trong Toán học thường biểu diễn dưới dạng 1 công thức nhất định và hay gặp nhất là dạng 1-D, hiếm khi gặp biểu diễn 2-D như thế này. Để thực hiện truy hồi trên mảng 1-D thì cần nạp vào một vài phần tử nhất định phụ thuộc vào công thức truy hồi. Tương tự thực hiện truy hồi trên mảng 2-D thì ta cần nạp một vài lớp giá trị nhất định. Trong bài này thì là lớp đầu tiên của hàng và lớp đầu tiên của cột.
