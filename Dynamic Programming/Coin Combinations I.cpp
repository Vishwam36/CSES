// https://cses.fi/problemset/result/4031716/

#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
const ll mod = 1e9 + 7;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
	int n, x;
    cin >> n >> x;
    vector<int> c(n);
    for(int& x : c)
        cin >> x;
    
    sort(c.begin(), c.end());
    
    vector<int> dp(x+1, 0);
    dp[0] = 1;
    for(int i = 1; i <= x; ++i)
        for(int coin : c)
            if(i-coin >= 0)
            {
                dp[i] += dp[i-coin];
                dp[i] %= mod;
            }
            else
            {
                break;
            }
 
    cout << dp[x];
}
