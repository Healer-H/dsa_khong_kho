#include <bits/stdc++.h>
using namespace std;
#define int long long
#define REP(i, a, b) for (int i = a; i <= b; ++i)
#define REPD(i, b, a) for (int i = b; i >= a; --i)
#define sz(s) (int)(s).size()
#define pii pair<int, int>
#define vi vector<int>
#define vii vector<pii>

int n, f[100001][4][4][4][4];
int conv(char c)
{
    if (c == 'M')
        return 1;
    if (c == 'F')
        return 2;
    if (c == 'B')
        return 3;
    return 0;
}

int calc(int a, int b, int c)
{
    int sum = 0;
    if (a == 1 || b == 1 || c == 1)
        sum++;
    if (a == 2 || b == 2 || c == 2)
        sum++;
    if (a == 3 || b == 3 || c == 3)
        sum++;
    return sum;
}
void solve()
{
    cin >> n;
    char c;
    vector<int> p(n + 1);
    REP(i, 1, n)
    {
        cin >> c;
        p[i] = conv(c);
    }
    // basecase
    REP(i, 0, n)
    REP(a, 0, 3)
    REP(b, 0, 3)
    REP(c, 0, 3)
    REP(d, 0, 3)
    f[i][a][b][c][d] = -10000;
    f[0][0][0][0][0] = 0;

    REP(i, 1, n)
    {
        int curr = p[i];
        REP(a, 0, 3)
        REP(b, 0, 3)
        REP(c, 0, 3)
        REP(d, 0, 3)
        {
            f[i][b][curr][c][d] = max(f[i][b][curr][c][d], f[i - 1][a][b][c][d] + calc(a, b, curr));

            f[i][a][b][d][curr] = max(f[i][a][b][d][curr], f[i - 1][a][b][c][d] + calc(c, d, curr));
        }
    }
    int ans = f[n][0][0][0][0];
    REP(a, 0, 3)
    REP(b, 0, 3)
    REP(c, 0, 3)
    REP(d, 0, 3)
        ans = max(ans, f[n][a][b][c][d]);
    cout << ans << endl;
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