
#include <iostream>
using namespace std;

struct TNODE {
	int key;
	TNODE* pLeft;
	TNODE* pRight;
};
typedef TNODE* TREE;

/* -------------------------------------------------- */
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

void CountNode(TREE T, int& cnt)
{
    if(T == NULL)
    {
        cnt = 0;
        return;
    }
    cnt = 1;
    int leftCount = 0;
    int rightCount = 0;
    CountNode(T->pLeft, leftCount);
    CountNode(T->pRight, rightCount);

    cnt += leftCount + rightCount;
}
/* -------------------------------------------------- */

int main() {
	TREE T; //hay: TNODE* T;
	T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)
	CreateTree(T);

	int count=0;
	CountNode(T, count);
	cout << count;
	return 0;
}
