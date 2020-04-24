#include <iostream>
#include <algorithm>
#include <vector>
#define pb push_back
using namespace std;

int n, m, color = 1, a[1001000], u, v;
bool vis[1001000];
vector < int > adj[1001000];
vector < pair < int , int > > com[1001000];
void DFS(int node)
{
    if(vis[node])
        return;
    vis[node] = true;
    com[color].pb({a[node], node});
    for(auto Cur : adj[node]){
        DFS(Cur);
    }
    return;
}

int main()
{
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i++){
        scanf("%d", &a[i]);
    }
    while(m--){
        scanf("%d %d", &u, &v);
        adj[u].pb(v);
        adj[v].pb(u);
    }
    for(int i = 1 ; i <= n ; i++){
        if(!vis[i]){
            DFS(i);
            color++;
        }
    }
    for(int i = 1 ; i < color ; i++){
        vector < int > temp1, temp2;
        for(int j = 0 ; j < com[i].size() ; j++){
            temp1.pb(com[i][j].first);
            temp2.pb(com[i][j].second);
        }
        sort(temp1.begin(), temp1.end());
        reverse(temp1.begin(), temp1.end());
        sort(temp2.begin(), temp2.end());
        for(int j = 0 ; j < com[i].size(); j++){
            a[temp2[j]] = temp1[j];
            //cout << temp2[j] << ' ' << temp1[j] << endl;
        }
        //cout << endl;
    }
    for(int i = 1 ; i <= n ; i++)
        printf("%d ", a[i]);
    cout << endl;
    return 0;
}