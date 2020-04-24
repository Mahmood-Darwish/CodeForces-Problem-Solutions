#include <iostream>
#include <vector>

using namespace std;

bool vis[1010][1010];
int n , a , b;
vector < int > x[10000];
vector < int > y[10000];
long long maxx1 , maxx2 , num1 , num2;
long long ans;

void funt(int i , int j)
{
    if(vis[i][j])return;
    vis[i][j] = true;
    for(int k1 = 0 ; k1 < x[i].size() ; k1++)
    {
        funt(i,x[i][k1]);
    }
    x[i].clear();
    for(int k1 = 0 ; k1 < y[j].size() ; k1++)
    {
        funt(y[j][k1],j);
    }
    y[j].clear();
}

int main()
{
    cin >> n;
    for( int i = 0 ; i < n ; i++)
    {
        cin >> a >> b;
        x[a].push_back(b);
        y[b].push_back(a);
    }
    for(int i = 0 ; i < n ; i++)
    {
        maxx2 = maxx1 = 0;
        for(int j = 0 ; j <= 1000 ; j++)
        {
            if(x[j].size() > maxx1)
            {
                num1 = j;
                maxx1 = x[j].size();
            }
        }
        for(int j = 0 ; j <= 1000 ; j++)
        {
            if(y[j].size() > maxx2)
            {
                num2 = j;
                maxx2 = y[j].size();
            }
        }
        if(maxx1 > maxx2)
        {
            funt(num1,x[num1][0]);
            ans++;
        }
        else
        {
            if(maxx2 != 0)
            {
                funt(y[num2][0],num2);
                ans++;
            }
        }
    }
    cout << ans - 1 << '\n';
    return 0;
}