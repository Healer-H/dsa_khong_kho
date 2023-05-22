
#include <iostream>
using namespace std;

struct TNODE
{
    int key;
    TNODE *pLeft;
    TNODE *pRight;
};
typedef TNODE *TREE;

void CreateEmptyTree(TREE &T)
{
    T = NULL;
}
TNODE *CreateTNode(int x)
{
    TNODE *p = new TNODE; // cấp phát vùng nhớ động
    p->key = x;           // gán trường dữ liệu của node = x
    p->pLeft = NULL;
    p->pRight = NULL;
    return p;
}
int Insert(TREE &T, TNODE *p)
{
    if (T)
    {
        if (T->key == p->key)
            return 0;
        if (T->key > p->key)
            return Insert(T->pLeft, p);
        return Insert(T->pRight, p);
    }
    T = p;
    return 1;
}
/* ------------------------------- ----------------------*/

void CreateTree(TREE &T)
{
    int item;
    while (cin >> item)
    {
        if (item == -1)
            return;
        Insert(T, CreateTNode(item));
    }
}

void FindSiblings(TREE T, int item)
{
    if(T == NULL)
    {
        cout << "Empty Tree. \n";
        return;
    }
    // tim thay/khong tim thay item
    // tim thay item: item khong co siblings / co siblings
    //  khong co siblings: item la root / parent of item has one child
    // ==> key: tim ra parent item

    // item la root
    if (T->key == item)
    {
        cout << item << " is Root. \n";
        return;
    }

    // item khong phai la root ==> item co parent, tim parent cua item
    TNODE *it = T, *parent;
    while (true)
    {
        if (it->key == item)
        {
            break;
        }
        parent = it;
        if (it->key > item)
        {
            if (it->pLeft == NULL)
            {
                it = NULL;
                break;
            }
            it = it->pLeft;
        }
        else
        {
            if (it->pRight == NULL)
            {
                it = NULL;
                break;
            }
            it = it->pRight;
        }
    }

    //not found
    if(it == NULL)
    {
        cout << "Not found " << item << ".\n";
        return;
    }

    // parent has one child
    if(parent->pLeft == NULL || parent->pRight == NULL)
        cout << item << " has no siblings. \n";
    else
        cout << parent->pLeft->key << " and " << parent->pRight->key << " are siblings. \n";
    
}

/* ------------------------------- ----------------------*/

int main()
{
    TREE T;   // hay: TNODE* T;
    T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)
    CreateTree(T);

    int x;
    cin >> x;

    FindSiblings(T, x);

    return 0;
}
