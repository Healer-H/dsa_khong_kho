<https://docs.google.com/document/d/1fldYvoXSJziFmgqMzC2rONckkTWkiitd/edit>

<https://docs.google.com/document/d/1SmhUTaQ9JzEFxA8TywEgiRKQ19WWIZPW/edit>

# Binary Search Tree

## Nội dung ra thi thường tập trung vào

- Thêm, xóa node vào BST (vẽ cây BST sau mỗi bước hoặc duyệt NLR)
- Duyệt BST theo các kiểu
  - Breath First (Level Other Traversal)
  - Deapth First (NLR, LNR, LRN)
- Những hàm đơn giản và ngắn gọn như: hàm đếm số lượng node, hàm tính tổng các node trong BST, hàm tính chiều cao (height) của BST...

*Chú ý:* học thuộc bảng chữ cái tiêng Anh, tiếng Việt

# B-Tree

## Các khái niệm

- Mỗi node $X$ sẽ có các trường thông tin
  - $X.n$ số lượng keys đang có trên node
  - $X.key_1 \leq X.key_2 \leq ... \leq X.key_n$
- *Internal Node* là node khác node gốc và node lá
- Số con của một node (trừ lá) bằng số $key + 1$
- Các node lá phải ở cùng mức (cùng độ sâu $h$)
- Số con và $key$ của một cây có ràng buộc phụ thuộc vào bậc của cây B-Tree

## Các ràng buộc của B-Tree

Với cây $B-Tree$ bậc $n$, ta có

- Node root thì đặc biệt, có thể chỉ có một $key$ cũng được (một $key$ thì sẽ có hai con do tính chất cây), tối đa có thể có $n$ con: $$2 \leq numNode \leq m$$
- Node không phải root mà có con, số con không được vượt quá số bậc của cây $B-Tree$, cũng không được ít hơn phần nguyên lấy chặn trên (ví dụ [4.6] = 5)  $$\left[\frac{m}{2}\right] \leq numNode \leq m$$

- Số $key$ giới hạn thì giảm 1 ở mỗi biên so với số node giới hạn, cụ thể:
  - Node root    $$1 \leq numKey \leq m - 1$$
  - Node khác root $$\left[\frac{m}{2}\right] - 1\leq numKey \leq m - 1$$

## Insertion

## Deletion
