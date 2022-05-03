// https://cses.fi/problemset/task/1070/

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    int n;
    cin >> n;
    if(n == 2 || n == 3)
        cout << "NO SOLUTION\n";
    else
    {
        int odd = (n % 2 == 1 ? n : n-1);
        while(odd > 0)
        {
            cout << odd << ' ';
            odd -= 2;
        }
        int even = (n % 2 == 0 ? n : n-1);
        while(even > 0)
        {
            cout << even << ' ';
            even -= 2;
        }
    }
}
