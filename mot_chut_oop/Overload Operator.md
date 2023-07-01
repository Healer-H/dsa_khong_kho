# Overload Operator

Overload operator là nội dung có khả năng cao sẽ xuất hiện trong đề thi OOP năm nay. Thông thường để overload operator người ta sẽ sử dụng hàm bạn `friend()` kết hợp với ép kiểu bằng `constructor()` để code có tính tổng quát.

Một số operator có cách overload hơi đặc biệt như `toán tử cộng/trừ trước [++, --]`, `toán tử cộng/trừ sau [++, --]`, `toán tử dịch bit (dùng cho nhập xuất) [>>, <<]`

Một số operator như `[ ], ( ), =, ->` bắt buộc phải là phương thức của lớp để toán hạng thứ nhất là một đối tượng của lớp.

Các operator `+=, -=, *=, ...` sẽ không được tự động định nghĩa kể cả khi chúng ta đã định nghĩa các operator `+, -, *,...`

Khi định nghĩa phép toán bằng hàm thành phần, số tham số ít hơn số ngôi một vì đã có một tham số ngầm định là đối tượng gọi phép toán (toán hạng thứ nhất). Phép toán 2 ngôi cần 1 tham số và phép toán 1 ngôi không có tham số.

```cpp
a - b; // a.operator-(b);
++a; // a.operator++();
```

Khi định nghĩa phép toán bằng hàm toàn cục, số tham số bằng số ngôi, Phép toán 2 ngôi cần 2 tham số và phép toán một ngôi cần một tham số

```cpp
a - b; // operator-(a, b);
-a; // operator-(a);
```

## Overload operator cho PhanSo

```cpp
// declared
class PhanSo
{
private:
    int tuSo;
    int mauSo;
public: 
    // other method()

    // binary operator +
    friend PhanSo operator+(PhanSo, PhanSo); 

    // unary operator -
    friend PhanSo operator-(PhanSo);

    // overload operator =
    void operator=(PhanSo);
}
```

```cpp
// defined 
PhanSo operator+(PhanSo a, PhanSo b)
{
    return PhanSo(b.tuSo * a.mauSo + a.tuSo * b.mauSo, b.mauSo * a.mauSo);
}

PhanSo operator-(PhanSo a)
{
    return PhanSo(-a.tuSo, a.mauSo);
}

void PhanSo::operator=(PhanSo other)
{
    this->tuSo = other.tuSo;
    this->mauSo = other.mauSo;
}

```

Có thể làm cho các phương thức trở nên chặt chẽ hơn ('chặt chẽ hơn' có thể là chính xác hơn, ít tốn tài nguyên hơn, bảo vệ dữ liệu tốt hơn,...) ta có thể truyền vào các từ khóa `const` hay toán tử `&`.

Ví dụ khi overload toán tử `=` ta có thể viết thành

```cpp
PhanSo& PhanSo::operator=(const PhanSo& other)
{
    if(this != &other)
    {
        this->tuSo = other.tuSo;
        this->mauSo = other.mauSo;
    }
    return *this;
}
```

Giải thích:

