// https://cses.fi/problemset/task/1084/

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> a(n), b(m);
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    for(int i = 0; i < m; ++i)
        cin >> b[i];
    
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int idx = 0, ans = 0;
    for(int i = 0; i < n; ++i)
    {
        idx = lower_bound(b.begin() + idx, b.end(), a[i] - k) - b.begin();
        if(idx < 0 || idx >= m)
            break;
        
        if(abs(a[i] - b[idx]) > k)
            continue;
        
        b[idx] = INT_MIN;
        ans++;
    }
    cout << ans << endl;
}
