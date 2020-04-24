#include <iostream>
#include <string.h>
#include <vector>
#include <queue>

using namespace std;

int n, q, a, b;
int dis[100005];
int dp[30][100005];
int lvl[100005];
int col[100005];
vector < int > adj[100005];
int INF = (1 << 29);
queue < pair < int , int > > Q;

struct Query{
    int node, type;
}query[100005];

void DFS(int node, int par, int depth)
{
    lvl[node] = depth;
    for(auto x: adj[node]){
        if(x == par) continue;
        dp[0][x] = node;
        DFS(x, node, depth + 1);
    }
}

void Build()
{
    int x;
    for(int i = 1 ; i <= 16 ; i++){
        for(int j = 1; j <= n ; j++){
            x = dp[i - 1][j];
            x = dp[i - 1][x];
            dp[i][j] = x;
        }
    }
}

void BFS(vector < int > &vec)
{
    for(unsigned int i = 0 ; i < vec.size() ; i++){
        Q.push({vec[i], 0});
    }
    pair < int, int > u;
    while(!Q.empty()){
        u = Q.front();
        Q.pop();
        for(auto x : adj[u.first]){
            if(dis[x] <= u.second + 1) continue;
            dis[x] = u.second + 1;
            Q.push({x, u.second + 1});
        }
    }
    return;
}

int LCA(int x, int y)
{
    if(lvl[x] < lvl[y])
        swap(x, y);
    int temp_x = x, temp_y = y;
    for(int i = 16 ; i >= 0 ; i--){
        if(lvl[dp[i][x]] >= lvl[y] && dp[i][x] != 0){
            x = dp[i][x];
        }
    }
    if(x == y){
        return (lvl[temp_x] - lvl[temp_y]);
    }
    for(int i = 16 ; i >= 0 ; i--){
        if(dp[i][x] != dp[i][y] && dp[i][x] != 0 && dp[i][y] != 0){
            x = dp[i][x];
            y = dp[i][y];
        }
    }
    x = dp[0][x], y = dp[0][y];
    return (lvl[temp_x] + lvl[temp_y] - (2 * lvl[x]));
}

int main()
{
    cin >> n >> q;
    dis[1] = 0;
    col[1] = 1;
    for(int i = 2 ; i <= n ; i++)
        dis[i] = INF;
    for(int i = 1 ; i < n ; i++){
        scanf("%d %d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i = 1 ; i <= q ; i++){
        scanf("%d %d", &a, &b);
        query[i].type = a;
        query[i].node = b;
    }
    DFS(1, -1, 1);
    Build();
    vector < int > temp;
    temp.push_back(1);
    for(int i = 1 ; i <= q ; i++){
        if(query[i].type == 1){
            temp.push_back(query[i].node);
            col[query[i].node] = 1;
        }
        else{
            if(col[query[i].node]){
                printf("0\n");
                continue;
            }
            int ans = dis[query[i].node];
            for(unsigned int j = 0 ; j < temp.size() ; j++){
                ans = min(ans, LCA(query[i].node, temp[j]));
            }
            printf("%d\n", ans);
        }
        if(temp.size() >= 100){
            BFS(temp);
            temp.clear();
        }
    }
    return 0;
}