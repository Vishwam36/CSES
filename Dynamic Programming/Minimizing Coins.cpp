// https://cses.fi/problemset/task/1634/

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ll n, x;
    cin >> n >> x;
    vector<ll> c(n);
    for(int i = 0; i < n; ++i)
        cin >> c[i];
    
    vector<ll> dp(x+1, INT_MAX);
    dp[0] = 0;
    for(int i = 1; i <= x; ++i)
        for(auto& coin : c)
            if(i-coin >= 0)
                dp[i] = min(dp[i], dp[i-coin] + 1);

    cout << (dp[x] >= INT_MAX ? -1 : dp[x]) << endl;
}
