#include <bits/stdc++.h>
using namespace std;
int const MAXN = 1e6 + 7;
#define REP(i, a, b) for (int i = a; i <= b; ++i)
#define REPD(i, b, a) for (int i = b; i >= a; --i)
#define sz(s) (int)(s).size()

int n;
int dp[100001][3];

void solve()
{
    cin >> n;
    vector<int> zero(n + 1);
    vector<int> first(n + 1);
    vector<int> second(n + 1);

    REP(i, 1, n)
        cin >> zero[i] >> first[i] >> second[i];

    REP(i, 1, n)
    {
        dp[i][0] = max(dp[i - 1][1], dp[i - 1][2]) + zero[i];
        dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]) + first[i];
        dp[i][2] = max(dp[i - 1][0], dp[i - 1][1]) + second[i];
    }

    cout << max({dp[n][0], dp[n][1], dp[n][2]}) << endl;
    
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