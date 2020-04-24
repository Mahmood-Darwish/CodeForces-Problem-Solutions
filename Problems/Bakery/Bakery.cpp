#include <bits/stdc++.h>
#define F first
#define S second
#define ii pair < int , int >

using namespace std;

typedef long long ll;

ll GCD(ll a , ll b)
{
    if(!b)return a;
    return GCD(b,a%b);
}

ll LCM(ll a , ll b)
{
    return (a * b) / GCD(a,b);
}

ll n , m ;
bool sure;
char c;
vector < ll > bak;
ll sum = 99999999999999;
vector <ii> adj[10000000];
set < ll > mys;

int main()
{
    ll k , u , v , l , num;
    cin >> n >> m >> k;
    for(int i = 0 ; i < m ; i++)
    {
        cin >> u >> v >> l;
        adj[u].push_back({v,l});
        adj[v].push_back({u,l});
    }
    ll o = k;
    while(o--)
    {
        cin >> num;
        bak.push_back(num);
        mys.insert(num);
    }
    if(k == 0 || k == n)
    {
        cout << -1;
        return 0;
    }
    for( int i = 0 ; i < bak.size() ; i++)
    {
        for(int j = 0 ; j < adj[bak[i]].size() ; j++)
        {
            if(mys.find(adj[bak[i]][j].F) == mys.end())
                sum = min(sum ,(ll) adj[bak[i]][j].S);
        }
    }
    if(sum == 99999999999999)
    {
        cout << -1;
    }
    else cout << sum;
    return 0;
}