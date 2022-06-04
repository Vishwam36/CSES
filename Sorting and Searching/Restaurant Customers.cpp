// https://cses.fi/problemset/task/1619/

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int find_parent(int a, vector<int> &par)
{
    if(par[a] == a)
        return a;
    
    int p = find_parent(par[a], par);
    return par[a] = p;
}

void unite(int a, int b, vector<int> &par)
{
    int pa = find_parent(a, par);
    int pb = find_parent(b, par);

    if(pa == pb)
        return;
    
    par[pb] = pa;
}

void dfs(int curr, vector<int> adj[], vector<bool> &vis, vector<int> &par)
{
    for(auto& next : adj[curr])
    {
        if(!vis[next])
        {
            vis[next] = 1;
            unite(curr, next, par);
            dfs(next, adj, vis, par);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    vector<pair<int, int> > v;
	int n;
    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        int in, out;
        cin >> in >> out;
        v.push_back({in, 0});
        v.push_back({out, 1});
    }

    sort(v.begin(), v.end());
    int cnt = 0;
    int ans = 0;
    for(int i = 0; i < v.size(); ++i)
    {
        if(v[i].second == 0)
            cnt++;
        else
            cnt--;
        
        ans = max(ans, cnt);
    }
    cout << ans << endl;
}
