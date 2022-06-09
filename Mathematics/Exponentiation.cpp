// https://cses.fi/problemset/task/1095

#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
const ll mod = 1e9 + 7;

ll exp(ll a, ll b)
{
    if(b == 0)
    {
        if(a == 0)
            return 1;
        return 1;
    }
    if(b == 1)
        return a;
    
    ll ans;
    if(b % 2 == 0)
    {
        ans = exp(a, b/2);
        ans = ans * ans;
    }
    else
    {
        ans = exp(a, b/2);
        ans = ((ans * ans) % mod) * a;
    }
    return ans % mod;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
	ll n, a, b;
    cin >> n;
    for(int i = 0 ; i < n; ++i)
    {
        cin >> a >> b;
        cout << exp(a, b) << endl;
    }
}
