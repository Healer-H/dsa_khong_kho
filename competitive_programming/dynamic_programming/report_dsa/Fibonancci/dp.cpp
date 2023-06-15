#include <bits/stdc++.h>

using namespace std;

int const MAX = 1e5;
long long f[MAX];

long long fibo(int n)
{
    if(f[n] != -1)
        return f[n];
    return f[n] = fibo(n - 1) + fibo(n - 2);
}

int main()
{
    memset(f, -1, sizeof(f));
    f[0] = 0, f[1] = 1;
    int n;
    while (cin >> n)
    {
        if (n == -1)
            return 0;
        cout << "The " << n << "-th Fibonancci number is: " << fibo(n) << endl;
    }
    return 0;
}