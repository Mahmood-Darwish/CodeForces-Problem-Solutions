#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

int ans[100100];
priority_queue < int > Q;
int out[100100];
vector < int > adj[100100], adj2[100100];

int main()
{
    int n, m, u, v;
    cin >> n >> m;
    for(int i = 1 ;i <= m ; i++){
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj2[v].push_back(u);
        out[u]++;
    }
    for(int i = 1 ; i <= n ; i++){
        if(!out[i]) Q.push(i);
    }
    int temp = n;
    while(!Q.empty()){
        int U = Q.top();
        Q.pop();
        ans[U] = temp;
        for(int i = 0 ; i < adj2[U].size() ;i++){
            out[adj2[U][i]]--;
            if(!out[adj2[U][i]]) Q.push(adj2[U][i]);
        }
        temp--;
    }
    for(int i = 1 ; i <= n ; i++){
        printf("%d ", ans[i]);
    }
    cout << endl;
    return 0;
}