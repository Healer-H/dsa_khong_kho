# Đa hình

## Khái niệm

*Đa hình* trong Lập trình Hướng đối tượng là hiện tượng các đối tượng thuộc các lớp khác nhau có khả năng hiểu cùng một thông điệp theo các cách khác nhau.

## Ví dụ

Lấy lại ví dụ về class `Dogs` và `Cats` ở phần trừu tượng. Rõ ràng các object của `Dogs` và `Cats` đều thực hiện phương thức `sound()`, tuy nhiên cách thức thực hiện là hoàn toàn khác nhau.

## Lợi ích

Tính đa hình mang lại nhiều lợi ích trong lập trình hướng đối tượng, bao gồm tái sử dụng mã, linh hoạt và mở rộng, đơn giản hóa mã nguồn, giúp mã nguồn trở nên linh hoạt, dễ bảo trì và dễ mở rộng.

## Cách thể hiện tính đóng gói trong mã nguồn

Tính đa hình được thể hiện thông qua việc sử dụng các khái niệm như lớp cha, lớp con, phương thức ảo (virtual), nạp chồng (overloading) và ghi đè phương thức (override).

- Nạp chồng (Overloading): Đây là khả năng cho phép một lớp có nhiều thuộc tính, phương thức cùng tên nhưng với các tham số khác nhau về loại cũng như về số lượng. Khi được gọi, dựa vào tham số truyền vào, phương thức tương ứng sẽ được thực hiện.

- Ghi đè (Overriding): là hai phương thức cùng tên, cùng tham số, cùng kiểu trả về nhưng thằng con viết lại và dùng theo cách của nó, và xuất hiện ở lớp cha và tiếp tục xuất hiện ở lớp con. Khi dùng override, lúc thực thi, nếu lớp con không có phương thức riêng, phương thức của lớp Cha sẽ được gọi, ngược lại nếu có, phương thức của lớp Con được gọi.
