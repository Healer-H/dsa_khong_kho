
#include <iostream>
using namespace std;

struct TNODE
{
    int key;
    TNODE *pLeft;
    TNODE *pRight;
};
typedef TNODE *TREE;

/* --------------------------------------------- */
void Insert(TREE &T, int item)
{
    TNODE *addNode = new TNODE;
    addNode->key = item;
    addNode->pLeft = addNode->pRight = NULL;

    if (T == NULL)
    {
        T = addNode;
        return;
    }
    TNODE *it = T;
    while (true)
    {
        if (item == it->key)
        {
            return;
        }
        if (item < it->key)
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
void CreateTree(TREE &T)
{
    int item;
    while (cin >> item)
    {
        if (item == -1)
            return;
        Insert(T, item);
    }
}

void DeleteNode(TREE &T, int item)
{
    if (T == NULL)
        return;
    if (item < T->key)
        DeleteNode(T->pLeft, item);
    if (item > T->key)
        DeleteNode(T->pRight, item);

    if (T->pLeft == NULL)
    {
        T = T->pRight;
        return;
    }
    if (T->pRight == NULL)
    {
        T = T->pLeft;
        return;
    }

    TNODE *tmp = T->pRight, *tmpParent = T;
    while (tmp->pLeft != NULL)
    {
        tmpParent = tmp;
        tmp = tmp->pLeft;
    }
    if (tmpParent != T)
    {
        T->key = tmp->key;
        tmpParent->pLeft = tmp->pRight;
        return;
    }
    else
    {
        T->key = tmp->key;
        T->pRight = tmp->pRight;
        return;
    }
}

void PrintTree(TREE T)
{
    if (T != NULL)
    {
        cout << T->key << " ";
        PrintTree(T->pLeft);
        PrintTree(T->pRight);
    }
}

/* --------------------------------------------- */

int main()
{
    TREE T;   // hay: TNODE* T;
    T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)
    CreateTree(T);

    int x;
    cin >> x;

    PrintTree(T);
    cout << endl;

    DeleteNode(T, x);
    PrintTree(T);

    return 0;
}
