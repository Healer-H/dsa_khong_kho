
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
#include <stack>
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

void PrintTree(TREE T) // duyet qua tree su dung stack
{
    if (T == NULL)
    {
        cout << "Empty Tree. \n";
        return;
    }

    stack <TNODE*> RNL;
    TNODE* curr = T;
    while(!RNL.empty() || curr != NULL)
    {
        while(curr != NULL)
        {
            RNL.push(curr);
            curr = curr->pRight;
        }
        curr = RNL.top();
        RNL.pop();

        cout << curr->key << " ";

        curr = curr->pLeft;
    }
}

/* -------------------------------------- */

int main()
{
    TREE T;   // hay: TNODE* T;
    T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)
    CreateTree(T);
    PrintTree(T);
    return 0;
}
