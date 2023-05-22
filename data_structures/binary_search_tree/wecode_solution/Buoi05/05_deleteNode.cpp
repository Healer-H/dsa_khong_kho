
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

TNODE *CreateNode(int item)
{
    TNODE *newNode = new TNODE;
    newNode->key = item;
    newNode->pLeft = newNode->pRight = NULL;
    return newNode;
}
void Insert(TREE &T, int item)
{
    TNODE *addNode = CreateNode(item);
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

void replace(TREE& node, TREE& replaceNode)
{
    if(replaceNode->pLeft != NULL)
        replace(node, replaceNode->pLeft);
    else
    {
        node->key = replaceNode->key;
        node = replaceNode;
        replaceNode = replaceNode->pRight;
    }
}
void DeleteNode(TREE &T, int item)
{
    if (T == NULL)
        return;
    if (item < T->key)
        DeleteNode(T->pLeft, item);
    else if (item > T->key)
        DeleteNode(T->pRight, item);
    else
    {
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
        TNODE* tmp = T;
        replace(tmp, T->pRight);
        delete tmp;
    }
}

void PrintTreeNLR(TREE T)
{
    if (T != NULL)
    {
        cout << T->key << " ";
        PrintTreeNLR(T->pLeft);
        PrintTreeNLR(T->pRight);
    }
}

void PrintTree(TREE T)
{
    if(T == NULL)
    {
        cout << "Empty Tree. \n";
    }
    else
        PrintTreeNLR(T);
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
    // cout << (findNode(T, 30))->key;
    PrintTree(T);

    return 0;
}
