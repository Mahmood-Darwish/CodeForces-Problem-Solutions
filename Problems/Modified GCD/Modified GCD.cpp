#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int a, b, q, low, high;
set < int > arr;

int GCD(int a, int b)
{
	if (!b)return a;
	return GCD(b, a%b);
}



int main()
{
	cin >> a >> b;
	int g = GCD(a, b);
	for (int i = 1; i * i <= g; i++) {
		if (g % i == 0) {
			arr.insert(i);
			arr.insert(g / i);
		}
	}
	cin >> q;
	while (q--)  {
		cin >> low >> high;
		if (low > high) {
			swap(low, high);
		}
		auto it = arr.upper_bound(high);
		it--;
		if ((*it) >= low && (*it) <= high)
			cout << (*it) << endl;
		else cout << -1 << endl;
	}
	return 0;
}