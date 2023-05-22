
#include <iostream>
using namespace std;

struct TNODE
{
    int key;
    TNODE *pLeft;
    TNODE *pRight;
};
typedef TNODE *TREE;

/* ------------------------------- */
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
        if(it->key == item)
        {
            return;
        }
        if(item < it->key)
        {
            if(it->pLeft == NULL)
            {
                it->pLeft = addNode;
                return;
            }
            it = it->pLeft;
        }
        else
        {
            if(it->pRight == NULL)
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
int CountNode_Have1Child(TREE T)
{
    if(T == NULL)
        return 0;
    int tmp = 0;
    if((T->pLeft != NULL && T->pRight == NULL) || (T->pLeft == NULL && T->pRight != NULL))
        tmp = 1;;
    
    return tmp + CountNode_Have1Child(T->pLeft) + CountNode_Have1Child(T->pRight); 
    
}
/* ------------------------------- */

int main()
{
    TREE T;   // hay: TNODE* T;
    T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)
    CreateTree(T);
    cout << CountNode_Have1Child(T);
    return 0;
}
