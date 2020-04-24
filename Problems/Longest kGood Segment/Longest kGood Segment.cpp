#include <iostream>
#include <map>

using namespace std;
typedef long long ll;
map < ll, ll > m;
ll n, k, a[1000007], sum, l, r, ans = -1, j;

int main()
{
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		scanf("%I64d", &a[i]);
	for (int i = 0; i < n; i++) {
		m[a[i]]++;
		if (m[a[i]] == 1)
			sum++;
		if (sum == k + 1){
			if ((i - 1) - j > ans) {
				ans = (i - 1) - j;
				l = j;
				r = i - 1;
			}
			for (; j <= i; j++) {
				m[a[j]]--;
				if (m[a[j]] == 0) {
					sum--;
					j++;
					break;
				}
			}
		}
	}
	if (sum <= k) {
		if ((n - 1) - j > ans) {
			ans = (n - 1) - j;
			l = j;
			r = n - 1;
		}
	}
	cout << l + 1 << ' ' << r + 1 << '\n';
	return 0;
}