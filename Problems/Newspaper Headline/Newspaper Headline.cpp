#include <iostream>
#include <vector>

using namespace std;

string s1, s2;
int ans;
bool vis[30];
vector < int > a[30];

int main()
{
    cin >> s1 >> s2;
    int n = s1.size(), m = s2.size();
    for(int i = 0 ; i < n ; i++){
        a[s1[i] - 'a'].push_back(i);
        vis[s1[i] - 'a'] = true;
    }
    for(int i = 0 ; i < m ; i++){
        if(!vis[s2[i] - 'a']){
            cout << -1 << endl;
            return 0;
        }
    }
    int pos1 = 0;
    for(int j = 0 ; j < m ; j++){
        auto it = lower_bound(a[s2[j] - 'a'].begin(), a[s2[j] - 'a'].end(), pos1);
        if(it == a[s2[j] - 'a'].end()){
            ans++;
            pos1 = *(lower_bound(a[s2[j] - 'a'].begin(), a[s2[j] - 'a'].end(), 0)) + 1;
        }
        else{
            pos1 = *(it) + 1;
        }
    }
    cout << ans + 1 << endl;
    return 0;
}