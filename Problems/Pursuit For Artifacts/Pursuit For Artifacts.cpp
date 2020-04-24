#include <iostream>
#include <string.h>
#include <stdio.h>
#include <vector>

#define F first
#define S second

using namespace std;

int low[300010], depth[300010];
vector < pair < int , pair < bool , bool > > > adj[300010];
vector < pair < int , bool > > adj2[300010];
int n, m, timer, ans, s, t, u, v, c;
int val[300010], temp;
bool arr[300010];
bool vis[300010];

void bridges(int x, int p)
{
	depth[x] = low[x] = ++timer;
	for (unsigned int nxt = 0 ; nxt < adj[x].size() ; nxt++) {
		if (adj[x][nxt].F == p) continue;
		if (depth[adj[x][nxt].F] == -1) {
			bridges(adj[x][nxt].F, x);
			low[x] = min(low[x], low[adj[x][nxt].F]);
			if (low[adj[x][nxt].F] > depth[x]) {
                adj[x][nxt].S.S = true;
                for(unsigned int cur = 0 ; cur < adj[adj[x][nxt].F].size() ; cur++){
                    if(adj[adj[x][nxt].F][cur].F == x){
                        //cout << adj[x][nxt].F << ' ' << x << endl;
                        adj[adj[x][nxt].F][cur].S.S = true;
                        break;
                    }
                }
                //cout << x << ' ' << adj[x][nxt].F << endl;
			}
		}
		else low[x] = min(low[x], depth[adj[x][nxt].F]);
	}
}

bool comp(int node, int par)
{
    vis[node] = true;
    if(val[node]) return false;
    bool art = false;
    val[node] = temp;
    for(auto cur : adj[node]){
        if(cur.F == par || cur.S.S) continue;
        art = max(art, cur.S.F);
        art = max(art, comp(cur.F, node));
    }
    return art;
}

void comp2(int node, int par)
{
    if(vis[node]) return;
    vis[node] = true;
    for(auto cur : adj[node]){
        if(cur.F == par) continue;
        if(cur.S.S){
            adj2[val[node]].push_back({val[cur.F] ,cur.S.F});
        }
        else comp2(cur.F, node);
    }
    return;
}

void DFS(int node, int par, bool art)
{
    art = max(art, arr[node]);
    if(art && node == val[t]){
        ans = 1;
        return;
    }
    for(auto cur : adj2[node]){
        if(cur.F == par) continue;
        DFS(cur.F, node, max(art, cur.S));
    }
    return;
}

int main()
{
    cin >> n >> m;
    while(m--){
        scanf("%d %d %d", &u, &v, &c);
        adj[u].push_back({v, {c, 0}});
        adj[v].push_back({u, {c, 0}});

    }
    cin >> s >> t;
    memset(low, -1, sizeof(low));
    memset(depth, -1, sizeof(depth));
    bridges(1, -1);
    for(int i = 1 ; i <= n ; i++){
        if(!vis[i]){
            temp++;
            arr[temp] = comp(i, -1);
        }
    }
    memset(vis, 0, sizeof(vis));
    for(int i = 1 ; i <= n ; i++){
        if(!vis[i]){
            comp2(i, -1);
        }
    }
    /*
    for(int i = 1 ; i <= n ; i++){
        cout << i << ":\n";
        for(auto cur : adj[i]){
            cout << cur.F << ' ' << cur.S.F << ' ' << cur.S.S << endl;
        }
        cout << endl;
    }
    for(int i = 1 ; i <= temp ; i++){
        cout << i << ' ' << arr[i] << ":\n";
        for(auto cur : adj2[i]){
            cout << cur.F << ' ' << cur.S << endl;
        }
        cout << endl;
    }
    */
    DFS(val[s], -1, 0);
    if(ans){
        cout << "YES\n";
    }
    else{
        cout << "NO\n";
    }
    return 0;
}