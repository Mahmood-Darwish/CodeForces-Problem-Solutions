#include <iostream>
#include <queue>

using namespace std;

bool vis[100000];

int BFS(int n, int m)
{
	queue < pair < int, int > > q;
	q.push({ n, 0 });
	while (!q.empty()) {
		pair < int, int > u = q.front();
		q.pop();
		if (vis[u.first])continue;
		vis[u.first] = true;
		if (u.first == m) {
			return u.second;
		}
		if (u.first - 1 > -1) {
			q.push({ u.first - 1, u.second + 1 });
		}
		if (u.first * 2 <= m * 2) {
			q.push({ u.first * 2, u.second + 1 });
		}
	}
}

int main()
{
	int n, m;
	cin >> n >> m;
	cout << BFS(n, m) << '\n';
	return 0;
}