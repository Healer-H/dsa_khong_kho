#include <bits/stdc++.h>
using namespace std;
int const MAXN = 1e6 + 7;
#define REP(i, a, b) for (int i = a; i <= b; ++i)
#define REPD(i, b, a) for (int i = b; i >= a; --i)
#define sz(s) (int)(s).size()

string s1, s2;

void solve()
{
    int m = sz(s1);
    int n = sz(s2);

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    REP(i, 0, m - 1)
    {
        REP(j, 0, n - 1)
        {
            if (s1[i] != s2[j])
                dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
            else
                dp[i + 1][j + 1] = max({dp[i][j] + 1, dp[i][j + 1], dp[i + 1][j]});
        }
    }

    cout << dp[m][n] << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int numTest;
    // cin >> numTest;
    // numTest = 1;
    while (getline(cin, s1))
    {
        getline(cin, s2);
        solve();
    }
}