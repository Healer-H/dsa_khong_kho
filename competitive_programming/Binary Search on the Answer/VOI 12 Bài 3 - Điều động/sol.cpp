#include <bits/stdc++.h>
using namespace std;
int const MAXN = 1e5 + 7;
#define REP(i, a, b) for (int i = a; i <= b; ++i)
#define REPD(i, b, a) for (int i = b; i >= a; --i)
#define sz(s) (int)(s).size()

int n;
pair<int, int> a[MAXN];

bool check(int maxTime, int n)
{
    int left[n + 1];
    int right[n + 1];

    REP(i, 1, n)
    left[i] = right[i] = 0;

    REP(i, 1, n)
    {
        left[max(1, a[i].first - maxTime / a[i].second)]++;
        right[min(n, a[i].first + maxTime / a[i].second)]++;
    }

    REP(i, 1, n - 1)
    {
        left[i + 1] += left[i];
        right[i + 1] += right[i];
    }

    REP(i, 1, n)
    {
        if (left[i] < i || right[i] > i)
            return false;
    }
    return true;
}

void solve()
{
    cin >> n;
    REP(i, 1, n)
    cin >> a[i].first >> a[i].second;

    int low = 0;
    int high = 100000000;
    int ans = INT_MAX;
    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (check(mid, n))
        {
            ans = min(ans, mid);
            high = mid - 1;
        }

        else
            low = mid + 1;
    }
        cout << ans << endl;
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
