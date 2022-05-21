// https://cses.fi/problemset/task/1754

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
	ll t, a, b;
    cin >> t;
    while(t--)
    {
        cin >> a >> b;
        if(a < b)
            swap(a, b);
        
        if(a <= 2*b && (a+b) % 3 == 0)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}
