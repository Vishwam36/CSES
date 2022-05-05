// https://cses.fi/problemset/task/1090/

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ll n, x;
    cin >> n >> x;
    vector<ll> p(n);
    for(int i = 0; i < n; ++i)
        cin >> p[i];
    
    sort(p.begin(), p.end());
    int l = 0, r = n-1, ans = 0;
    while(r >= l)
    {
        if(p[l] + p[r] <= x)
        {
            ++ans;
            ++l;
            --r;
        }
        else
        {
            --r;
            ++ans;
        }
    }
    cout << ans << endl;
}
