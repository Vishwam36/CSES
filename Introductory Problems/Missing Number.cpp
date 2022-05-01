// https://cses.fi/problemset/task/1083

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    int n, x = 0, a;
    cin >> n;
    for(int i = 0; i < n-1; ++i)
    {
        cin >> a;
        x ^= a;
    }
    for(int i = 1; i <= n; ++i)
        x ^= i;
    
    cout << x << '\n';
}
