#include <iostream>
#include <vector>
#include <stack>
#include <string.h>

using namespace std;

stack < int > mys;
bool vis[10000000];
long long cost[10000000],  min_cost[10000000];
vector < int > adj1[1000000];
vector < int > adj2[1000000];
vector < unsigned long long > myv[1000000];
unsigned long long n , m , com , a , b , ans , ans2 = 1;

void DFS(int s)
{
    if(!vis[s])
    {
        vis[s] = true;
        for(int i = 0 ; i < adj1[s].size() ; i++)
            DFS(adj1[s][i]);
        mys.push(s);
    }
}

void DFS2(int s)
{
    if(!vis[s])
    {
        vis[s] = true;
        myv[com].push_back(s);
        for(int i = 0 ; i < adj2[s].size() ; i++)
            DFS2(adj2[s][i]);
    }
}

void scc()
{
    for(int i = 1 ; i <= n ;i++)
    {
        if(!vis[i])
        {
            DFS(i);
        }
    }
    memset(vis,0,sizeof(vis));
    for(int i = 1 ; i <= n ;i++)
    {
        if(!vis[mys.top()])
        {
            DFS2(mys.top());
            com++;
        }
        mys.pop();
    }
    return;
}

int main()
{
    for(int i = 0 ; i <= 1000000 ; i ++)
        min_cost[i] = 999999999999;
    cin >> n;
    for(int i = 1 ; i <= n ; i++)
        cin >> cost[i];
    cin >> m;
    while(m--)
    {
        cin >> a >> b;
        adj1[a].push_back(b);
        adj2[b].push_back(a);
    }
    scc();
    for(int i = 0 ; i < com ; i++)
    {
        int temp = 1;
        for(int j = 0 ; j < myv[i].size() ; j++)
        {
            if(cost[myv[i][j]] < min_cost[i])
            {
                min_cost[i] = cost[myv[i][j]];
                temp = 1;
                continue;
            }
            if(cost[myv[i][j]] == min_cost[i])
            {
                temp++;
                continue;
            }
        }
        ans2 = ((ans2 % 1000000007) *  ((temp) % 1000000007)) % 1000000007;
    }
    for(int i = 0 ; i < com ; i++)
        ans += min_cost[i];
    cout << ans << " " << ans2;
    return 0;
}