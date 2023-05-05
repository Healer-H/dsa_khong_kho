# Một vài khái niệm

## 1. Git là gì

Git là một dạng Version Control / Source Control. Nó có các công dụng của một Version Control như

* Lưu trữ các thay đổi của Source Code

* Hỗ trợ nhiều người làm việc cùng lúc

* Xem lịch sử chỉnh sửa code (xem được người nào đã chỉnh sửa)

* Nếu hôm nay code sai ra toàn bugs thì có thể quay đầu lại "code của ngày hôm qua"

## 2. Khái niệm quan trọng

* Khái niệm về Repository (gọi tắt là repo, đọc là rê bô, rì bô, ...): có thể xem repo như một cái project, nó chứa toàn bộ code và còn chứa cả các commit. Có hai loại repo:

  * Local Repo: là repo nằm trên máy của mình
  * Remote Repo: là repo nằm trên máy chủ, nằm ở một chỗ nào đó mà chúng ta có thể lấy code về, đẩy code lên,...

* Khái niệm về Commit: mỗi lần mà chúng ta thay đổi code và nói với máy tính rằng "anh bạn à, tôi mới sửa chỗ này, anh nhớ giúp tôi nhé" thì sẽ tính là một commit. Commit sẽ được repo lưu lại và nhờ vậy mà chúng ta có thể quay lại code của những ngày chưa có bug nếu ngày hôm nay gặp bug mà fix mãi không được.

* Github là gì: Github là một dịch vụ lưu trữ Git repo, bạn có thể lưu repo của mình lên Github sau đó share cho bạn bè cùng xem. Lúc này cái repo trên Github đóng vai trò như một cái Remote repo, còn cái trên máy bạn giống như một cái Local repo. Quá trình làm việc thường sẽ là: đồng bộ code từ remote repo về local repo, gõ gõ gõ, đẩy code ngược lại lên remote repo.

Việc đồng bộ từ Remote về Local là bởi vì thường chúng ta làm nhóm nhiều người thì không chỉ có mình bạn sửa, bạn của bạn cũng sửa và để tránh tình huống xung đột code với nhau thì chúng ta phải đồng bộ code từ Remote về Local.

## 3. Nguyên lý hoạt động của Git

