// https://cses.fi/problemset/task/1617

#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
ll mod = 1e9 + 7;
 
ll myPow(ll base, ll p)
{
    if(p == 0)
        return 1;
    
    ll ans = myPow(base, p/2);
    
    if(p % 2 == 0)
        return (ans * ans) % mod;
    
    return (((ans * ans) % mod) * base) % mod;
}
 
int main()
{
    int n;
    cin >> n;
    cout << myPow(2, n) << endl;
}
