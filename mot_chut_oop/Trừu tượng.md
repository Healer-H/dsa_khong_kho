# Trừu tượng

## Khái niệm

*Trừu tượng* trong Lập trình Hướng đối tượng là khả năng tạo ra các đối tượng, lớp, và giao diện trừu tượng để mô hình hóa các khái niệm, thuộc tính và hành vi của thế giới thực vào trong mã lập trình.

## Ví dụ

Giả sử chúng ta cần quản lý các loại thú cưng khác nhau như *Chó, Mèo, chuột Hamster, Hổ, Báo, Cáo, Gà,...*. Chúng ta muốn mô hình hóa các đối tượng này bằng cách sử dụng tính trừu tượng.

Đầu tiên chúng ta tạo một lớp đối tượng là *Pets* để đại diện cho đặc điểm và hành vi chung của các loại thú cưng. Lớp này chứa một vài thông tin như *tên, tuổi* và các phương thức như *tiếng kêu, nghịch đồ chơi*.

```cpp
class Pets {
protected:
    string name;
    int age;

public:
    Pets(string name, int age) {
        this->name = name;
        this->age = age;
    }

    virtual void sound() = 0;
    virtual void play() = 0;
};
```

Tiếp đó ta tạo lớp con kế thừa từ *Pets* để thể hiện cho các loại thú cưng cụ thể. Ví dụ như *Chó* và *Mèo*.

```cpp
class Dogs : public Pets {
public:
    Dogs(string name, int age) : Pets(name, age) {}

    void sound() override {
        cout << "Woof! Woof!" << endl;
    }

    void play() override {
        cout << "The dog is playing fetch." << endl;
    }
};
```

```cpp
class Cats : public Pets {
public:
    Cats(string name, int age) : Pets(name, age) {}

    void sound() override {
        cout << "Meow! Meow!" << endl;
    }

    void play() override {
        cout << "The cat is chasing a toy." << endl;
    }
};

```

Trong ví dụ này, lớp cơ sở là `Pets` đại diện cho các đặc điểm và hành vi chung của các con vật nuôi. Lớp cơ sở này có hai phương thức trừu tượng là `sound()` (âm thanh) và `play()` (chơi).

Lớp dẫn xuất `Dogs` và `Cats` kế thừa từ lớp cơ sở `Pets` và triển khai lại các phương thức trừu tượng tương ứng. Lớp `Dogs` có âm thanh là "Woof! Woof!" và chơi theo cách "The dog is playing fetch." Trong khi đó, lớp "Cats" có âm thanh là "Meow! Meow!" và chơi theo cách "The cat is chasing a toy."

## Lợi ích

Việc sử dụng trừu tượng trong lập trình hướng đối tượng mang lại nhiều lợi ích quan trọng, bao gồm

- Tính tái sử dụng
- Tính linh hoạt
- Tính mô-đun
- Tính dễ bảo trì
- Tính mở rộng
- Tính đồng nhất

### Cụ thể

*Tính tái sử dụng*: Trừu tượng cho phép tạo ra các lớp cơ sở và kế thừa từ chúng để tạo ra các lớp con. Điều này giúp tái sử dụng mã nguồn, vì các lớp con có thể sử dụng lại các thuộc tính và phương thức của lớp cơ sở mà không cần triển khai lại.

*Tính linh hoạt*: Sử dụng trừu tượng, bạn có thể tạo ra các giao diện và lớp trừu tượng để mô hình hóa khái niệm chung. Điều này cho phép bạn tách rời các khái niệm và quan hệ giữa các đối tượng, giúp mã nguồn trở nên linh hoạt và dễ dàng mở rộng.

*Tính mô-đun*: Trừu tượng giúp tạo ra các đối tượng độc lập và đóng gói, có thể tương tác với nhau thông qua giao diện. Điều này tạo ra các mô-đun riêng biệt, giúp giảm sự phụ thuộc giữa các thành phần và làm cho mã nguồn dễ quản lý hơn.

*Tính dễ bảo trì*: Trừu tượng giúp tách rời cài đặt cụ thể của một đối tượng khỏi phần còn lại của hệ thống. Khi cần thay đổi hoặc nâng cấp một phần của hệ thống, bạn chỉ cần quan tâm đến phần đó mà không cần thay đổi toàn bộ mã nguồn.

*Tính mở rộng*: Trừu tượng cho phép bạn dễ dàng mở rộng chức năng của một hệ thống bằng cách thêm các lớp con mới hoặc triển khai các giao diện mới. Điều này giúp hệ thống có thể đáp ứng được yêu cầu mới mà không làm ảnh hưởng đến các phần đã tồn tại.

*Tính đồng nhất*: Trừu tượng giúp tạo ra một cấu trúc chung cho mã nguồn, giúp cải thiện sự hiểu biết và sự hợp tác giữa các thành viên trong nhóm phát triển. Việc sử dụng các khái niệm trừu tượng giúp tạo ra một ngôn ngữ chung để diễn tả và thiết kế hệ thống.

## Cách thể hiện tính trừu tượng trong mã nguồn

Sử dụng `phương thức trừu tượng` và `lớp trừu trượng`

1. Phương thức trừu tượng: là phương thức với từ khóa `virtual` trước khai báo. Các phương thức trừu trượng không (có thể không) có thân hàm và các lớp dẫn xuất phải override lại các phương thức này.

    So sánh hàm ảo và thuần ảo

    Giống nhau:

    - Cả hàm ảo và hàm thuần ảo đều là các phương thức trừu tượng trong C++. Điều này có nghĩa là các phương thức này không có thân hàm và cần được triển khai lại (override) trong lớp dẫn xuất.

    - Cả hàm ảo và hàm thuần ảo đều được khai báo bằng cách sử dụng từ khóa "virtual".

    - Cả hàm ảo và hàm thuần ảo đều dùng để tạo ra một giao diện chung cho các lớp con và cho phép đa hình (polymorphism). Điều này có nghĩa là các đối tượng của lớp con có thể được xem như là đối tượng của lớp cơ sở và gọi các phương thức tương ứng.

    Khác nhau:

    - Hàm ảo có một thân hàm mặc định (có thể có thân hàm), trong khi hàm thuần ảo không có thân hàm. Hàm thuần ảo chỉ cần được khai báo và không có triển khai ở lớp cơ sở.

    - Lớp chứa hàm thuần ảo trở thành một lớp trừu tượng (abstract class), và các đối tượng của lớp này không thể được khởi tạo. Trong khi đó, lớp chứa hàm ảo có thể được khởi tạo và tạo đối tượng.

    - Một lớp con phải triển khai lại tất cả các hàm thuần ảo từ lớp cơ sở, trong khi một lớp con có thể triển khai hoặc không triển khai lại các hàm ảo từ lớp cơ sở.

2. Lớp trừu tượng: tổng quát hơn phương thức trừu tượng, ta có lớp trừu tượng. Lớp này không thể tạo thành đối tượng nhưng được dùng để các lớp khác kế thừa và dùng làm lớp cơ sở cho các lớp con.
