
#include <iostream>
using namespace std;

struct TNODE {
	int key;
	TNODE* pLeft;
	TNODE* pRight;
};
typedef TNODE* TREE;
/* -------------------------------------------- */

void Insert(TREE& T, int item)
{
    TNODE* addNode = new TNODE;
    addNode->pLeft = addNode->pRight = NULL;
    addNode->key = item;

    if(T == NULL)
    {
        T = addNode;
        return;
    }

    TNODE* it = T;
    while(true)
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

void CreateTree(TREE& T)
{
    int item;
    while(cin >> item)
    {
        if(item == -1)
            return;
        Insert(T, item);
    }
}

int Height(TREE T)
{
    if(T == NULL)
        return 0;
    if(T->pLeft == NULL && T->pRight == NULL)
        return 0;
    int leftHeight = Height(T->pLeft);
    int rightHeight = Height(T->pRight);
    return 1 + max(leftHeight, rightHeight);
}


/* -------------------------------------------- */
int main() {
	TREE T; //hay: TNODE* T;
	T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)
	CreateTree(T);
	if(T==NULL) cout << "Empty Tree.";
	else cout << Height(T);
	return 0;
}
