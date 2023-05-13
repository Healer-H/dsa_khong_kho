# Binary Search Tree (BST)

## Định nghĩa

> Là cây nhị phân thỏa mãn tại mỗi node thì các node con bên trái nhỏ hơn node đang xét, các node con bên phải lớn hơn node đang xét.

Chú ý: với cây gồm $N$ node, chiều cao $h$ của cây trong tình huống tốt nhất là $log_2N$ và xấu nhất là $N-1$. Do vậy mà thao tác tìm kiếm trong tình huống xấu nhất sẽ có độ phức tạp là $O(N)$

Cấu trúc của một node

```cpp
struct TNODE
{
    int key;
    TNODE* pLeft;
    TNODE* pRight;
};
```

Cấu trúc của một cây

```cpp
typedef TNODE* TREE;
```

Thao tác trên BST

1. Tạo cây rỗng
2. Tạo node với $value$ cho trước
3. Thêm node vào cây
4. Duyệt cây
5. Tìm kiếm
6. Lấy Min, Max
7. Xóa node

Code tham khảo

* Tạo cây rỗng

```cpp
void CreateEmptyTree(TREE &T)
{
    T = NULL;
}
```

* Tạo node với $value$ cho trước *(nhớ return nếu không sẽ bị RTE)*

```cpp
TNODE *CreateTNode(int value)
{
    TNODE *newNode = new TNODE;
    newNode->key = value;
    newNode->pLeft = newNode->pRight = NULL;
    return newNode;
}
```

* Thêm node vào cây: input là một $value$, chúng ta cần tìm vị trí thích hợp để thêm node chứa giá trị $value$.

*Code sử dụng đệ quy*

```cpp
void Insert(TREE &T, int value)

{
    TNODE *addNode = CreateTNode(value);
    if (T == NULL)
    {
        T = addNode;
        return;
    }
    //trường hợp BST rỗng thì chỉ việc cập nhật root của BST và return

    if (T->key == addNode->key) 
        return; 
    //BST không lưu các giá trị trùng nhau nên néu addNode->key đã xuất hiện trước đó thì không cần làm gì nữa

    if (addNode->key < T->key) 
        Insert(T->pLeft, value);
    else
        Insert(T->pRight, value);
    //nếu giá trị thêm vào nhỏ hơn root thì ta add về phía bên trái, ngược lại ta add về phía bên phải
}
```

*Code khử đệ quy*

```cpp
void Insert(TREE &T, int value)
{
    TNODE *addNode = CreateTNode(value);
    if (T == NULL)
    {
        T = addNode;
        return;
    }

    TNODE *it = T; 
    //note: "it" stands for iterator, có thể hiểu "it" như một biến con trỏ dùng để duyệt cây.

    while (true)
    {
        if (addNode->key == it->key)
            return;
        // nếu gặp một giá trị đã có trong BST, ta không cần phải làm gì nữa --> return

        //Nhận xét 1: khi thêm một node, node được thêm sẽ luôn là
        //node lá và đi xuống phía dưới cùng nên thành thử 
        //để có thể quyết định thêm/không thêm thì ta cần kiểm tra 
        //node hiện tại đang xét đã ở đáy hay chưa.
        // Nếu rồi, ta thêm vào sau node đang xét
        // Nếu chưa, ta tiếp tục di chuyển xuống phía dưới

        //Nhận xét 2: ta sẽ luôn tìm được một vị trí thích hợp với 
        //vọi giá trị cần thêm vào, khi tìm được thì ta thực hiện 
        //việc thêm vào và return, do đó ta dùng while(true)
        if (addNode->key < it->key)
        {
            if (it->pLeft == NULL)
            {
                it->pLeft = addNode;
                return;
            }
            it = it->pLeft;
        }
        else
        {
            if (it->pRight == NULL)
            {
                it->pRight = addNode;
                return;
            }
            it = it->pRight;
        }
    }
}
```

Mặc dù cách viết không đệ quy dài hơn, nó giúp chúng ta ngẫm nghĩ tốt hơn và Performance của cách này cũng tốt hơn nên khuyến khích dùng cách này hơn là đệ quy.

Thao tác tìm kiếm thực hiện tương tự như thao tác thêm, lưu ý `return value` có thể kiểu `bool` thể hiện việc có giá trị cần tìm trong BST hay không hoặc kiểu `TNODE*` để phục vụ việc tính toán sau này.

* Thao tác duyệt
  * Duyệt theo chiều ngang (Breadth First / Level Order Traversal)
  * Duyệt theo chiều sâu (Depth First Travelsal)
    * Preorder: Node - Left - Right (NLR)
    * Inorder: Left - Node - Right (LNR)
    * Postorder: Left - Right - Node (LRN)

