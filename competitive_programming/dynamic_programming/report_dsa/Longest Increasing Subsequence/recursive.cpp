#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> arr;

int liq(int id)
{
    int ans = 1;

    for (int i = id - 1; i >= 0; i--)
    {
        if (arr[i] < arr[id])
        {
            ans = max(ans, liq(i) + 1);
        }
    }
    return ans;
}

int main()
{
    // get input
    cin >> n;
    arr.resize(n);
    for (int &item : arr)
        cin >> item;

    // print output
    int ans = 1;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, liq(i));
    }
    cout << ans;
    return 0;
}