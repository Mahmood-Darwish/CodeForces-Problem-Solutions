#include <iostream>
#include <queue>

using namespace std;

bool vis[1000000];
int n , m ;
int ans = -1;
int sure;
int adj1[500][500];
int adj2[500][500];

void BFS()
{
    queue < pair < int , int > > q;
    q.push(make_pair(1 , 0));
    while(!q.empty())
    {
        if(vis[q.front().first])
        {
            q.pop();
            continue;
        }
        if(sure == 2)
        {

            for(int i = 1 ; i <= n ; i++)
            {
                if(adj1[q.front().first][i])
                    q.push(make_pair(i , q.front().second + 1));
                if(adj1[q.front().first][n])
                {
                    ans = q.front().second + 1;
                    return;
                }
                vis[q.front().first] = true;
            }
            q.pop();
        }
        else
        {
            for(int i = 1 ; i <= n ; i++)
            {
                if(adj2[q.front().first][i])
                    q.push(make_pair(i , q.front().second + 1));
                if(adj2[q.front().first][n])
                {
                    ans = q.front().second + 1;
                    return;
                }
                vis[q.front().first] = true;
            }
            q.pop();
        }
    }
}


int main()
{
    cin >> n >> m;
    while(m--)
    {
        int a , b;
        cin >> a >> b;
        adj1[a][b] = 1;
        adj1[b][a] = 1;
        if(a == 1 && b == n)
            sure = 1;
        if(a == n && b == 1)
            sure = 1;
    }
    if(!sure)
        sure = 2;
    for(int i = 1 ; i <= n ; i++)
    {
        for(int j = 1 ; j <= n ; j++)
        {
            if(i != j)
                adj2[i][j] = 1 - adj1[i][j];
        }
    }
    BFS();
    cout << ans;
    return 0;
}