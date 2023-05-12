
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

bool IsCompleteBST(TREE T)
{
    if (T == NULL)
        return true;
    queue<TNODE *> bfs;
    bfs.push(T);
    int numNode = 1;
    int maximunNumNode = 1;

    while (maximunNumNode == numNode)
    {
        while (numNode--)
        {
            TNODE *it = bfs.front();
            bfs.pop();
            if (it->pLeft != NULL)
                bfs.push(it->pLeft);
            if (it->pRight != NULL)
                bfs.push(it->pRight);
        }

        numNode = (int)bfs.size();

        maximunNumNode *= 2;
    }
    
    queue <TNODE*> copyBFS(bfs);
    while(!copyBFS.empty())
    {
        TNODE* it = copyBFS.front();
        copyBFS.pop();
        if(it->pLeft != NULL || it->pRight != NULL)
            return false;
    }


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
