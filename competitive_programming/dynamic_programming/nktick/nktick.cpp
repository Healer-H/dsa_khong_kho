/* https://oj.vnoi.info/problem/nktick */
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define REP(i, a, b) for (int i = a; i <= b; ++i)
#define REPD(i, b, a) for (int i = b; i >= a; --i)
#define sz(s) (int)(s).size()
#define pii pair<int, int>
#define vi vector<int>
#define vii vector<pii>
int const MAXN = 6e4 + 5;
int f[MAXN];
int n;
void solve()
{
    cin >> n;
    vi a(n + 1);
    vi r(n + 1);
    REP(i, 1, n)
        cin >> a[i];
    REP(i, 2, n)
        cin >> r[i];
    f[1] = a[1];
    f[2] = min(a[1] + a[2], r[2]);

    REP(i, 3, n)
    {
        f[i] = min(f[i - 1] + a[i], f[i - 2] + r[i]);
    }
    cout << f[n] << endl;
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