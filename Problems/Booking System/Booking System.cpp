#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;
typedef long long ll;

pair < ll, ll > arr[5007];
pair < ll, ll > table[5007];
ll n, k, dp[5007][5007], num, temp;
pair < pair < ll, ll >, ll > req[5007];

ll DP(ll pos, ll order)
{
	if (pos == k || order == n)return 0;
	ll &cur = dp[pos][order];
	if (cur != -1)return cur;
	cur = max(DP(pos + 1, order), DP(pos, order + 1));
	if (table[pos].first >= req[order].first.first)
		cur = max(cur, DP(pos + 1, order + 1) + req[order].first.second);
	return cur;
}

void find_sol(ll pos, ll order, ll ans)
{
	if (pos == k || order == n) return;
	if (DP(pos + 1, order) == ans) {
		find_sol(pos + 1, order, ans);
		return;
	}
	if (DP(pos, order + 1) == ans) {
		find_sol(pos, order + 1, ans);
		return;
	}
	if (table[pos].first >= req[order].first.first && ans == DP(pos + 1, order + 1) + req[order].first.second) {
		num++;
		arr[temp].first = req[order].second;
		arr[temp].second = table[pos].second;
		temp++;
		find_sol(pos + 1, order + 1, ans - req[order].first.second);
		return;
	}
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> req[i].first.first >> req[i].first.second;
		req[i].second = i;
	}
	sort(req, req + n);
	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> table[i].first;
		table[i].second = i;
	}
	sort(table, table + k);
	memset(dp, -1, sizeof(dp));
	ll ans = DP(0, 0);
	find_sol(0, 0, ans);
	cout << num << ' ' << ans << '\n';
	for (int i = 0; i < num; i++) {
		cout << arr[i].first + 1 << ' ' << arr[i].second + 1 << '\n';
	}
	return 0;
}