#include <iostream>
#include <string.h>
#include <stdio.h>
#include <vector>
#include <queue>

#define F first
#define S second
#define pb push_back
#define SF(x) scanf("%d",&x)

using namespace std;
/*
vector < pair < int , pair < int , bool > > > adj[100100];
int n, m, k, ans, u, v, x, s, t[100100];

void dijkstra()
{
    int dis[100100];
    bool train[100100];
    bool vis[100100];
    memset(dis,-1,sizeof(dis));
    memset(vis,0,sizeof(vis));
    memset(train,0,sizeof(train));
    priority_queue < pair < int , bool > , vector < pair < int , bool > > , greater < pair < int , bool > > > pq;
    pq.push({1, 0});
    dis[1] = 0;
    while(!pq.empty()){
        pair < int , bool > U = pq.top();
        pq.pop();
        for(auto cur : adj[U.F]){
            if(dis[cur.F] == -1 || dis[cur.F] > dis[U.F] + cur.S.F){
                dis[cur.F] = dis[U.F] + cur.S.F;
                train[cur.F] = max(U.S, cur.S.S);
            }
            if(dis[cur.F] == dis[U.F] + cur.S.F){
                train[cur.F] = min(train[cur.F] , max(U.S, cur.S.S));
            }
            if(!vis[cur.F]){
                vis[cur.F] = true;
                pq.push({cur.F, train[cur.F]});
            }
        }
    }
    for(int i = 1 ; i <= n ; i++){
        ans += t[i] - train[i];
    }
    return;
}*/

int main()
{
    string s, s2;
    cin >> s >> s2;
    if(s == s2)
        cout << -1 << endl;
    else
        cout << max(s.size(), s2.size()) << endl;
    return 0;
}