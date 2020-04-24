#include <iostream>
#include <stdio.h>

using namespace std;

int n, m, q, temp, x, y;
char a[1004][1004];
int ans[1004][1004];
bool vis[1004][1004];
bool vis2[1004][1004];

int DFS(int i, int j)
{
    if(vis[i][j] || a[i][j] == '*')
        return 0;
    vis[i][j] = true;
    int sum = 0;
    if(a[i + 1][j] == '*')
        sum++;
    if(a[i - 1][j] == '*')
        sum++;
    if(a[i][j + 1] == '*')
        sum++;
    if(a[i][j - 1] == '*')
        sum++;
    sum += DFS(i + 1, j);
    sum += DFS(i - 1, j);
    sum += DFS(i, j + 1);
    sum += DFS(i, j - 1);
    return sum;
}

void color(int i, int j , int col)
{
    if(vis2[i][j] || a[i][j] == '*')
        return;
    ans[i][j] = col;
    vis2[i][j] = true;
    color(i + 1, j, col);
    color(i - 1, j, col);
    color(i, j + 1, col);
    color(i, j - 1, col);
    return;
}

int main()
{
    cin >> n >> m >> q;
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= m ; j++){
            cin >> a[i][j];
        }
    }
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= m ; j++){
            if(a[i][j] == '.' && ! vis[i][j]){
                temp = DFS(i, j);
                color(i, j, temp);
            }
        }
    }
    while(q--){
        scanf("%d %d", &x, &y);
        printf("%d\n", ans[x][y]);
    }
    return 0;
}