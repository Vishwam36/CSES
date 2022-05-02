// Link : https://cses.fi/problemset/task/1069/

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    string s;
    cin >> s;
    
    int ans = 0, i = 0, n = s.size();
    while(i < n)
    {
        int j = i;
        while(j < n && s[i] == s[j])
            ++j;
        
        ans = max(ans, j-i);
        i = j;
    }

    cout << ans;
}
