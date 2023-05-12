
#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

struct TNODE
{
    int key;
    TNODE *pLeft;
    TNODE *pRight;
};
typedef TNODE *TREE;

/* ------------------------------------- */
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

int CountNode(TREE T)
{
    if (T == NULL)
        return 0;
    return 1 + CountNode(T->pLeft) + CountNode(T->pRight);
}

bool IsCompleteBST(TREE T)
{
    if (T == NULL)
        return true;
    queue<TNODE *> bfs;
    bfs.push(T);
    bool flag = true;
    TNODE *it;
    while (!bfs.empty())
    {
        int numNode = bfs.size();
        while (numNode--)
        {
            it = bfs.front();
            bfs.pop();
            if (flag)
            {
                if (it->pLeft != NULL)
                    bfs.push(it->pLeft);
                else
                {
                    flag = false;
                }
                if (it->pRight != NULL)
                    bfs.push(it->pRight);
                else
                {
                    flag = false;
                }
            }
            else
            {
                if(it->pLeft != NULL || it->pRight != NULL)
                    return false;
            }
        }
    }
    return true;
}
/* ------------------------------------- */

int main()
{
    TREE T;   // hay: TNODE* T;
    T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)
    CreateTree(T);

    if (T == NULL)
        cout << "Empty Tree.";
    else
        cout << boolalpha << IsCompleteBST(T);

    return 0;
}