![Git Workflow](https://drive.google.com/file/d/1gXNpde7EPWNxBuo9De_hHxN4OJc824CH/view?usp=sharing)

Ngoài vùng Local repo và Remote repo thì chúng ta còn có một vùng nữa là vùng Staging Area. Khi mà chúng ta sửa code, chúng ta đang sửa trên code thôi. Sau đó chúng ta cần phải đẩy code lên Staging Area, rồi đến Local repo, cuối cùng là Remote repo. Để đẩy code lên Staging Area, ta dùng câu lệnh `git add`. Lúc này code đang nằm ở Staging Area và đã sẵn sàng để được đẩy lên Local repo, chúng ta có thể kiểm tra file nào đã sẵn sàng được đẩy lên bằng câu lệnh `git status`. Muốn đẩy code từ Staging Area lên Local repo ta chỉ cần gõ lệnh `git commit`. Thông thường câu lệnh này kèm theo một tham số `-m` với ý nghĩa là 'message' giống như kiểu để lại cái comment để cho người khác biết cái commit này có tác dụng là gì. Cuối cùng là tui sẽ đẩy code lên Remote repo bằng câu lệnh `git push`. Ví dụ tui fix được cái bug của hàm tính tổng, quá trình đẩy code mới lên từ máy của tui diễn ra như sau.

```git
git add sum.cpp
git commit -m "fix duoc bug roi hahaha"
git push
```

Đó sương sương cái quy trình vận hành là nó như vậy, "cậu ơi hãy thêm cái file này vào staging area đi, cậu ơi hãy đẩy hết mấy cái file trong staging area lên local repo đi *nhớ kèm theo cái message này nha, cậu ơi hãy đẩy code từ local lên remote đi".
Các câu lệnh trên đều được gõ trong Terminal nha nên bạn có thể sử dụng Terminal sẵn có của Win (chính là cái cmd của máy đó) hoặc là dùng cái Terminal trong Visual Studio Code giống tui nè.

À còn một số cái tiểu tiết kiểu: tui có một cái Repo trong máy, làm sao tui đưa cái repo đó lên mạng. Thì đầu tiên là vào Github tạo một cái repo trên đó. Sau đó copy link dẫn tới repo đó, rồi gõ lệnh `git remote add origin <kèm cái link>`. Câu lệnh này kiểu là tui nói với cái máy của tui là "ê giờ tui cho bạn cái link dẫn vào remote repo nè, bạn lưu lại đi, sau này mỗi lần tui push code thì bạn cứ push lên cái link này cho tui."

Chiều ngược lại cũng tương tự, bạn có thể lấy một cái repo trên mạng về bằng cách nói với máy tính là "ê giờ tui có cái remote repo này nè, bạn lên đó lấy về giúp tui đi" thông qua câu lệnh `git clone <kèm cái link>`

## 4. Một số lệnh Git cơ bản mà tui biết sài sơ sơ

Trước khi đến với mấy cái lệnh thì bạn phải cài Git về máy trước đã. Vào trình duyệt và download git, sau đó cài như một phần mềm bình thường.

Khi làm việc với Git thì thường mình sẽ làm việc trên Terminal (có thể bạn biết với cái tên khác là Console hay Command Line). Bằng cách gõ các câu lệnh tương ứng với chức năng mà code của bạn sẽ được lưu/cập nhật/xóa/... nhìn chung khá là ảo dịu.

* Nhóm lệnh làm việc với Remote repo

  * `git init` - khởi tạo một cái repo bên trong folder hiện tại, thao tác này sẽ tạo ra một cái folder ẩn .git, không cần hiểu cái folder này lắm đâu. Sau khi gõ lệnh này thì chúng ta đã có một cái gọi là repo rồi :>

  * git clone *<'link của remote repo>* - (ví dụ: `git clone https://github.com/Healer-H/dsa_khong_kho.git*` ) nhận được lệnh này thì máy tính sẽ tự chui vào cái link được bạn cung cấp, nhặt cái repo trên đó về ngay tại folder mà bạn đang đứng.

  * `git pull` - lệnh này đồng bộ dữ liệu từ remote repo xuống local repo

* Nhóm lệnh làm việc với Local repo

  * git add *<tên file muốn add>* - (ví dụ: `git add add1.cpp add2.cpp add3.txt`) lệnh này đẩy các file được gọi đến vào Staging Area. Có thể đẩy hết tất cả các file bằng lệnh `git add .` để đỡ mất công gọi tên từng file.

  * `git commit -m "message gi do"` - đưa code từ Staging Area qua bên Local repo

  * `git push` - đẩy code từ Local lên Remote

Tui mới biết nhiêu đó và tui làm được cái Remote repo mà bạn đang xem nè, thực ra nó là một kỹ năng khá hay và tui nghĩ nó không khó lắm nên chúng ta hoàn toàn có thể tự học nha. Phía dưới tui có để một vài video mà tui xem để tự học, mong là nó có ích với bạn he.

Ngoài ra thì làm việc với Git chúng ta chủ yếu gõ lệnh trên command line, nên cũng sẽ không thừa nếu chúng ta hiểu một chút về Command Line là cái gì đâu này. Mọi người có thể tự tìm hiểu phần này nhen.

## Tham khảo thêm tại

1. [Từ gà tới pro Git và Github trong 20 phút - Tự học Git siêu tốc - toidicođeao](https://www.youtube.com/watch?v=1JuYQgpbrW0)

2. [Git Tutorial for Beginners: Learn Git in 1 Hour](https://www.youtube.com/watch?v=8JJ101D3knE)

3. [Git Tutorial - w3school](https://www.w3schools.com/git/default.asp)
