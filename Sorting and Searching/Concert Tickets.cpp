// https://cses.fi/problemset/task/1091

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
	int n, m;
    cin >> n >> m;
    multiset<int> s;
    for(int i = 0; i < n; ++i)
    {
        int h;
        cin >> h;
        s.insert(h);
    }
    
    for(int i = 0; i < m; ++i)
    {
        int t;
        cin >> t;
        auto it = s.lower_bound(t);
        
        if(s.size() == 0)
        {
            cout << "-1" << endl;
            continue;
        }
        if(it == s.begin())
        {
            if(*it == t)
            {
                cout << t << endl;
                s.erase(it);
            }
            else
            {
                cout << "-1" << endl;
            }
        }
        else
        {
            if(*it == t)
            {
                cout << t << endl;
                s.erase(it);
            }
            else
            {
                it--;
                cout << *it << endl;
                s.erase(it);
            }
        }
    }
}
