#include <bits/stdc++.h>

using namespace std;

long long fibo(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return fibo(n - 1) + fibo(n - 2);
}

int main()
{
    int n;
    while (cin >> n)
    {
        if (n == -1)
            return 0;
        cout << "The " << n << "-th Fibonancci number is: " << fibo(n) << endl;
    }
}