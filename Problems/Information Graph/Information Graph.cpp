#include <iostream>
#include <string.h>
#include <stdio.h>
#include <vector>

#define pb push_back
#define F first
#define S second

using namespace std;

int depth[300100];
int n, m, type, timer = 1, k = 1;
int par[300100][26];
int time[300100][26];
vector < int > adj[300100];
int where[300100];
int when[300100];
int color[300100];
vector < pair < int , int > > Q;

void DFS(int node, int temp, int temp2)
{
    depth[node] = temp, color[node] = temp2, temp++;
    for(auto cur : adj[node])
        DFS(cur, temp, temp2);
    return;
}

int check(int node1, int node2)
{
    int dis = depth[node2] - depth[node1];
    int ans = 0;
    for(int i = 0 ; i < 25 ; i++){
        if((dis & (1 << i))){
            ans = max(ans , time[node2][i]);
            node2 = par[node2][i];
        }
    }
    if(node2 != node1)
        return (1 << 29);
    return ans;
}

int main()
{
    memset(par, -1, sizeof(par));
    cin >> n >> m;
    int x, y;
    for(int i = 1 ; i <= m ; i++){
        scanf("%d", &type);
        if(type == 1){
            scanf("%d %d", &x, &y);
            adj[y].pb(x);
            par[x][0] = y;
            time[x][0] = timer++;
        }
        if(type == 2){
            scanf("%d", &x);
            where[k] = x;
            when[k++] = timer++;
        }
        if(type == 3){
            scanf("%d %d", &x, &y);
            Q.pb({x, y});
        }
    }
    for(int i = 1 ; i <= 25 ; i++){
        for(int j = 1 ; j <= n ; j++){
            par[j][i] = par[par[j][i - 1]][i - 1];
            time[j][i] = max(time[j][i - 1], time[par[j][i - 1]][i - 1]);
        }
    }
    int col = 1;
    for(int i = 1; i <= n ; i++){
        if(par[i][0] == -1)
            DFS(i, 1, col++);
    }
    for(unsigned int i = 0 ; i < Q.size() ; i++){
        pair < int , int > u = Q[i];
        //cout << depth[u.F] << ' ' << depth[where[u.S]] << ' ' << color[u.F] << ' ' << color[where[u.S]] << ' ' << check(u.F, where[u.S]) << ' ' << when[u.S] << endl;
        if(depth[u.F] <= depth[where[u.S]] && color[u.F] == color[where[u.S]]){
            if(check(u.F, where[u.S]) <= when[u.S]){
                printf("YES\n");
                continue;
            }
        }
        printf("NO\n");
    }
    return 0;
}
/*
100 66

1 61 29

2 65

3 42 1

3 11 1

2 41

1 97 57

2 98

3 10 2

1 76 34

2 15

2 87

2 15

3 44 4

1 15 7

3 22 1

1 59 12

2 86

2 95

3 43 3

1 62 10

2 34

1 2 1

3 48 5

1 3 2

3 88 2

2 69

3 90 4

1 65 9

1 78 10

3 12 3

3 3 1

3 97 6

1 22 5

2 2

3 32 9

2 88

3 26 4

1 33 15

3 10 2

3 10 12

3 48 7

2 58

2 7

2 67

3 24 10

2 51

1 44 10

3 17 2

1 52 41

3 24 10

3 45 7

3 65 9

3 5 10

2 23

1 38 18

3 68 13

1 48 1

3 70 2

2 22

3 31 5

1 51 4

2 87

2 23

3 74 5

1 40 29

3 48 3

*/