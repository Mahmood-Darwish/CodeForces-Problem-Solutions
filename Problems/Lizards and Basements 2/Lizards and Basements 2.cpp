#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;
typedef long long ll;

ll max(ll num1, ll num2)
{
	if (num1 >= num2)return num1;
	return num2;
}

ll min(ll num1, ll num2)
{
	if (num1 <= num2)return num1;
	return num2;
}

ll n, a[20], dp[20][20][20][20], inf = 9999999999 , b , c , ans;

ll DP(ll pos, ll num1, ll num2, ll num3)
{
	num1 = max(num1, 0);
	num2 = max(num2, 0);
	num3 = max(num3, 0);
	if (pos == n) {
		if (num1 + num2 == 0)
			return 0;
		return inf;
	}
	ll &cur = dp[pos][num1][num2][num3];
	if (cur != -1)return cur;
	if (num1 == 0 && num2 == 0 && num3 == 0) {
		cur = DP(pos + 1, 0, 0, a[pos + 2]);
		return cur;
	}
	cur = DP(pos, num1 - b, num2 - c, num3 - b) + 1;
	if (num1 == 0) {
		cur = min(cur, DP(pos + 1, num2, num3, a[pos + 2]));
	}
	return cur;
}

void find_sol(ll pos, ll num1, ll num2, ll num3)
{
	num1 = max(num1, 0);
	num2 = max(num2, 0);
	num3 = max(num3, 0);
	if (pos == n) {
		return;
	}
	if (num1 == 0 && num2 == 0 && num3 == 0 && DP(pos + 1 , 0 , 0 , a[pos + 2]) == ans) {
		find_sol(pos + 1, 0, 0, a[pos + 2]);
		return;
	}
	if (DP(pos, num1 - b, num2 - c, num3 - b) + 1 == ans) {
		ans--;
		printf("%I64d ", pos);
		find_sol(pos, num1 - b, num2 - c, num3 - b);
		return;
	}
	if (num1 == 0 && DP(pos + 1, num2, num3, a[pos + 2]) == ans) {
		find_sol(pos + 1, num2, num3, a[pos + 2]);
		return;
	}
	return;
}

int main()
{
	memset(dp, -1, sizeof(dp));
	scanf("%d %d %d", &n, &c, &b);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		a[i]++;
	}
	ans = DP(2, a[1], a[2], a[3]);
	printf("%I64d\n",ans);
	find_sol(2, a[1], a[2], a[3]);
	return 0;
}
// this is my first code I've done using VC yay!!!