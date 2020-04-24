#include <iostream>
#include <stdio.h>
#include <string.h>
#include <queue>

#define F first
#define S second

using namespace std;

int n, m, l1, t1, s1, l2,t2,s2;
int ans[3001][3001];
vector < int > adj[3001];

void BFS()
{
    memset(ans, -1, sizeof(ans));
    queue < pair < int , int > > Q;
    for(int i = 1 ; i <= n ; i++){
        ans[i][i] = 0;
        Q.push({i, 0});
        while(!Q.empty()){
            pair < int , int > u = Q.front();
            Q.pop();
            for(auto j : adj[u.F]){
                if(ans[i][j] == -1){
                    ans[i][j] = u.S + 1;
                    Q.push({j, u.S + 1});
                }
            }
        }
    }
    return;
}

int main()
{
    cin >> n >> m;
    for(int i = 0 ; i < m ; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    cin >> s1 >> t1 >> l1 >> s2 >> t2 >> l2;
    BFS();
    /*for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= n ; j++){
            cout << ans[i][j] << ' ';
        }
        cout << endl;
    }*/
    int res = (1 << 27);
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= n ; j++){
            if(ans[s1][i] > -1 && ans[i][j] > -1 && ans[j][t1] > -1 && ans[s2][i] > -1 && ans[j][t2] > -1){
                if(ans[s1][i] + ans[i][j] + ans[j][t1] <= l1 && ans[s2][i] + ans[i][j] + ans[j][t2] <= l2){

                    res = min(ans[s1][i] + ans[i][j] + ans[j][t1] + ans[s2][i] + ans[j][t2], res);
                }
            }
            swap(s1, t1);
            if(ans[s1][i] > -1 && ans[i][j] > -1 && ans[j][t1] > -1 && ans[s2][i] > -1 && ans[j][t2] > -1){
                if(ans[s1][i] + ans[i][j] + ans[j][t1] <= l1 && ans[s2][i] + ans[i][j] + ans[j][t2] <= l2){
                    res = min(ans[s1][i] + ans[i][j] + ans[j][t1] + ans[s2][i] + ans[j][t2], res);
                }
            }
            swap(s1, t1);
        }
    }
    if(ans[s1][t1] <= l1 && ans[s2][t2] <= l2)
        res = min(res, ans[s1][t1] + ans[s2][t2]);
    if(res == (1 << 27)){
        cout << -1 << endl;
    }
    else {
        cout << m - res << endl;
    }
    return 0;
}
/*
10 11

1 3

2 3

3 4

4 5

4 6

3 7

3 8

4 9

4 10

7 9

8 10

1 5 3

6 2 3
*/