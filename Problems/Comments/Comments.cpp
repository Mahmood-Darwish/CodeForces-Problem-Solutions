#include <bits/stdc++.h>

#define pb push_back

using namespace std;

bool vis[1100000];
int n, max_lvl;
string s;
vector < string > V[1100000];

int F(string temp)
{
    int number = atoi(temp.c_str());
    return number;
}

int DFS(int pos, int lvl)
{
    vis[pos] = true;
    if(pos >= n)return n - 1;
    int mx = -1;
    string temp = "";
    max_lvl = max(max_lvl, lvl);
    for(int i = pos ; s[i] != ',' && i != n ; i++){
        temp += s[i];
        vis[i] = true;
    }
    V[lvl].pb(temp);
    temp = "";
    for(int i = pos ; i < n ; i++){
        vis[i] = true;
        if(s[i] == ','){
            for(int j = i + 1 ; j < n && s[j] != ',' ; j++){
                vis[j] = true;
                vis[j + 1] = true;
                temp += s[j];
                mx = j;
            }
            break;
        }
    }
    mx += 2;
    int num = F(temp);
    while(num--){
        mx = DFS(mx, lvl + 1);
    }
    return mx;
}

int main()
{
    cin >> s;
    n = s.size();
    for(int i = 0 ; i < n ; i++)
        if(!vis[i])
            DFS(i,1);
    cout << max_lvl << endl;
    for(int i = 1 ; i <= max_lvl ; i++){
        for(int j = 0 ; j < V[i].size() ; j++){
            cout << V[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}