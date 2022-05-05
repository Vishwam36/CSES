// https://cses.fi/problemset/task/1192

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int di[4] = {-1, 1, 0, 0};
int dj[4] = {0, 0, -1, 1};
int n, m;

bool valid(int i, int j)
{
    return i >= 0 && j >= 0 && i < n && j < m;
}

void bfs(int x, int y, vector<string> &v, vector<vector<bool> > &vis)
{
    queue<pair<int, int> > q;
    q.push({x, y});
    vis[x][y] = true;

    while(!q.empty())
    {
        auto p = q.front(); q.pop();
        int i = p.first;
        int j = p.second;

        for(int k = 0; k < 4; ++k)
        {
            int ni = i + di[k];
            int nj = j + dj[k];

            if(valid(ni, nj) && v[ni][nj] == '.' && vis[ni][nj] == false)
            {
                q.push({ni, nj});
                vis[ni][nj] = true;
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    vector<string> v(n, string(m, ' '));
    for(int i = 0; i < n; ++i)
        cin >> v[i];
    
    int cnt = 0;
    vector<vector<bool> > vis(n, vector<bool>(m, false));
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            if(v[i][j] == '.' && vis[i][j] == false)
            {
                bfs(i, j, v, vis);
                ++cnt;
            }
    
    cout << cnt << endl;
}
