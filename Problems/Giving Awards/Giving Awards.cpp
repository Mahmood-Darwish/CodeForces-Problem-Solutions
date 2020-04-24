#include <iostream>
#include <vector>
#include <queue>
#include <stdio.h>

#define pb push_back
#define SF(x) scanf("%d",&x)

using namespace std;

int n, m, u, v;
vector < int > adj[1000000], sol;
bool vis[1000000];

void DFS(int node, int par = -1)
{
    if(vis[node])
       return;
    vis[node] = true;
    for(auto cur : adj[node])
        if(cur != par)
            DFS(cur, node);
    sol.push_back(node);
}

int main()
{
    cin >> n >> m;
    while(m--)
    {
        SF(u);
        SF(v);
        adj[u].pb(v);
    }
    for(int i = 1 ; i <= n ; i++)
        if(!vis[i])
            DFS(i);
    if(sol.size() != n)
        cout << "-1\n";
    else{
        for(auto cur : sol)
            cout << cur << ' ';
        cout << endl;
    }
    return 0;
}