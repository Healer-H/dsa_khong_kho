#include <bits/stdc++.h>
using namespace std;
int const MAXN = 1e6 + 7;
#define REP(i, a, b) for(int i = a; i <= b; ++i)
#define REPD(i, b, a) for(int i = b; i >= a; --i)
#define sz(s) (int)(s).size()

int n, k;
int a[MAXN];

bool check(int* a, int n, int median)
{
    vector <int> b(n);

    REP(i, 0, n - 1)
        if(a[i] < median)
            b[i] = -1;
        else
            b[i] = 1;
    
    REP(i, 1, n - 1)
        b[i] += b[i - 1];

    
    

}

void solve()
{
    cin >> n >> k;

    REP(i, 0, n - 1)
        cin >> a[i];

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int numTest;
    cin >> numTest;
    // numTest = 1;
    while(numTest--)
    {
        solve();
    }
}