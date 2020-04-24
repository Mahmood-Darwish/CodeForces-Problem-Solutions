#include <iostream>
#include <string.h>

using namespace std;
typedef long long ll;

ll dp[(1 << 19)][20], a[20], b[20][20], n, m, k;

ll DP(ll mask, ll last_dish)
{
	if (__builtin_popcount(mask) == m)return 0;
	ll &cur = dp[mask][last_dish];
	if (cur != -1)return cur;
	cur = 0;
	for (int i = 0; i < n; i++) {
		if (!(mask &(1 << i))) {
			cur = max(1LL * DP(mask | (1 << i), i) + a[i] + b[last_dish][i],1LL * cur);
		}
	}
	return cur;
}


int main()
{
	memset(dp, -1, sizeof(dp));
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	ll x, y, c;
	for (int i = 0; i < k; i++) {
		cin >> x >> y >> c;
		x--;
		y--;
		b[x][y] = c;
	}
	cout << DP(0, 19) << '\n';
	return 0;
}