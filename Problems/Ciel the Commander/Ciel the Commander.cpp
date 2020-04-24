#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

int subtree[100100];
vector < int > adj[100100];
int par[100100];
bool blocked[100100];
char ans[100100];
int n, a, b;

int DFS(int node, int p)
{
    subtree[node] = 1, par[node] = p;
    for(unsigned int i = 0 ; i < adj[node].size() ; i++){
        int x = adj[node][i];
        if(x == p || blocked[x]) continue;
        subtree[node] += DFS(x, node);
    }
    return subtree[node];
}

void create(int u, int letter) {
    DFS(u, -1);
    int centroid = u, best = subtree[u];
    queue < int > q;
    q.push(u);
    while(!q.empty()) {
        int uu = q.front();
        q.pop();
        int sizee = subtree[u] - subtree[uu];
        for(auto v : adj[uu]) {
            if (par[uu] == v || blocked[v]) continue;
            sizee = max(sizee, subtree[v]);
            q.push(v);
        }
        if (sizee < best) {
            best = sizee, centroid = uu;
        }
    }
    blocked[centroid] = true;
    ans[centroid] = (char)(letter);
    for(auto v : adj[centroid]) {
        if (blocked[v]) continue;
        create(v, letter + 1);
    }
    return;
}

int main()
{
    cin >> n;
    for(int i = 1 ; i < n ; i++){
        scanf("%d %d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    create(1, (int)'A');
    for(int i = 1 ; i <= n ; i++){
        printf("%c ", ans[i]);
    }
    return 0;
}