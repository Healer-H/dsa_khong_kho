/* https://dmoj.ca/problem/ioi99p1 */
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define REP(i, a, b) for (int i = a; i <= b; ++i)
#define REPD(i, b, a) for (int i = b; i >= a; --i)
#define sz(s) (int)(s).size()
#define pii pair<int, int>
#define vi vector<int>
#define vii vector<pii>
#define INF 1000000
int n, m, f[105][105];
int c[105][105];

void solve()
{
    cin >> n >> m;
    REP(i, 0, n)
    f[0][i] = 0;
    REP(i, 1, n)
    {
        REP(j, 1, m)
        cin >> c[i][j];
    }
    REP(i, 1, n)
    {
        REP(j, i, m)
        {
            f[i][j] = max(f[i][j - 1], f[i - 1][j - 1] + c[i][j]);
        }
    }
    cout << f[n][m] << endl;
    int i = n, j = m;
    vector<int> ans;
    while (i > 0)
    {
        if (f[i][j] == f[i - 1][j - 1] + c[i][j])
        {
            ans.push_back(j);
            i--;
            j--;
        }
        else
            j--;
    }
    REPD(t, ans.size() - 1, 0)
        cout << ans[t] << " ";
    //solution 2: AC 9/10 testcases, chưa biết fix như thế nào cho đúng =)))
    /*  REP(i, 1, n)
     {
         REP(j, i, m)
         {
             REP(k, 1, j - 1)
             f[i][j] = max(f[i][j], f[i - 1][k] + c[i][j]);
         }
     }
     int i = n, j = 0;
     REP(k, 0, m)
     {
         if(f[n][k] > f[i][j])
         {
             j = k;
         }
     }
     cout << f[i][j] << "\n";
     stack <int> d;
     while(i > 0)
     {
         d.push(j);
         REP(k, 1, m)
         {
             if(f[i - 1][k] == f[i][j] - c[i][j])
             {
                 j = k;
                 --i;
                 break;
             }
         }
     }
     while(!d.empty())
     {
         cout << d.top() << " ";
         d.pop();
     } */
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int numTest = 1;
    // cin >> numTest;
    REP(i, 0, 104)
    REP(j, 0, 104)
    f[i][j] = -INF;
    while (numTest--)
    {
        solve();
    }
}
