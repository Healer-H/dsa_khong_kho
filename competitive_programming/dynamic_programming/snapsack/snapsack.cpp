#include <bits/stdc++.h>
using namespace std;
int const MAXN = 1e5 + 2;
#define REP(i, a, b) for (int i = a; i <= b; ++i)
#define REPD(i, b, a) for (int i = b; i >= a; --i)
#define sz(s) (int)(s).size()

int n, w;
long long f[105][MAXN];

struct item
{
    int weight;
    int value;
};

void solve()
{
    cin >> n >> w;
    vector<item> a(n + 1);

    REP(i, 1, n)
    {
        cin >> a[i].weight >> a[i].value;
    }

    REP(i, 1, n)
    {
        REP(j, 1, w)
        {
            if (j >= a[i].weight)
                f[i][j] = max(f[i - 1][j], f[i - 1][j - a[i].weight] + a[i].value);
            else
                f[i][j] = f[i - 1][j];
        }
    }
    cout << f[n][w] << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int numTest;
    // cin >> numTest;
    numTest = 1;
    while (numTest--)
    {
        solve();
    }
}