- Kiểu trả về `PhanSo&` sẽ tạo ra nhiều điều khác biệt so với kiểu `void` và `PhanSo`, cụ thể là trong phép gán chuỗi, giả sử ta có đoạn khai báo sau:

    ```cpp
    PhanSo a(1, 2), b(3, 5), c(10, 7);
    ```

    Nếu việc overload toán tử `=` có kiểu trả về là `void`, ta sẽ không thể thực hiện phép gán chuỗi `a = b = c;` vì `a` có kiểu là `PhanSo` còn `b = c` có kiểu là `void`.

    *Câu hỏi đặt ra: nếu return về `PhanSo` thay vì `PhanSo&` thì điều gì sẽ xảy ra?*

    Trả lời: khi này việc thực hiện phép gán chuỗi `a = b = c` là hợp lệ về mặt cú pháp (vì `b = c` bây giờ cũng có kiểu `PhanSo`). Tuy nhiên về mặt logic thì không.

    Cụ thể, output là như nhau, tức là sau cùng ta vẫn có `a = c` và `b = c`. Tuy nhiên khi kiểu trả về là `PhanSo` thì phép gán `b = c` sẽ trả về một `PhanSo` gọi là `ps` có giá trị là `c` và lưu phân số này vào một vùng nhớ mới. Sau đó thực hiện gán `a = ps`. Còn khi kiểu trả về là `PhanSo&` thì phép gán `b = c` sẽ trả về tham chiếu tới phần tử `b`, tức là giá trị của `b` là `c` và địa chỉ của phần tử trả về là `b`, tức là không tạo thêm vùng nhớ mới. Khi ta thực hiện gán `a = b` tức là ta đang gán giá trị của chính `b` cho `a`.

    Bản thân câu lệnh `a = b = c` giống như một lời gọi hàm `a.operator=(b.operator=(c))`, tức là chúng ta đã chỉ rõ thứ tự thực hiện phép toán là phải gán `b = c` trước rồi mới `a = (b = c)`. Do đó mà sự khác biệt không thể hiện rõ, để nhìn thấy sự khác biệt rõ ràng hơn, có thể thử gọi lệnh `a.operator=(b).operator=(c)`. Lúc này, nếu return value không có `&` thì kết quả sẽ tương đương với `a = b; (a = b) = c` và do đó kết quả cuối cùng sẽ là `a = b` còn `c` vẫn giữ nguyên.
    Nếu return value có `&` thì kết quả sẽ tương đương với `a = b; a = c` và do đó `a = c` còn `b` và `c` thì vẫn giữ nguyên.

- `const PhanSo& other` - khi truyền vào hàm một tham trị thì hàm sẽ sao chép tham trị ra một vùng nhớ mới và tính toán (đó là lý do mà sau khi ra khỏi hàm thì tham trị không bị thay đổi), khi truyền tham biến thì hàm sẽ làm việc trực tiếp trên vùng nhớ của biến truyền vào (đó là lý do mà truyền `&` làm cho giá trị biến bị thay đổi). Còn khi truyền vào một hằng tham biến `const <data_type>&` thì giá trị của biến không bị thay đổi, đồng thời chương trình sẽ lấy giá trị trực tiếp trên vùng nhớ mà không cần phải sao chép, giúp tối ưu tài nguyên.

Tóm lại, viết `PhanSo&` là chuẩn nhất.

## Overload toán tử nhập xuất

Toán tử nhập xuất `>>, <<` là toán tử hai ngôi với ngôi thứ nhất thuộc lớp `istream (ostream)` do vậy cần triển khai hàm toàn cục kết hợp với từ khóa `friend`.

Sử dụng lại ví dụ class `PhanSo` bên trên

```cpp
class PhanSo
{
private:
    int tuSo;
    int mauSo;

public:
    // other method
    friend ostream &operator<<(ostream &out, const PhanSo &c);
    friend istream &operator>>(istream &in, PhanSo &c);
}
```

```cpp
istream & operator >> (istream &in, PhanSo & c)
{
    in >> c.tuSo >> c.mauSo;
    return in;
}

ostream & operator<<(ostream& out, const PhanSo& c)
{
    out << c.tuSo << " / " << c.mauSo;
    return out;
}
```

## Overload toán tử ++ prefix và postfix

```cpp
class PhanSo
{
private:
    int tuSo;
    int mauSo;

public:
    // other method
    PhanSo& operator++();   //overload prefix operator
    PhanSo operator++(int); // overload postfix operator
}
```

```cpp
PhanSo& PhanSo::operator++()
{
    tuSo = tuSo + mauSo;
    return *this;
}
```

```cpp
PhanSo PhanSo::operator++(int)
{
    PhanSo tmp = *this;
    tuSo = tuSo + mauSo;
    return tmp;
}
```

Để phân biệt toán tử prefix và postfix trong cách đặt hàm ta truyền vào một tham số kiểu `int` vào khai báo hàm postfix. Phần còn lại chỉ là triển khai hàm như thế nào cho hợp lý. *Thử thách cho mọi người là hãy tự lý giải tại sao overload prefix operator lại có return value kiểu tham chiếu mà postfix operator thì lại không có?*
