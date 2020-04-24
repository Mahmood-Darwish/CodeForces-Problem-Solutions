#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>

using namespace std;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
bool vis[1007][1007];
int temp[1007][1007];
int val[1007][1007];
char a[1007][1007];
int col, ans , n, m;


bool check(int i, int j)
{
    if(i >= n || i < 0 || j < 0 || j >= m)
        return false;
    return true;
}

int DFS(int x, int y)
{
    if(val[x][y] != -1)
        return val[x][y];
    int sum = 0;
    if(a[x][y] == 'D'){
        for(int i = 0 ; i < 4 ; i++){
            if(check(x + dx[i], y + dy[i]) && a[x + dx[i]][y + dy[i]] == 'I'){
                sum = max(sum, DFS(x + dx[i], y + dy[i]));
            }
        }
    }
    if(a[x][y] == 'I'){
        for(int i = 0 ; i < 4 ; i++){
            if(check(x + dx[i], y + dy[i]) && a[x + dx[i]][y + dy[i]] == 'M'){
                sum = max(sum, DFS(x + dx[i], y + dy[i]));
            }
        }
    }
    if(a[x][y] == 'M'){
        for(int i = 0 ; i < 4 ; i++){
            if(check(x + dx[i], y + dy[i]) && a[x + dx[i]][y + dy[i]] == 'A'){
                sum = max(sum, DFS(x + dx[i], y + dy[i]));
            }
        }
    }
    if(a[x][y] == 'A'){
        for(int i = 0 ; i < 4 ; i++){
            if(check(x + dx[i], y + dy[i]) && a[x + dx[i]][y + dy[i]] == 'D'){
                sum = max(sum, DFS(x + dx[i], y + dy[i]));
            }
        }
    }
    return (val[x][y] = (sum + (a[x][y] == 'A')));
}

bool cycle(int x, int y)
{
    if(temp[x][y] != -1)
        return temp[x][y];
    temp[x][y] = 1;
    bool num = false;
    if(a[x][y] == 'D'){
        for(int i = 0 ; i < 4 ; i++){
            if(check(x + dx[i], y + dy[i]) && a[x + dx[i]][y + dy[i]] == 'I'){
                num = max(num, cycle(x + dx[i], y + dy[i]));
            }
        }
    }
    if(a[x][y] == 'I'){
        for(int i = 0 ; i < 4 ; i++){
            if(check(x + dx[i], y + dy[i]) && a[x + dx[i]][y + dy[i]] == 'M'){
                num = max(num, cycle(x + dx[i], y + dy[i]));
            }
        }
    }
    if(a[x][y] == 'M'){
        for(int i = 0 ; i < 4 ; i++){
            if(check(x + dx[i], y + dy[i]) && a[x + dx[i]][y + dy[i]] == 'A'){
                num = max(num, cycle(x + dx[i], y + dy[i]));
            }
        }
    }
    if(a[x][y] == 'A'){
        for(int i = 0 ; i < 4 ; i++){
            if(check(x + dx[i], y + dy[i]) && a[x + dx[i]][y + dy[i]] == 'D'){
                num = max(num, cycle(x + dx[i], y + dy[i]));
            }
        }
    }
    return (temp[x][y] = num);
}

int main()
{
    memset(temp, -1, sizeof(temp));
    memset(val, -1, sizeof(val));
    cin >> n >> m;
    for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; j < m ; j++)
            scanf(" %c", &a[i][j]);
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(a[i][j] == 'M'){
                if(temp[i][j] == -1){
                    if(cycle(i, j)){
                        cout << "Poor Inna!\n";
                        return 0;
                    }
                }
            }
        }
    }
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(a[i][j] == 'D'){
                ans = max(ans, DFS(i, j));
            }
        }
    }
    if(!ans){
        cout << "Poor Dima!\n";
    }
    else{
        cout << ans << endl;
    }
    return 0;
}