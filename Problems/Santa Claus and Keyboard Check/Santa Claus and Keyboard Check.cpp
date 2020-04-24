#include <iostream>
#include <vector>

#define F first
#define S second
#define pb push_back

using namespace std;

vector < int > adj[30];
string s1, s2;
vector < pair < int , int > > V;
bool vis[30];

int main()
{
    cin >> s1 >> s2;
    if(s1 == s2){
        cout << 0 << endl;
        return 0;
    }
    int n = s1.size();
    for(int i = 0 ; i < n ; i++){
        if(s1[i] != s2[i]){
            if((adj[s1[i] - 'a'].size() != 0 && adj[s1[i] - 'a'][0] != s2[i] - 'a')){
                cout << -1 << endl;
                return 0;
            }
            if(adj[s1[i] - 'a'].size() == 0){
                adj[s1[i] - 'a'].pb(s2[i] - 'a');
                adj[s2[i] - 'a'].pb(s1[i] - 'a');
            }
        }
    }
    for(int i = 0 ; i < n ; i++){
        if(adj[s2[i] - 'a'].size() != 0){
            s2[i] = adj[s2[i] - 'a'][0] + 'a';
        }
    }
    if(s1 == s2){
        for(int i = 0 ; i < 26 ; i++){
            if(adj[i].size() != 0 && !vis[i]){
                V.pb({adj[i][0] + 'a', i + 'a'});
                vis[i] = vis[adj[i][0]] = true;
            }
        }
        cout << V.size() << endl;
        for(auto cur : V){
            cout << (char)cur.F << ' ' << (char)cur.S << endl;
        }
        return 0;
    }
    else cout << -1 << endl;
    return 0;
}