/* https://vinhdinhcoder.net/Problem/Details/5043 */

#include <bits/stdc++.h>
using namespace std;
#define REP(i, a, b) for (int i = a; i <= b; ++i)
#define REPD(i, b, a) for (int i = b; i >= a; --i)
#define sz(s) (int)(s).size()
#define pii pair<int, int>
#define vi vector<int>
#define vii vector<pii>

int const MAXN = 1e4 + 6;

long long f[MAXN][2];

void solve()
{
    int n;
    cin >> n;
    vi a(n + 1);
    REP(i, 1, n)
    cin >> a[i];

    // base-case
    
    REP(i, 1, n)
        f[i][1] = 0;
    f[1][0] = a[1];
    f[1][1] = 1;

    f[2][0] = a[1] + a[2];
    f[2][1] = 2;

    f[3][0] = a[1] + a[2] + a[3] - min({a[1], a[2], a[3]});
    f[3][1] = 2;

    

    // cong thuc dp: f[n][0] = max(f[n - 2] + a[n], f[n - 3] + a[n - 1] + a[n], f[n - 1])
    REP(i, 4, n)
    {
        f[i][0] = max({f[i - 2][0] + a[i], f[i - 3][0] + a[i - 1] + a[i], f[i - 1][0]});

        if (f[i][0] == f[i - 2][0] + a[i])
            f[i][1] = f[i - 2][1] + 1;
        if(f[i][0] == f[i - 3][0] + a[i - 1] + a[i])
            f[i][1] = f[i - 3][1] + 2;
        if(f[i][0] == f[i -1][0])
            f[i][1] = f[i - 1][1];
    }

    cout << f[n][1] << " " << f[n][0] << endl;
}


int main()
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