#include <iostream>
#define min(a,b)    (((a) < (b)) ? (a) : (b))
using namespace std;

int n, a, b, c, k;
int arr[350][350], arr2[350][350];
long long sum;

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
			arr2[i][j] = arr[i][j];
		}
	}
	cin >> k;
	while (k--) {
		cin >> a >> b >> c;
		if (c < arr2[a][b]) {
			arr2[a][b] = c;
			arr2[b][a] = c;
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				arr2[i][j] = min(arr2[i][j], arr2[i][a] + arr2[a][b] + arr2[j][b]);
				arr2[i][j] = min(arr2[i][j], arr2[i][b] + arr2[a][b] + arr2[j][a]);
				sum += arr2[i][j];
			}
		}
		sum /= 2;
		cout << sum << ' ';
		sum = 0;
	}
	return 0;
}