Có thể thấy có nhiều cách duyệt BST khác nhau, bản thân mỗi cách lại có thể có nhiều cách cài đặt khác nhau. Điểm chung giữa cách cách này là đều có độ phức tạp thời gian là $O(N)$ vì phải đi qua hết tất cả các node. Điểm khác biệt giữa các cách cài đặt có thể là độ phức tạp không gian, có cách chỉ tốn chi phí $O(1)$ trong khi có cách tốn chi phí $O(N)$. Tất nhiên cách tốn chi phí cao hơn sẽ dễ cài đặt hơn và trong đa phần các tình huống ta không cần quá quan tâm tới giới hạn bộ nhớ nên mình sẽ chọn cái dễ mà làm. Tuy nhiên cũng nên học hỏi ý tưởng đằng sau cách cài đặt tối ưu để có nhiều phương án lựa chọn khi gặp phải vấn đề.

*Duyệt theo chiều ngang - Level Order Tranversal*

Ý tưởng: sử dụng CTDL `queue` để lưu trữ các node, mỗi khi lấy ra một node thì thêm vào `queue` con của phần tử vừa lấy ra. Vì `queue` là CTDL được tổ chức dưới dạng `First In First Out` nên khi thêm vào các phần tử theo thứ tự từ trái sang phải thì khi lấy ra cũng sẽ lấy được theo chiều từ trái sang phải. Do vậy mà ta có thể đi qua hết tất cả các node theo thứ tự *Level Order Tranversal*.

Ví dụ cây BST sau:

```md
                9
              /   \
            6      16
          /  \    /  \
         2    7  12   25
       /   \    /    /
      1     4  11   20
```

* Thêm node root vào `queue` - [9]
* Lấy phần tử `front()` của `queue` ra (lấy 9 ra, cho vào output) và đẩy con của 9 vào (đẩy 6 và 16 vào) - [6, 16]
* Lấy phần tử `front()` của `queue` ra (lấy 6 ra, cho vào output) và đẩy con của 6 vào (đẩy 2 và 7 vào) - [16, 2, 7]
* Lấy phần tử `front()` của `queue` ra (lấy 16 ra, cho vào output) và đẩy con của 16 vào (đẩy 12 và 25 vào) - [2, 7, 12, 25]
* ...
* Cứ làm như vậy cho tới khi nào `queue` rỗng thì ta sẽ được output là [9, 6, 16, 2, 7, 12, 15, 1, 4, 11, 20]

Code tham khảo:

```cpp
void PrintTreeBFS(TREE T)
{
    if (T == NULL)
    {
        cout << "Empty Tree. \n";
        return;
    }

    queue <TNODE*> bfs;
    //lưu ý: queue lưu các node của BST chứ không phải giá trị vì cần phải truy cập tới các node con

    bfs.push(T);

    while (!bfs.empty())
    {
            TNODE *it = bfs.front();
            bfs.pop();
            cout << it->key << " ";

            if(it->pLeft != NULL)
                bfs.push(it->pLeft);
            if(it->pRight != NULL)
                bfs.push(it->pRight);
    }
}
```

*Duyệt theo chiều sâu*

Để ý rằng trong các cách duyệt theo chiều sâu, Inorder sẽ cho ta output là các phần tử đã được sắp xếp. Với thứ tự $LNR$ thì là sắp xếp tăng dần và với thứ tự $RNL$ là sắp xếp giảm dần.

Ta có thể code các bài duyệt theo chiều sâu sử dụng đệ quy, code thu được sẽ rất ngắn gọn và trực quan.

Code tham khảo Inorder Traversal

```cpp
void PrintInorder(TREE T)
{
    if(T == NULL)
        return;
    //base-case: điều kiện dừng

    PrintInorder(T->pLeft);
    //đệ quy tới con bên trái

    cout << T->key << " ";
    //in ra giá trị tại node 

    PrintInorder(T->pRight);
    //đệ quy tới con bên phải
}
```

Vì bản chất của `Recursive` là `Call Stack` nên ta hoàn toàn có thể dùng CTDL `stack` để khử đệ quy cho bài này.

Các cách duyệt khác hoàn toàn tương tự, chỉ việc thay đổi thứ tự gọi hàm đệ quy sao cho phù hợp thì ta sẽ thu được kết quả mong muốn.

Tham khảo thêm:

* [Tree Traversals (Inorder, Preorder and Postorder) - Geeksforgeeks](https://www.geeksforgeeks.org/tree-traversals-inorder-preorder-and-postorder/)
* [Inorder Tree Traversal without Recursion - Geeksforgeeks](https://www.geeksforgeeks.org/inorder-tree-traversal-without-recursion/)
