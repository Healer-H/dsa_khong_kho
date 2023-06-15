#include <bits/stdc++.h>

using namespace std;

int const MAX = 1e3 + 5;
int dp[MAX][MAX], n, sum;
vector<int> coins;

void calc()
{
    for (int i = 0; i <= n; i++)
        dp[0][i] = 1;

    for (int i = 1; i <= sum; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            dp[i][j] += dp[i][j - 1];
            if (i >= coins[j])
            {
                dp[i][j] += dp[i - coins[j]][j];
            }
        }
    }
}

void print(int row, int col)
{
    for (int i = 1; i <= row; i++)
    {
        cout << "Row " << i << ": ";
        for (int j = 1; j <= col; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    cin >> n;
    coins.resize(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> coins[i];
    cin >> sum;
    calc();
    cout << dp[sum][n] << endl;
    print(sum, n);
    return 0;
}