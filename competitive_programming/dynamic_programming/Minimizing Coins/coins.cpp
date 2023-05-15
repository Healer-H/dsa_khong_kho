/* https://cses.fi/problemset/task/1634/ */
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define REP(i, a, b) for (int i = a; i <= b; ++i)
#define REPD(i, b, a) for (int i = b; i >= a; --i)
#define sz(s) (int)(s).size()
#define pii pair<int, int>
#define vi vector<int>
#define vii vector<pii>
#define INF 1000004
int const MAXN = 1e6 + 4;

int f[2][MAXN];
int n, x;
void solve()
{
    REP(i, 1, MAXN - 1)
    f[0][i] = INF;
    f[0][0] = 0;

    cin >> n >> x;
    vi a(n + 1);
    REP(i, 1, n)
    cin >> a[i];
    int status = 1;
    REP(i, 1, n)
    {
        int prev = (status + 1) % 2;
        REP(j, 0, x)
        {
            f[status][j] = f[prev][j];
            if (j >= a[i])
                f[status][j] = min(f[status][j], f[status][j - a[i]] + 1);
        }
        status = prev;
    }
    cout << ((f[n % 2][x] == INF) ? -1 : f[n % 2][x]);
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int numTest = 1;
    // cin >> numTest;
    while (numTest--)
    {
        solve();
    }
}