#include <iostream>
#include <string.h>
#include <vector>
#include <queue>

#define F first
#define S second

using namespace std;

int n, u, v;
vector < pair < int , int > > roads;
vector < int > V[205];
bool vis[205], adj[205][205];


int DFS(int node, int par)
{
    int sum = 0;
    for(int i = 1 ; i <= n ; i++){
        if(i != par && adj[i][node]){
            sum = max(sum, DFS(i, node) + 1);
        }
    }
    return sum;
}

int Find_ans(int node)
{
    int len = 0, start = 1;
    queue < pair < int , int > > Q;
    Q.push({node, 0});
    vis[node] = true;
    while(!Q.empty()){
        pair < int , int > U = Q.front();
        Q.pop();
        if(U.S > len)
            start = U.F;
        vis[U.F] = true;
        for(int i = 1 ; i <= n ; i++){
            if(!vis[i] && adj[U.F][i])
                Q.push({i, U.S + 1});
        }
    }
    //cout << start << endl;
    return DFS(start, -1);
}

int main()
{
    cin >> n;
    int temp = n - 1;
    while(temp--){
        cin >> u >> v;
        adj[u][v] = true;
        adj[v][u] = true;
        V[u].push_back(v);
        V[v].push_back(u);
    }
    for(int i = 0 ; i <= n ; i ++){
        for(int j = i + 1 ; j <= n ; j++){
            if(V[i].size() > 1 && V[j].size() > 1 && adj[i][j]){
                roads.push_back({i, j});
            }
        }
    }
    int ans = 0;
    for(unsigned int i = 0 ; i < roads.size() ; i++){
        adj[roads[i].F][roads[i].S] = false;
        adj[roads[i].S][roads[i].F] = false;
        int ans1 = 0, ans2 = 0;
        //cout << roads[i].F << ' ' << roads[i].S << endl;
        for(int i = 1 ; i <= n ; i++){
            if(!vis[i]){
                //cout << i << endl;
                if(!ans1)
                    ans1 = Find_ans(i);
                else
                    ans2 = Find_ans(i);
            }
            ans = max(ans, ans1 * ans2);
            //cout << ans << endl;
        }
        memset(vis, 0, sizeof(vis));
        adj[roads[i].F][roads[i].S] = true;
        adj[roads[i].S][roads[i].F] = true;
    }
    cout << ans << endl;
    return 0;
}