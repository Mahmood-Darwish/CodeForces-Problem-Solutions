#include <iostream>
#include <string.h>
#include <set>

using namespace std;

int n, m, ans2[1007][1007];
char a[1007][1007], ans[1007][1007];
bool vis[1007][1007], vis2[1007][1007];
set < pair < int , int > > mys;

int DFS(int i, int j)
{
    if(vis[i][j] || a[i][j] == '*' || i >= n || i < 0  || j >= m || j < 0)
        return 0;
    vis[i][j] = true;
    int sum = 1;
    sum += DFS(i + 1, j);
    sum += DFS(i - 1, j);
    sum += DFS(i , j + 1);
    sum += DFS(i , j - 1);
    return sum;
}

void color(int i, int j, int col)
{
    if(vis2[i][j] || i >= n || i < 0  || j >= m || j < 0)
        return;
    if(a[i][j] == '*' && mys.find({i , j}) == mys.end()){
        ans2[i][j] += col;
        mys.insert({i,j});
        return;
    }
    if(a[i][j] == '*')
        return;
    vis2[i][j] = true;
    color(i + 1, j, col);
    color(i - 1, j, col);
    color(i, j + 1, col);
    color(i, j - 1, col);
    return;
}

int main(){
    cin >> n >> m;
    for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; j < m ; j++)
            cin >> a[i][j];
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(a[i][j] == '.'){
                ans[i][j] = '.';
                if(!vis[i][j]){
                    int temp = DFS(i, j);
                    color(i, j, temp);
                    mys.clear();
                }
            }
            else 
                ans2[i][j]++;
        }
    }
    for(int i = 0 ; i < n ;i++)
        for(int j = 0 ; j < m ; j++)
            if(ans2[i][j])
                ans[i][j] = (ans2[i][j] % 10) + '0';
    for(int i = 0 ; i < n ; i++)
        cout << ans[i] << endl;
    return 0;
}