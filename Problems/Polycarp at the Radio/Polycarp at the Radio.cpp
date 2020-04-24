#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int n, q, sum;
int a[10000];
int b[10000];
map < int, int > m;


int main()
{
	cin >> n >> q;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		b[i] = a[i];
		m[a[i]]++;
	}
	for (int i = 0; i < n; i++) {
		if (a[i] > q) {
			for (int j = 1; j <= q; j++) {
				if (m[j] < n / q) {
					m[j]++;
					b[i] = j;
					break;
				}
			}
			continue;
		}
		if (m[a[i]] > n / q) {
			for (int j = 1; j <= q; j++) {
				if (m[j] < n / q) {
					m[j]++;
					m[a[i]]--;
					b[i] = j;
					break;
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		if (b[i] != a[i])
			sum++;
	}
	cout << n / q << ' ' << sum << endl;
	for (int i = 0; i < n; i++)
		cout << b[i] << ' ';
	return 0;
}