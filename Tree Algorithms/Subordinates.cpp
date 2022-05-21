// https://cses.fi/problemset/task/1674

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int find_sub(int i, vector<vector<int> > &v, vector<int> &sub)
{
    if(sub[i] != -1)
        return sub[i];
    
    if(v[i].size() == 0)
        return 0;
        
    int ans = 0;
    for(auto& next : v[i])
        ans += find_sub(next, v, sub) + 1;

    return sub[i] = ans;
}

int main()
{
	int n, boss;
    cin >> n;
    vector<vector<int> > v(n+1);
    for(int i = 2; i <= n; ++i)
    {
        cin >> boss;
        v[boss].push_back(i);
    }

    vector<int> sub(n+1, -1);
    for(int i = 1; i <= n; ++i)
    {
        sub[i] = find_sub(i, v, sub);
        cout << sub[i] << ' ';
    }
}
