/* https://www.spoj.com/problems/IOIPALIN/ */

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define REP(i, a, b) for (int i = a; i <= b; ++i)
#define REPD(i, b, a) for (int i = b; i >= a; --i)
#define sz(s) (int)(s).size()
#define pii pair<int, int>
#define vi vector<int>
#define vii vector<pii>

int f[5005][5005];

void solve()
{
    string s = "0", tmp;
    int n;
    cin >> n >> tmp;
    // n--;
    s += tmp;

    REP(i, 0, n)
    {
        if (s[i] != s[i + 1])
            f[i][i + 1] = 1;
    }

    int step = 2;
    while (step < n)
    {
        REP(i, 0, n - step)
        {
            if (s[i] == s[i + step])
            {
                f[i][i + step] = f[i + 1][i + step - 1];
            }
            else
            {
                f[i][i + step] = min(f[i + 1][i + step], f[i][i + step - 1]) + 1;
            }
        }
        step++;
    }
    cout << f[1][n];
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