

#include <iostream>
using namespace std;

#define MAXTABLESIZE 10000

struct NODE
{
    int key;
};
typedef NODE *HASHTABLE[MAXTABLESIZE];

int TableSize;
int M;

int HF(int key)
{
    return key % M;
}
int HF_LinearProbing(int key, int i)
{
    return (HF(key) + i) % TableSize;
}
/*  */

void CreateHashTable(HASHTABLE &H, int &size)
{
    size = 0;
    for (int i = 0; i < MAXTABLESIZE; i++)
    {
        H[i] = new NODE;
        H[i]->key = -1;
    }

    cin >> M;
    cin >> TableSize;
    int item;
    while (cin >> item && size < TableSize)
    {
        if (item == -1)
        {
            size = TableSize;
            return;
        }
        int pos = HF(item);
        bool flag = true; // flag = true: chua dat duoc item vao dung vi tri
        int times = 1;
        while (flag)
        {
            if (H[pos]->key == -1)
            {
                H[pos]->key = item;
                flag = false;
            }
            else
            {
                pos = (pos + 1) % TableSize;
            }
        }
        size++;
    }
}

void Traverse(HASHTABLE H, int num)
{
    for (int i = 0; i < num; i++)
    {
        cout << i << " --> " << H[i]->key << endl;
    }
}

/*  */

int main()
{
    HASHTABLE H;
    int CurrentSize;

    CreateHashTable(H, CurrentSize);
    Traverse(H, CurrentSize);

    return 0;
}
