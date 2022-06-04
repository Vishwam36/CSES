// https://cses.fi/problemset/task/1666/

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
    
	int n, m;
    cin >> n >> m;
    vector<int> adj[n+1];
    for(int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> vis(n+1);
    vector<int> par(n+1);
    vector<int> comps;
    for(int i = 1; i <= n; ++i)
        par[i] = i;

    for(int i = 1; i <= n; ++i)
    {
        if(!vis[i])
        {
            vis[i] = 1;
            comps.push_back(i);
            dfs(i, adj, vis, par);
        }
    }

    cout << comps.size()-1 << endl;
    for(int i = 1; i < comps.size(); ++i)
        cout << comps[i-1] << ' ' << comps[i] << endl;
}
