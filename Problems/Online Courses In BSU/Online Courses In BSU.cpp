#include <iostream>
#include <vector>

using namespace std;

int n, m, ans, cycle, t, num;
short vis[100100];
vector < int > vec, V[100100];
int arr1[100100];

void DFS(int node)
{
    if(vis[node] == 2)
        return;
    //cout << node << endl;
    vis[node] = 1;
    if(cycle == 1)
        return;
    for(int i = 0 ; i < V[node].size() ; i++){
        if(vis[V[node][i]] == 1){
            cycle = 1;
            return;
        }
        if(vis[V[node][i]] == 2)
            continue;
        DFS(V[node][i]);
        if(cycle == 1)
            return;
    }
    if(vis[node] != 2){
        vis[node] = 2;
        ans++;
        vec.push_back(node);
    }
}

int main()
{
    cin >> n >> m;
    for(int i = 1 ; i <= m ; i++){
        scanf("%d", &arr1[i]);
    }
    for(int i = 1 ; i <= n ; i++){
        scanf("%d", &t);
        while(t--){
            scanf("%d", &num);
            V[i].push_back(num);
        }
    }
    for(int i = 1 ; i <= m ; i++){
        DFS(arr1[i]);
        if(cycle){
            cout << -1 << endl;
            return 0;
        }
    }
    cout << ans << endl;
    for(int i = 0 ; i < ans ; i++){
        cout << vec[i] << ' ';
    }
    cout << endl;
    return 0;
}