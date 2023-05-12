
#include <iostream>
using namespace std;

struct TNODE {
	int key;
	TNODE* pLeft;
	TNODE* pRight;
};
typedef TNODE* TREE;
/* ------------------------------------------  */
TNODE* CreateNode(int value)
{
    TNODE* newNode = new TNODE;
    newNode->key = value;
    newNode->pLeft = newNode->pRight = NULL;
    return newNode;
}
void Insert(TREE& T, int value)
{
    TNODE* addNode = CreateNode(value);
    if(T == NULL)
    {
        T = addNode;
        return;
    }
    TNODE* it = T;
    while(true)
    {
        if(it->key == addNode->key)
            return;
        if(it->key > addNode->key)
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
void CreateTree(TREE& T)
{
    int value;
    while(cin >> value)
    {
        if(value == -1)
            return;
        Insert(T, value);
    }
}

int SumNode(TREE T)
{
    if(T == NULL)
        return 0;
    return T->key + SumNode(T->pLeft) + SumNode(T->pRight);
}

/* ------------------------------------------  */
int main() {
	TREE T; //hay: TNODE* T;
	T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)
	CreateTree(T);
	cout << SumNode(T);
	return 0;
}

