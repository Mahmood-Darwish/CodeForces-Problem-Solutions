#include <bits/stdc++.h>
#define F first
#define S second
#define pb push_back
#define MEM(a,b) memset(a,b,sizeof(a))
#define SF(x) scanf("%d",&x)

using namespace std;
typedef long long ll;

int n, m, k, u, v, colo, sum;
bool arr[1007][1007];
bool vis[1007];
vector < int > V[1007];
int gov[1007];

void col(int node, int par = -1)
{
    if(vis[node])return;
    vis[node] = true;
    V[colo].pb(node);
    for(int i = 0 ; i <= n ; i++){
        if(i == par)continue;
        if(arr[i][node])
            col(i, node);
    }
}

int main()
{
    cin >> n >> m >> k;
    for(int i = 0 ; i < k ; i++)
        SF(gov[i]);
    for(int i = 0 ; i < m ; i++){
        SF(u);
        SF(v);
        arr[u][v] = arr[v][u] = true;
    }
    for(int i = 0 ; i < k ; i++){
        col(gov[i]);
        colo++;
    }
    ll temp = 0, mx = -1;
    for(int i = 0 ; i <= n ; i++){
        if(V[i].size() > mx){
            mx = V[i].size();
            temp = i;
        }
    }
    for(int i = 1 ; i <= n ; i++){
        if(!vis[i]){
            V[temp].pb(i);
        }
    }
    for(int i = 0 ; i < colo ; i++){
        for(int j = 0 ; j < V[i].size() ; j++){
            for(int k = j + 1 ; k < V[i].size() ; k++){
                if(!arr[V[i][j]][V[i][k]]){
                    arr[V[i][j]][V[i][k]] = arr[V[i][k]][V[i][j]] = true;
                    sum++;
                }
            }
        }
    }

    cout << sum << endl;
    return 0;
}