#include <bits/stdc++.h>

using namespace std;

int n, m;
char a[501][501];
bool vis[501][501];
vector < pair < char , pair < int , int > > > V;
int dx[] = {1 , -1 , 0 , 0};
int dy[] = {0 , 0 , 1, -1};

bool check(int x, int y)
{
    if(x > -1 && x < n && y > -1 && y < m && !vis[x][y] && a[x][y] != '#')
        return true;
    return false;
}

void DFS(int x, int y, bool ok)
{
    vis[x][y] = true;
    V.push_back({'B',{x , y}});
    for(int i = 0 ; i < 4 ; i++){
        if(check(dx[i] + x, dy[i] + y)){
            DFS(dx[i] + x, dy[i] + y, 0);
        }
    }
    if(!ok){
        V.push_back({'D',{x , y}});
        V.push_back({'R',{x , y}});
    }
    return;
}

int main(){
    cin >> n >> m;
    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
    }
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(!vis[i][j] && a[i][j] != '#'){
                DFS(i, j, 1);
            }
        }
    }
    cout << V.size() << endl;
    for(auto cur : V){
        printf("%c %d %d\n", cur.first, cur.second.first + 1, cur.second.second + 1);
    }
}