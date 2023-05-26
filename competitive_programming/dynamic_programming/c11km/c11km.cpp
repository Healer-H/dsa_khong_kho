/* https://oj.vnoi.info/problem/c11km */
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define REP(i, a, b) for (int i = a; i <= b; ++i)
#define REPD(i, b, a) for (int i = b; i >= a; --i)
#define sz(s) (int)(s).size()
#define pii pair<int, int>
#define vi vector<int>
#define vii vector<pii>
#define INF 1000000
int n, c[1005], f[1005][1005];

void solve()
{
    cin >> n;
    REP(i, 1, n)
    cin >> c[i];

    f[0][0] = 0;
    
    REP(i, 1, n)
    {
        REPD(j, n, 0)
        {
            if(c[i] > 100 && j >= 1)
            {
                f[i][j] = min(f[i - 1][j - 1] + c[i], f[i - 1][j + 1]);
            }
            else
            {
                f[i][j] = min(f[i - 1][j] + c[i], f[i - 1][j + 1]);
            }
        }
    }
    int ans = f[n][0];
    for(int i = 0; i <= n; i++)
    {
        ans = min(ans, f[n][i]);
    }
    cout << ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int numTest = 1;
    // cin >> numTest;
    REP(i, 0, 1000)
    REP(j, 0, 1000)
    f[i][j] = INF;
    while (numTest--)
    {
        solve();
    }
}