// https://cses.fi/problemset/task/1629/

#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
const ll mod = 1e9 + 7;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
	int n;
    cin >> n;
    vector<pair<int, int> > v(n);
    for(int i = 0 ; i < n; ++i)
        cin >> v[i].first >> v[i].second;
    
    sort(v.begin(), v.end(), [](auto& p, auto& q){
        return p.second < q.second;
    });

    int cnt = 0;
    int start = -1, end = -1;
    for(int i = 0; i < n;)
    {
        while(i < n && v[i].first < end)
            ++i;

        if(i == n)
            break;
        
        ++cnt;
        end = v[i].second;
        ++i;
    }
    cout << cnt << endl;
}
