#include <iostream>
#include <map>

using namespace std;

map < int , bool > vis;
map < int , pair < bool , int > > m;
int a[100100];
int b[100100];
int c[100100];
int ans, n;

void DFS(int node, int minn, int maxx)
{
    if(node == -1)
        return;
    if((a[node] < maxx && maxx != -1) || (a[node] > minn && minn != -1)){
        if(m[a[node]].first != true)
            m[a[node]].first = false;
        m[a[node]].second++;
    }
    else m[a[node]].first = true, m[a[node]].second++;
    if(minn != -1)
        DFS(b[node], min(minn, a[node]), maxx);
    else DFS(b[node], a[node], maxx);
    DFS(c[node], minn, max(maxx, a[node]));
    return;
}

int main()
{
    cin >> n;
    for(int i = 1 ; i <= n ;i++){
        cin >> a[i] >> b[i] >> c[i];
        vis[b[i]] = vis[c[i]] = true;
    }
    for(int i = 1 ; i <= n ; i++)
        if(!vis[i])

            DFS(i, -1, -1);
    for(auto it = m.begin(); it != m.end() ; it++){
        if((it -> second).first == 0){
            ans += (it -> second).second;
        }
    }
    cout << ans << endl;
    return 0;
}