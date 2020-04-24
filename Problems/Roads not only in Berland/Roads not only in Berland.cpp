#include <bits/stdc++.h>

using namespace std;

vector < int > adj[1007];
bool vis[1007], vis2[1007][1007];
vector < pair < int, int > > sol, cycle;

void cy(int pos, int dad)
{
	if (vis[pos]) {
		if (!vis2[dad][pos]) {
			vis2[dad][pos] = true;
			vis2[pos][dad] = true;
			cycle.push_back({ dad, pos });
		}
		return;
	}
	vis[pos] = true;
	for (auto cur : adj[pos]) {
		if (cur == dad)continue;
		cy(cur, pos);
	}
	return;
}

void DFS(int pos, int par)
{
	if (vis[pos])return;
	vis[pos] = true;
	for (auto cur : adj[pos]) {
		if (cur == par)continue;
		DFS(cur, pos);
	}
	return;
}

int n, a, b, ans;

int main()
{
	cin >> n;
	for (int i = 1; i <= n - 1; i++) {
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			cy(i, -1);
		}
	}
	memset(vis, 0, sizeof(vis));
	DFS(1, -1);
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			ans++;
			DFS(i, -1);
			sol.push_back({ 1, i });
		}
	}
	cout << ans << '\n';
	for (int i = 0; i < ans; i++) {
		cout << cycle[i].first << ' ' << cycle[i].second << ' ' << sol[i].first << ' ' << sol[i].second << '\n';
	}
	return 0;
}