#include <bits/stdc++.h>
#define F first
#define S second
#define ii pair < int , int >
#define MEM(a,b) memset(a,b,sizeof(a))
using namespace std;
typedef long long ll;

ll GCD(ll a , ll b){
    if(!b)return a;
    return GCD(b,a%b);
}

ll LCM(ll a , ll b){
    return (a * b) / GCD(a , b);
}

ll n;
bool vis[50];
string s;

int main()
{
    cin >> s;
    n = s.size();
    if(n < 26)
    {
        cout << -1;
        return 0;
    }
    for(int i = 0 ; i < n ; i++){
        ll sum = 0;
        MEM(vis,0);
        for(int j = i ; j < i + 26 && j < n; j++){
            if(s[j] == '?'){
                sum++;
                continue;
            }
            if(!vis[s[j] - 'A']){
                vis[s[j] - 'A'] = true;
                sum++;
            }
        }
        if(sum == 26){
            for(int j = i ; j < 26 + i && j < n; j++){
                if(s[j] == '?'){
                    for(int k = 0 ; k < 26 ; k++){
                        if(!vis[k]){
                            s[j] = (char)k + 'A';
                            vis[k] = true;
                            break;
                        }
                    }
                }
            }
            for(int j = 0 ; j < n ; j++)
            {
                if(s[j] == '?')
                    s[j] = 'A';
            }
            cout << s;
            return 0 ;
        }
    }
    cout << -1;
    return 0;
}