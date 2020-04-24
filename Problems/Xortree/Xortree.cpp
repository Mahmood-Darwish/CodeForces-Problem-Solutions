#include <iostream>
#include <vector>

using namespace std;

vector < int > adj[1000000];
bool vis[1000000];
int inti[1000000];
int goal[1000000];
int arr[1000000];
int ans , n , a , b;

void DFS(int node , int level , bool odd , bool even)
{
    if(vis[node])return;
    vis[node] = true;
    if(level % 2 == 0) if(even) inti[node] = 1 - inti[node];
    if(level % 2 == 1) if(odd) inti[node] = 1 - inti[node];
    if(inti[node] != goal[node])
    {
        arr[ans] = node;
        ans++;
        if(level % 2 == 0) even = 1 - even;
        if(level % 2 == 1) odd = 1 - odd;
    }
    for(int i = 0 ; i < adj[node].size() ; i++)
        DFS(adj[node][i] , level + 1 , odd , even);
}

int main()
{
    cin >> n;
    for(int i = 0 ; i < n - 1; i++)
    {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i = 1 ; i <= n ; i++)
        cin >> inti[i];
    for(int i = 1 ; i <= n ; i++)
        cin >> goal[i];
    DFS( 1 , 0 , 0 , 0);
    cout << ans << endl;
    for(int i = 0 ; i < ans ; i++)
        cout << arr[i] << endl;
    return 0;
}