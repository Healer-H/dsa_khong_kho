# Kế thừa

## Khái niệm

*Kế thừa* trong Lập trình Hướng đối tượng là khả năng cho phép một lớp con kế thừa các thuộc tính và phương thức của một lớp cha. Lớp con có thể tái sử dụng code từ lớp cha mà không cần phải viết lại những phần mà lớp cha đã xây dựng.

## Ví dụ

Giả sử chúng ta cần quản lý các hình đa giác (tam giác, tứ giác, hình chữ nhật, ...), ta sẽ cho các lớp `Triangle`, `Rectangle`, ... kế thừa từ lớp `Polygon`.

```cpp
class Polygon
{
protected:
    std::vector<int> sides;

public:
    void setSides(const std::vector<int> &s)
    {
        sides = s;
    }
};
```

Các lớp `Triangle`, `Rectangle` sẽ kế thừa từ `Polygon`

```cpp
class Triangle : public Polygon
{
public:
    Triangle(int a, int b, int c)
    {
        sides = {a, b, c};
    }
};
```

```cpp
class Rectangle : public Polygon
{
public:
    Rectangle(int a, int b, int c, int d)
    {
        sides = {a, b, c, d};
    }
};
```

## Lợi ích

Tính kế thừa là một tính chất vô cùng quan trọng của Lập trình Hướng đối tượng với một số lợi ích như `khả năng tái sử dụng mã`, `khả năng mở rộng`, `khả năng quản lý và tổ chức mã`.

Cụ thể

- Tái sử dụng mã: Kế thừa cho phép lớp con kế thừa tất cả các thành phần (thuộc tính và phương thức) của lớp cha. Điều này giúp tái sử dụng mã nguồn đã được triển khai trong lớp cha mà không cần viết lại. Khi có một số lượng lớn các lớp con có các tính chất và hành vi tương tự, tính kế thừa giúp giảm thiểu sự lặp lại mã nguồn.

- Mở rộng: Kế thừa cho phép mở rộng và mở rộng tính năng của lớp cha trong lớp con. Lớp con có thể thừa hưởng các thành phần của lớp cha và cũng có thể thêm các thuộc tính và phương thức riêng của nó hoặc ghi đè các phương thức của lớp cha để thay đổi hoặc mở rộng hành vi.

- Quản lý và tổ chức mã: Kế thừa giúp tổ chức mã theo cấu trúc phân cấp. Các lớp con có thể được nhóm lại và được quản lý dễ dàng trong một cấu trúc phân cấp, làm cho mã trở nên rõ ràng và dễ hiểu hơn. Điều này cũng giúp quản lý và bảo trì mã dễ dàng hơn khi cần thay đổi hoặc mở rộng tính năng.

## Cách thể hiện tính Kế thừa trong mã nguồn

Trong C++, tính kế thừa được thể hiện bằng toán tủ `:` kèm với các từ khóa chỉ phạm vi như `public`, `protected`, `privated`.

```cpp
class Child : public Parent
{
    // ...
};
```
