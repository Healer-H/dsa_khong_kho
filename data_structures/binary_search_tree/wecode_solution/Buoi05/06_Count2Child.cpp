
#include <iostream>
using namespace std;

struct TNODE
{
    int key;
    TNODE *pLeft;
    TNODE *pRight;
};
typedef TNODE *TREE;

/* ------------------------------------ */

void Insert(TREE &T, int item)
{
    if (T == NULL)
    {
        TNODE *newNode = new TNODE;
        newNode->key = item;
        newNode->pLeft = newNode->pRight = NULL;
        T = newNode;
        return;
    }
    if (T->key == item)
        return;
    if (item < T->key)
        Insert(T->pLeft, item);
    if (item > T->key)
        Insert(T->pRight, item);
}

void CreateTree(TREE& T)
{
    int item;
    while(cin >> item)
    {
        if(item == -1)
            return;
        Insert(T, item);
    }
}

void CountNode_Have2Child(TREE T, int &cnt)
{
    if (T == NULL)
    {
        cnt = 0;
        return;
    }
    if(T->pLeft != NULL && T->pRight != NULL)
    {
        cnt = 1;
    }
    int countLeft = 0;
    int countRight = 0;
    CountNode_Have2Child(T->pLeft, countLeft);
    CountNode_Have2Child(T->pRight, countRight);
    cnt += countLeft + countRight;
    
}

/* ------------------------------------ */

int main()
{
    int count = 0;
    TREE T;   // hay: TNODE* T;
    T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)
    CreateTree(T);
    CountNode_Have2Child(T, count);
    cout << count;
    return 0;
}
