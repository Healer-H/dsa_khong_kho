
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

/* --------------------------------------------- */
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
        if (it->key == addNode->key)
            return;
        if (addNode->key < it->key)
        {
            if (it->pLeft == NULL)
            {
                it->pLeft = addNode;
                return;
            }
            else
                it = it->pLeft;
        }
        else
        {
            if (it->pRight == NULL)
            {
                it->pRight = addNode;
                return;
            }
            else
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

void PrintLevel(TREE T, int level)
{
    if (level == -1)
    {
        cout << "Empty Tree. \n";
        return;
    }
    if(level < 0)
    {
        cout << "Khong ton tai level " << level << ". \n";
        return;
    }
    int tmp = level;
    if (T == NULL)
    {
        cout << "Empty Tree. \n";
        return;
    }

    queue<TNODE *> bfs;
    bfs.push(T);
    while (level > 0 && !bfs.empty())
    {
        level--;
        int numNode = bfs.size();
        while (numNode--)
        {
            TNODE *it = bfs.front();
            bfs.pop();

            if (it->pLeft != NULL)
                bfs.push(it->pLeft);
            if (it->pRight != NULL)
                bfs.push(it->pRight);
        }
    }
    // cout << level << endl;
    if(level > 0 || bfs.empty() == true)
    {
        cout << "Khong ton tai level " << tmp << ". \n";
        return;
    }
    else
    {
        while(bfs.empty() == false)
        {
            cout << bfs.front()->key << " ";
            bfs.pop();
        }
    }
}

/* --------------------------------------------- */

int main()
{
    // freopen("test.txt", "r", stdin);
    TNODE *T; // hay: TNODE* T;
    T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)
    int level;
    cin >> level;
    CreateTree(T);
    PrintLevel(T, level);
    return 0;
}
