// https://cses.fi/problemset/task/1755

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
	string s;
    cin >> s;
    vector<int> v(26, 0);
    for(int i = 0; i < s.size(); ++i)
        v[s[i]-'A']++;
    
    int oddFreq = 0;
    for(int i = 0; i < v.size(); ++i)
        if(v[i] % 2 == 1)
            oddFreq++;
    
    if(oddFreq > 1)
    {
        cout << "NO SOLUTION\n";
    }
    else
    {
        int l = 0, r = s.size()-1;
        for(int i = 0; i < v.size(); ++i)
        {
            if(v[i] % 2 == 0)
            {
                int j = v[i]/2;
                while(j--)
                    s[l++] = 'A' + i;
                
                j = v[i]/2;
                while(j--)
                    s[r--] = 'A' + i;
            }
            else
            {
                int mid = s.size()/2;
                s[mid] = 'A' + i;
                int j = v[i]/2, k = mid-1;
                while(j--)
                    s[k--] = 'A' + i;
                
                j = v[i]/2, k = mid+1;
                while(j--)
                    s[k++] = 'A' + i;
            }
        }
        cout << s << endl;
    }
}
