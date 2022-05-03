// https://cses.fi/problemset/task/1071/

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ll t, x, y;
    cin >> t;
    while(t--)
    {
        cin >> y >> x;
        if(y >= x)
        {
            if(y % 2 == 0)
            {
                ll pre = (max(y,x))*(max(y,x));
                cout << pre - x + 1 << endl;
            }
            else
            {
                ll pre = (max(y,x)-1)*(max(y,x)-1);
                cout << pre + x << endl;
            }
        }
        else
        {
            if(x % 2 == 0)
            {
                ll pre = (max(y,x)-1)*(max(y,x)-1);
                cout << pre + y << endl;
            }
            else
            {
                ll pre = (max(y,x))*(max(y,x));
                cout << pre - y + 1 << endl;
            }
        }
    }
}
