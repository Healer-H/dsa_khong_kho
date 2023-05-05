#include <bits/stdc++.h>
using namespace std;
int const MAXN = 1e5 + 7;
#define REP(i, a, b) for (int i = a; i <= b; ++i)
#define REPD(i, b, a) for (int i = b; i >= a; --i)
#define sz(s) (int)(s).size()

int dp[MAXN];

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    REP(i, 0, n - 1)   
        cin >> a[i];

    // dp[n] = min(dp[n - 1] + abs(a[n - 1] - a[n]), dp[n - 2] + abs(a[n - 2] - a[n]))
    // base-case
    dp[0] = 0;
    dp[1] = abs(a[1] - a[0]);

    REP(i, 2, n - 1)
    {
        dp[i] = min(dp[i - 1] + abs(a[i - 1] - a[i]), dp[i - 2] + abs(a[i - 2] - a[i]));
    }
    cout << dp[n - 1] << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    REP(i, 0, MAXN - 1)
        dp[i] = 0;
    int numTest;
    // cin >> numTest;
    numTest = 1;
    while (numTest--)
    {
        solve();
    }
}