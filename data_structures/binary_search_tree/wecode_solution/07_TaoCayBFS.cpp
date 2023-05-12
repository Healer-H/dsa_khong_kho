
#include <iostream>
#include <queue>
using namespace std;

struct TNODE
{
    int key;
    TNODE *pLeft;
    TNODE *pRight;
};
typedef TNODE *TREE;
/* ---------------------------------------------- */
TNODE *CreateNode(int value)
{
    TNODE *newNode = new TNODE;
    newNode->key = value;
    newNode->pLeft = newNode->pRight = NULL;
    return newNode;
}
void Insert(TREE &T, int value)
{
    TNODE *addNode = CreateNode(value);
    if (T == NULL)
    {
        T = addNode;
        return;
    }
    TNODE *it = T;
    while (true)
    {
        if (it->key == addNode->key)
            return;
        if (it->key > addNode->key)
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

void PrintTreeBFS(TREE T)
{
    if (T == NULL)
    {
        cout << "Empty Tree. \n";
        return;
    }
    queue<TNODE *> bfs;
    bfs.push(T);

    int numOfNode = 1;

    while (!bfs.empty())
    {
        while (numOfNode--)
        {
            TNODE *it = bfs.front();
            bfs.pop();
            cout << it->key << " ";

            if(it->pLeft != NULL)
                bfs.push(it->pLeft);
            if(it->pRight != NULL)
                bfs.push(it->pRight);
        }
        cout << endl;
        numOfNode = (int) bfs.size();
    }
}
/* ---------------------------------------------- */
int main()
{
    TNODE *T; // hay: TNODE* T;
    T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)
    CreateTree(T);
    PrintTreeBFS(T);
    return 0;
}
