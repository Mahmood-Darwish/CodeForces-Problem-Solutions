#include <iostream>
#include <vector>

using namespace std;

long long n, k, num, temp, ans, temp2;
vector < long long > a[100009];

int main()
{
	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		cin >> temp;
		while (temp--) {
			cin >> num;
			if (num == 1) temp2 = i;
			a[i].push_back(num);
		}
	}
	num = 1;
	for (int i = 0; i < k; i++) {
		if (i == temp2) {
			for (int j = 1; j < a[i].size(); j++) {
				if (a[i][j] - 1 == a[i][j - 1]) {
					num++;
				}
				else {
					ans += a[i].size() - num;
					break;
				}
			}
			continue;
		}
		ans += a[i].size() - 1;
	}
	cout << ans + (n - num) << '\n';
	return 0;
}