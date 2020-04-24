#include <iostream>
#include <vector>

using namespace std;

vector < int > adj[1000000];
int n , k;

int main()
{
    cin >> n >> k;
    if(2 * k >= n)
    {
        cout << -1;
        return 0;
    }
    for(int i = 1 ; i <= n ; i++)
    {
        for(int j = i + 1 ; j < i + k + 1 ; j++)
        {
            int temp = j;
            if(temp > n)temp -= n;
            adj[i].push_back(temp);
        }
    }
    cout << n * k << '\n';
    for(int i = 1 ; i <= n ; i++)
    {
        for(int j = 0 ; j < adj[i].size() ; j++)
            cout << i << " " << adj[i][j] << '\n';
    }
    return 0;
}