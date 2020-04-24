#include <iostream>
#include <string>

using namespace std;

int ans, sum;

int max(int num1, int num2)
{
	if (num1 > num2)return num1;
	return num2;
}

int main()
{
	int n;
	string s;
	cin >> n;
	cin >> s;
	for (int i = 0; i < n; i++) {
		if (s[i] == '(') {
			for (int j = i; j < n; j++) {
				if (s[j] == ')') {
					i = j;
					break;
				}
			}
			continue;
		}
		if (isalpha(s[i])) {
			for (int j = i + 1; j <= n; j++) {
				ans = max(ans, (j - i));
				if (j == n) {
					break;
				}
				if (!isalpha(s[j])) {
					break;
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		if (s[i] == '(') {
			for (int j = i + 1; j < n; j++) {
				if (s[j] == ')')  {
					i = j;
					break;
				}
				while (isalpha(s[j])) {
					if (!isalpha(s[j + 1])) {
						sum++;
						i = j;
						break;
					}
					j++;
				}
			}
		}
	}
	cout << ans << ' ' << sum << endl;
	return 0;
}