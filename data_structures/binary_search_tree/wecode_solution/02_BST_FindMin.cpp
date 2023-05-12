
#include <iostream>
using namespace std;

struct TNODE
{
    int key;
    TNODE *pLeft;
    TNODE *pRight;
};
typedef TNODE *TREE;

/* ---------------------------------------- */
TNODE *CreateTNode(int value)
{
    TNODE *newNode = new TNODE;
    newNode->key = value;
    newNode->pRight = newNode->pLeft = NULL;
    return newNode;
}
void Insert(TNODE *&T, int value)
{
    TNODE *addNode = CreateTNode(value);

    if (T == NULL)
    {
        T = addNode;
        return;
    }

    TNODE *it = T;
    while (true)
    {
        if (addNode->key == it->key)
            return;
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

void CreateTree(TNODE *&T)
{
    int value;
    while (cin >> value)
    {
        if (value == -1)
            return;
        Insert(T, value);
    }
}

TNODE *FindMin(TNODE *T)
{
    TNODE *it = T;
    while (it->pLeft != NULL)
        it = it->pLeft;
    return it;
}

/* ---------------------------------------- */

int main()
{
    TREE T;   // hay: TNODE* T;
    T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)
    CreateTree(T);

    if (T == NULL)
        cout << "Empty Tree.";
    else
        cout << FindMin(T)->key;
    return 0;
}
