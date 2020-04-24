#include <iostream>
#include <vector>

#define F first
#define S second
#define pb push_back

using namespace std;

int n, m, x, y;
bool vis[10000];
vector < pair < int, int > > V[10000], edge;

int main()
{
    cin >> n >> m;
    for(int i = 1 ; i <= m ;i++){
        cin >> x >> y;
        edge.pb({x, y});
        vis[x] = vis[y] = true;
    }
    for(int i = 1 ; i <= n ; i++){
        if(!vis[i]) V[i].pb({i, i});
    }
    x = n + 19;
    for(int i = 0 ; i < edge.size() ; i++){
        V[edge[i].F].pb({edge[i].F, x});
        V[edge[i].S].pb({edge[i].S, x});
        x++;
    }
    for(int i = 1 ; i <= n ; i++){
        cout << V[i].size() << endl;
        for(unsigned int j = 0 ; j < V[i].size() ; j++){
            cout << V[i][j].F << ' ' << V[i][j].S << endl;
        }
    }
    return 0;
}