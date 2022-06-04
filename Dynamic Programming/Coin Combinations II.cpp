// https://cses.fi/problemset/task/1636/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll mod = 1000000007;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll n, sum;
    cin >> n >> sum;
    vector<ll> c(n);
    for(int i = 0; i < n; ++i)
        cin >> c[i];
    
    vector<ll> dp(sum+1, 0);
    dp[0] = 1;

    for(auto& coin : c)
        for(ll i = coin; i <= sum; ++i)
        {
            dp[i] += dp[i-coin];
            dp[i] %= mod;
        }
    
    cout << dp[sum] << endl;
}
