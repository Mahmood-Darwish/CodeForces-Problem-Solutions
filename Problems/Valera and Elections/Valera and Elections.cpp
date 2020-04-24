#include <iostream>
#include <vector>
#include <queue>

#define pb push_back
#define F first
#define S second

using namespace std;

vector < pair < int , bool > > adj[100100];
vector < int > V;
int n, u, v, pro;

bool DFS(int node, int par, bool need_fixing)
{
    bool sure = false;
    for(auto cur : adj[node])
    {
        if(cur.F != par){
            sure = max(sure, DFS(cur.F, node, cur.S));
        }
    }
    if(sure)
        return true;
    if(need_fixing){
        V.pb(node);
        return true;
    }
    return false;
}

int main()
{
    cin >> n;
    for(int i = 0 ; i < n - 1 ; i++){
        cin >> u >> v >> pro;
        adj[u].pb({v, (pro == 2)});
        adj[v].pb({u, (pro == 2)});
    }
    DFS(1, -1, 0);
    cout << V.size() << endl;
    for(auto cur : V)
        cout << cur << ' ';
    cout << endl;
    return 0;
}