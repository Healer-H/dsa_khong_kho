#include <bits/stdc++.h>
using namespace std;
int const MAXN = 1e5 + 7;
#define REP(i, a, b) for(int i = a; i <= b; ++i)
#define REPD(i, b, a) for(int i = b; i >= a; --i)
#define sz(s) (int)(s).size()

int n;
int liq[MAXN];

void solve()
{
    cin >> n;
    vector <int> a(n); 
    REP(i, 0, n - 1)
        cin >> a[i];

    liq[0] = 1;
    REP(i, 1, n - 1)
    {
        REP(j, 0, i - 1)
        if(a[i] > a[j])
        liq[i] = max(liq[j] + 1, liq[i]);
    }

    cout << *max_element(liq, liq + n);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int numTest;
    // cin >> numTest;
    REP(i, 0, MAXN - 1)
        liq[i] = 1;
    numTest = 1;
    while(numTest--)
    {
        solve();
    }
}