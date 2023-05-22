
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

/* ------------------------------------------------------ */

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

void FindParent(TREE T, int item)
{
    if (T == NULL)
    {
        cout << "Empty Tree. \n";
        return;
    }
    if (T->key == item)
    {
        cout << item << " has no parent. \n";
        return;
    }
    TNODE *parent = T;
    TNODE *it = T;
    while (it != NULL)
    {
        if (it->key == item)
        {
            break;
        }
        if (item < it->key)
        {
            parent = it;
            if (it->pLeft == NULL)
            {
                it = NULL;
                break;
            }
            it = it->pLeft;
        }
        if (item > it->key)
        {
            parent = it;
            if (it->pRight == NULL)
            {
                it = NULL;
                break;
            }
            it = it->pRight;
        }
    }
    if (it == NULL)
    {
        cout << "Not found " << item << ". \n";
        return;
    }
    cout << parent->key << " is parent of " << item << ". \n";
}

/* ------------------------------------------------------ */

int main()
{
    TREE T;   // hay: TNODE* T;
    T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)
    CreateTree(T);

    int x;
    cin >> x;

    FindParent(T, x);

    return 0;
}
