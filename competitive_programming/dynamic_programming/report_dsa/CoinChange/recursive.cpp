#include <bits/stdc++.h>

using namespace std;
int n, sum;
vector<int> coins;

int coinChange(vector<int> coins, int size, int sum)
{
    if(sum < 0)
        return 0;
    if(sum == 0)
        return 1;
    if(size <= 0)
        return 0;
    return coinChange(coins, size, sum - coins[size - 1]) + coinChange(coins, size - 1, sum);
}

int main()
{
    cin >> n;
    coins.resize(n);
    for(int &item : coins)
        cin >> item;
    cin >> sum;
    cout << coinChange(coins, coins.size() ,sum);
    return 0;
}