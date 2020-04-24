#include <iostream>
#include <vector>
#include <map>

using namespace std;

map < int, int > vis;
vector < int > sol;
int n, a[1000007];
bool sure = true;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		if (vis[a[i]] == 1) {
			sol.push_back(i);
			vis.clear();
			sure = true;
			continue;
		}
		vis[a[i]] = 1;
		if (sure) {
			sol.push_back(i);
		}
		sure = false;
	}
	if (sol.size() / 2 == 0) {
		cout << -1 << '\n';
		return 0;
	}
	if (!sure) {
		sol.pop_back();
		sol.pop_back();
		sol.push_back(n - 1);
	}
	if (sol[sol.size() - 1] != n - 1)
		sol.push_back(n - 1);
	cout << sol.size() / 2 << '\n';
	int k = 0;
	for (int i = 0; i < sol.size() / 2 ; i++) {
		cout << sol[k] + 1 << ' ' << sol[k + 1] + 1 << '\n';
		k += 2;
	}
	return 0;
}