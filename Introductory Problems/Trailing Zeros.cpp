// https://cses.fi/problemset/result/3967951/

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
	ll n;
	cin >> n;

	ll factor = 5, ans = 0;
	while(factor <= n)
	{
		ans += n / factor;
		factor *= 5;
	}

	cout << ans << endl;
}
