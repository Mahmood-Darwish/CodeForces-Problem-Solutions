#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;

ll n;
ll adj[501][501];
ll arr[501];
vector < ll > sol;
bool vis[501];

int main()
{
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cin >> adj[i][j];
        }
    }
    for(int i = 0 ; i < n ; i++)
        cin >> arr[i];
    for(int k = n - 1 ; k >= 0 ; k--){
        /*
        cout << endl << endl;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                cout << a[i][j] << ' ';
            }
            cout << endl;
        }
        cout << endl << endl;
        */
        arr[k]--;
        vis[arr[k]] = true;
        for(int j = 0 ; j < n ; j++)
            for(int i = 0 ; i < n ; i++)
                adj[j][i] = min(adj[j][arr[k]] + adj[arr[k]][i], adj[j][i]);
        ll temp = 0;
        for(int i = 0 ; i < n ; i++)
            for(int j = 0 ; j < n ; j++)
                if(vis[i] && vis[j])
                    temp += adj[i][j];
        sol.push_back(temp);
    }
    reverse(sol.begin(), sol.end());
    for(auto cur : sol)
        cout << cur << ' ';
    cout << endl;
    return 0;
}