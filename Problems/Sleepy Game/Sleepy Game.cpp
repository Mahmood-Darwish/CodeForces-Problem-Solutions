#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stdio.h>
#include <string.h>

#define F first
#define S second
#define pb push_back
#define SF(x) scanf("%d", &x)

using namespace std;

int n, m, x, y, start, ans;
queue < pair < int ,int > > Q;
vector < int > V, adj[100100];
int arr [100100][4];
bool D;
int VIS[100100][3];

bool BFS()
{
    Q.push({start, 0});
    while(!Q.empty()){
        pair < int, int > u = Q.front();
        Q.pop();
        if(VIS[u.F][u.S]) continue;
        VIS[u.F][u.S] = 1;
        if(adj[u.F].size() == 0 && u.S == 1){
            ans = u.F;
            int pos = ans, temp = 1;
            while(pos != 0){
                V.push_back(pos);
                pos = arr[pos][temp];
                temp ^= 1;
            }
            return true;
        }
        for(auto cur : adj[u.F]){
            if(VIS[cur][1 - u.S]) continue;
            arr[cur][1 - u.S] = u.F;
            Q.push({cur, 1 - u.S});
        }
    }
    return false;
}

void Find_BFS()
{
    reverse(V.begin(), V.end());
    for(auto cur : V){
        cout << cur << ' ';
    }
    cout << endl;
    return;
}

int DFS(int pos)
{
    if(VIS[pos][0] == 1) { D = true; return 1; }
    VIS[pos][0] = 1;
    for(auto cur : adj[pos]){
        if(DFS(cur)){
            D = true;
            return 1;
        }
    }
    VIS[pos][0] = 2;
    return 0;
}

int main()
{
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i++){
        SF(x);
        while(x--){
            SF(y);
            adj[i].pb(y);
        }
    }
    cin >> start;
    if(BFS()){
        cout << "Win\n";
        Find_BFS();
        return 0;
    }
    memset(VIS, 0, sizeof(VIS));
    DFS(start);
    if(D){
        cout << "Draw\n";
        return 0;
    }
    cout << "Lose" << endl;
    return 0;
}