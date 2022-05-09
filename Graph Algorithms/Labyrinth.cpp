// https://cses.fi/problemset/task/1193

// REF : https://www.youtube.com/watch?v=s0DnJ0CdNEE

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int n, m;
int xa, ya, xb, yb;
int di[4] = {0, 0, -1, 1};
int dj[4] = {-1, 1, 0, 0};
vector<string> v;
vector<vector<bool> > vis;
vector<vector<pair<int, int> > > par;

int valid(int i, int j)
{
    return i >= 0 && j >= 0 && i < n && j < m;
}

bool isPath()
{
    queue<pair<int, int> > q;
    q.push({xa, ya});
    vis[xa][ya] = 1;
    par[xa][ya] = {-1, -1};

    while(!q.empty())
    {
        auto p = q.front(); q.pop();
        int i = p.first, j = p.second;

        if(i == xb && j == yb)
            return true;

        for(int k = 0; k < 4; ++k)
        {
            int ni = i + di[k];
            int nj = j + dj[k];

            if(valid(ni, nj) && !vis[ni][nj] && (v[ni][nj] == '.' || v[ni][nj] == 'B'))
            {
                vis[ni][nj] = 1;
                par[ni][nj] = {i, j};
                q.push({ni, nj});
            }
        }
    }
    return false;
}

string getPath()
{
    string path;
    int i = xb, j = yb, pi, pj;
    while(1)
    {
        auto p = par[i][j];
        if(p == pair<int, int>({-1, -1}))
            break;
        
        pi = p.first, pj = p.second;
        if(pi == i)
        {
            if(pj == j-1)
                path.push_back('R');
            else
                path.push_back('L');
        }
        else
        {
            if(pi == i-1)
                path.push_back('D');
            else
                path.push_back('U');
        }

        i = pi, j = pj;
    }

    reverse(path.begin(), path.end());
    return path;
}

int main()
{
    cin >> n >> m;
    v.resize(n);
    vis.resize(n, vector<bool>(m, false));
    par.resize(n, vector<pair<int, int> >(m));

    for(int i = 0; i < n; ++i)
        cin >> v[i];
    
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
        {
            if(v[i][j] == 'A')
            {
                xa = i;
                ya = j;
            }
            else if(v[i][j] == 'B')
            {
                xb = i;
                yb = j;
            }
        }
    
    if(isPath())
    {
        cout << "YES\n";
        string path = getPath();
        cout << path.size() << endl;
        cout << path << endl;
    }
    else
    {
        cout << "NO\n";
    }
}
