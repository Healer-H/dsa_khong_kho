
#include <iostream>
using namespace std;

struct TNODE
{
    int key;
    TNODE *pLeft;
    TNODE *pRight;
};
typedef TNODE *TREE;

/* -------------------------------------- */
TNODE *CreateTNode(int value)
{
    TNODE *newNode = new TNODE;
    newNode->key = value;
    newNode->pLeft = newNode->pRight = NULL;
    return newNode;
}
void Insert(TREE &T, int value)
{
    TNODE *addNode = CreateTNode(value);
    if (T == NULL)
    {
        T = addNode;
        return;
    }

    if (T->key == addNode->key)
        return;

    if (T->key < addNode->key)
        Insert(T->pLeft, value);
    else
        Insert(T->pRight, value);
}

void CreateTree(TREE &T)
{
    int value;
    while (cin >> value)
    {
        if (value == -1)
            return;
        Insert(T, value);
    }
}

int CountNode(TREE T)
{
    int static cnt = 0;
    if(T != NULL)
    {
        cnt++;
        CountNode(T->pLeft);
        CountNode(T->pRight);
    }
    return cnt;
}

/* -------------------------------------- */

int main()
{
    TREE T;   // hay: TNODE* T;
    T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)
    CreateTree(T);
    cout << CountNode(T);
    return 0;
}
