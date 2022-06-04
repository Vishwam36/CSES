// https://cses.fi/problemset/task/1646

#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
const ll mod = 1e9 + 7;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
	int n, q;
    cin >> n >> q;
    vector<ll> pre(n+1, 0);
    for(int i = 0; i < n; ++i)
    {
        cin >> pre[i+1];
        pre[i+1] += pre[i];
    }

    while(q--)
    {
        int a, b;
        cin >> a >> b;
        cout << pre[b] - pre[a-1] << endl;
    }
}
