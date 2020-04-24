#include <iostream>
#include <stdio.h>

using namespace std;

char a[1000][1000];
long long n , m , k , visited , s;
bool vis[1000][1000];
bool sure;

void DFS(int i ,int j , bool is_wall)
{
    if(i <= 0 || i > n || j <= 0 || j > m)return;
    if(a[i][j] == '#' || a[i][j] == 'X')return;
    if(vis[i][j])return;
    vis[i][j] = true;
    if(!is_wall)
        visited++;
    if(is_wall)
        a[i][j] = 'X';
    DFS(i+1,j, (visited >= s - k));
    DFS(i-1,j, (visited >= s - k));
    DFS(i,j+1, (visited >= s - k));
    DFS(i,j-1, (visited >= s - k));
}


int main()
{
    scanf("%I64d %I64d %I64d" , &n , &m , &k);
    for(int i = 1 ; i <= n ; i++)
    {
        for(int j = 1 ; j <= m ; j++)
        {
            cin >> a[i][j];
            s += (a[i][j] == '.');
        }
    }
    for(int i = 1 ; i <= n ; i++)
    {
        for(int j = 1 ; j <= m ; j++)
        {
            if(a[i][j] == '.')
            {
                DFS(i,j,0);
                sure = true;
                break;
            }
        }
        if(sure)break;
    }
    for(int i = 1 ; i <= n ; i++)
    {
        for(int j = 1 ; j <= m ; j++)
        {
            printf("%c",a[i][j]);
        }
        cout << '\n';
    }
    return 0;
}