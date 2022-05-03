// link : https://cses.fi/problemset/task/1072/
// ref : https://www.youtube.com/watch?v=12Y8OrlRS3U

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ll n;
    cin >> n;
    for(ll k = 1; k <= n; ++k)
        cout << ((k*k)*(k*k-1))/2 - (k-1)*(k-2)*2 - (k-1)*(k-2)*2 << endl; // each 2*3 box and each 3*2 box will have 2 invalid arrangements 
}
