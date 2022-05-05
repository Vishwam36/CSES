// https://cses.fi/problemset/task/1092

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ll n;
    cin >> n;
    ll sum = ((n)*(n+1))/2;
    if(n <= 2 || sum % 2 == 1)
    {
        cout << "NO\n";
    }
    else
    {
        int cnt = 0;
        sum /= 2;
        vector<int> v(n+1, 1);
        while(sum)
        {
            if(sum >= n)
            {
                sum -= n;
                v[n] = 0;
                n--;
            }
            else
            {
                v[sum] = 0;
                sum = 0;
            }
            ++cnt;
        }
        cout << "YES\n";
        cout << cnt << endl;
        for(int i = 1; i < v.size(); ++i)
            if(v[i] == 0)
                cout << i << ' ';
        cout << endl;
        cout << v.size()-cnt-1 << endl;
        for(int i = 1; i < v.size(); ++i)
            if(v[i])
                cout << i << ' ';
        cout << endl;
    }
}
