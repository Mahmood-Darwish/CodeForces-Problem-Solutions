#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
int dx[] = {1 , -1 , 0 , 0};
int dy[] = {0 , 0 , 1 , -1};
char a[100][100] , b[100][100];
bool vis[100][100];
int n , m , k;
vector < pair < int , pair < int , int > > > sol;
void BFS(int i, int j)
{
    if(vis[i][j] || a[i][j] == '*')
        return;
    vis[i][j]= true;
    a[i][j] = '*';
    for(int t = 0 ; t < 4 ; t++)
    {
        int nx = i + dx[t] , ny = j + dy[t];
        if(nx < 0 || ny < 0 || nx >= n || ny >= m || a[nx][ny] == '*') continue;
        BFS(nx , ny);
    }
}

int BFS2(int i, int j)
{
    if(vis[i][j] || a[i][j] == '*')
        return 0;
    vis[i][j]= true;
    int sum = 1;
    for(int t = 0 ; t < 4 ; t++)
    {
        int nx = i + dx[t] , ny = j + dy[t];
        if(nx < 0 || ny < 0 || nx >= n || ny >= m || a[nx][ny] == '*') continue;
        sum += BFS2(nx , ny);
    }
    return sum;
}

void BFS3(int i, int j)
{
    if(vis[i][j] || b[i][j] == '*' || a[i][j] == '*')
        return;
    vis[i][j]= true;
    b[i][j] = '*';
    a[i][j] = '*';
    for(int t = 0 ; t < 4 ; t++)
    {
        int nx = i + dx[t] , ny = j + dy[t];
        if(nx < 0 || ny < 0 || nx >= n || ny >= m || b[nx][ny] == '*' || a[nx][ny] == '*') continue;
        BFS3(nx , ny);
    }
}


int main()
{
    cin >> n >> m >> k;
    for(int i = 0 ; i < n ; i++)
        scanf("%s",&a[i]);
    for(int i = 0 ; i < n ; i++)
        for(int j=0;j<m;j++)
            b[i][j] = a[i][j];
    for(int i = 0 ; i < m ; i++)
    {
        if(a[0][i] == '.' && !vis[0][i])
        {
            BFS(0,i);
        }
        if(a[n-1][i] == '.' && !vis[n-1][i])
        {
            BFS(n-1,i);
        }
    }
    for(int i = 0 ; i < n ; i++)
    {
        if(a[i][0] == '.' && !vis[i][0])
        {
            BFS(i,0);
        }
        if(a[i][m-1] == '.' && !vis[i][m-1])
        {
            BFS(i,m-1);
        }
    }
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < m ; j++)
        {
            if(a[i][j] == '.' && !vis[i][j])
            {
                pair < int , pair < int , int > > temp;
                temp.first = BFS2(i,j);
                temp.second = {i,j};
                sol.pb(temp);
            }
        }
    }
    ll res = 0;
    memset(vis,0,sizeof(vis));
    sort(sol.begin(),sol.end());
    int x = sol.size() - k;
    for(int i = 0 ; i < x ; i++)
    {
        res += sol[i].first;
        BFS3(sol[i].second.first,sol[i].second.second);
    }
    cout << res << endl;
    for(int i = 0 ; i  <n ; i++)
    {
        for(int j =  0; j < m ; j++)
        {
            cout << b[i][j];
        }
        cout << endl;
    }
    return 0;
}