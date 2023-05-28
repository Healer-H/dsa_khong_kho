#include <bits/stdc++.h>

using namespace std;

void print(int u[1005][1005], int row, int col)
{
    for (int i = 0; i <= row; i++)
    {
        for (int j = 0; j <= col; j++)
        {
            cout << "[" << i << "][" << j << "]: " << u[i][j] << "\t";
        }
        cout << endl;
    }
}
int const INF = 1000000;
int u[1005][1005], v[1005][1005];
class Solution
{
public:
    int maxProfit(int k, vector<int> &prices)
    {
        int n = prices.size();
        for (int i = 0; i < 1005; i++)
            for (int j = 0; j < 1005; j++)
            {
                u[i][j] = v[i][j] = -INF;
            }
        for (int i = 0; i < 1005; i++)
            v[i][0] = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                u[i + 1][j + 1] = u[i][j + 1];
                u[i + 1][j + 1] = max(u[i + 1][j + 1], v[i][j] - prices[i]);

                v[i + 1][j + 1] = v[i][j + 1];
                v[i + 1][j + 1] = max(v[i + 1][j + 1], u[i][j] + prices[i]);
            }
        }
        print(u, n, k);
        cout << endl;
        print(v, n, k);
        int uu = *max_element(u[n], u[n] + k + 1);
        int vv = *max_element(v[n], v[n] + k + 1);
        cout << uu << " " << vv << endl;
        return max({uu, vv, 0});
    }
};

int main()
{
    Solution a;
    int k, n, item;
    vector<int> prices;
    cin >> k >> n;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> item;
        prices.push_back(item);
    }

    cout << a.maxProfit(k, prices) << endl;
    return 0;
}