#include <bits/stdc++.h>

using namespace std;

int const MAX = 1e3 + 5;
int n, dp[MAX];
vector<int> arr;

void calc()
{
    for (int i = 0; i < n; i++)
        dp[i] = 1;

    for (int i = 1; i < n; i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if (arr[j] < arr[i])
                dp[i] = max(dp[i], dp[j] + 1);
        }
    }
}

int main()
{
    // get input
    cin >> n;
    arr.resize(n);
    for (int &item : arr)
        cin >> item;

    // process
    calc();

    // print output
    int ans = 1;
    for (int i = 0; i < n; i++)
        ans = max(ans, dp[i]);
    cout << ans << endl;

    return 0;
}