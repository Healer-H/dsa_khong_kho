# Đóng gói

## Khái niệm

*Đóng gói* trong Lập trình Hướng đối tượng là khả năng cho phép nhóm các thông tin và che dấu chúng - ẩn thông tin và hoạt động nội bộ của một đối tượng để chỉ cho phép truy cập thông qua các thành phần `public` được xác định trước, từ đó đảm bảo được sự toàn vẹn của đối tượng.

## Ví dụ

Giả sử chúng ta có một mảnh đất hình chữ nhật với chiều dài và chiều rộng. Để đảm bảo các thuộc tính này không bị thay đổi lung tung (nhỡ có ai vô trộm đất của tui thì sao...) thì ta vận dụng tính đóng gói.

```cpp
class Land
{
private:
    double length;
    double width;

public:
    // Getter methods
    double getLength()
    {
        return length;
    }

    double getWidth()
    {
        return width;
    }
    // Setter methods
    void setLength(double newLength)
    {
        if (/* conditions */)
        {
            length = newLength;
        }
        else
        {
            cout << "Invalid length!" << endl;
        }
    }
    void setWidth(double newWidth)
    {
        if (/* conditions */)
        {
            width = newWidth;
        }
        else
        {
            cout << "Invalid width!" << endl;
        }
    }
};
```

Trong ví dụ trên, để có thể tương tác với chiều dài và chiều rộng của mảnh đất, ta chỉ có thể thông qua các phương thức `setter()` và `getter()`. Đặc biệt để có thể thay đổi được chiều dài và chiều rộng mảnh đất thì cần phải thỏa mãn một số `conditions` nhất định.

## Lợi ích

Tính đóng gói giúp kiểm soát quyền truy cập, bảo vệ dữ liệu và cung cấp một giao diện rõ ràng để tương tác với các đối tượng.

Cụ thể

- Kiểm soát quyền truy cập: Tính đóng gói giúp kiểm soát quyền truy cập vào các thành phần của đối tượng. Chỉ những phương thức công khai được khai báo trong lớp có thể được gọi từ bên ngoài, trong khi các thành phần private và protected chỉ có thể truy cập và sử dụng bên trong lớp. Điều này giúp ngăn chặn việc truy cập trực tiếp vào các thành phần nội bộ và đảm bảo tính toàn vẹn của đối tượng.

- Bảo vệ dữ liệu: Tính đóng gói cho phép ẩn thông tin và chi tiết về cách dữ liệu được lưu trữ và xử lý bên trong một đối tượng. Chỉ có các phương thức công khai được cung cấp để truy cập và thao tác dữ liệu. Điều này bảo vệ dữ liệu khỏi việc truy cập trái phép hoặc chỉnh sửa không đúng cách từ bên ngoài.

- Tính rõ ràng và dễ bảo trì: Tính đóng gói giúp tạo ra một giao diện rõ ràng và đơn giản để tương tác với đối tượng. Người sử dụng của đối tượng chỉ cần quan tâm đến các phương thức công khai và không cần phải biết chi tiết về cách dữ liệu được lưu trữ và xử lý bên trong đối tượng. Điều này giúp làm giảm sự phức tạp và giữ cho mã nguồn dễ hiểu, dễ bảo trì và dễ mở rộng.

## Cách thể hiện tính đóng gói trong mã nguồn

Trong mã nguồn, tính đóng gói trong lập trình hướng đối tượng có thể được thể hiện qua việc sử dụng các khai báo `private`, `protected` và `public` để xác định phạm vi truy cập của các thành phần của một lớp.
