#include <iostream>

using namespace std;

long long n, x, y, sum, sum2, a[1000005];

int main()
{
	cin >> n >> x >> y;
	a[0] = max(y - (n - 1),1LL);
	sum = a[0];
	sum2 = a[0] * a[0];
	for (int i = 1; i < n; i++) {
		a[i] = 1;
		sum += a[i];
		sum2 += a[i] * a[i];
	}
	if (sum <= y && sum2 >= x) {
		for (int i = 0; i < n; i++)
			cout << a[i] << '\n';
		return 0;
	}
	else {
		cout << -1;
		return 0;
	}
}