#include <iostream>
#include <vector>

using namespace std;

vector < pair < int , int > > adj;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        string s;
        cin >> s;
        for(int i = 1 ; i <= 12 ; i++)
        {
            if(12 % i == 0)
            {
                for(int k = 0 ; k < 12 / i ; k++)
                {
                    bool sure = true;
                    for(int j = k ; j < 12 ; j += (12 / i))
                    {
                        if(s[j] != 'X')
                            sure = false;
                    }
                    if(sure)
                    {
                        adj.push_back({i , (12/i)});
                        break;
                    }
                }
            }
        }
        cout << adj.size();
        if(adj.size())
        {
            cout << " ";
            for(int i = 0 ; i < adj.size() - 1; i++)
                cout << adj[i].first << 'x' << adj[i].second << " ";
            cout << adj[adj.size() - 1].first << 'x' << adj[adj.size() - 1].second <<  '\n';
            adj.clear();
        }
        else cout << '\n';
    }
    return 0;
}