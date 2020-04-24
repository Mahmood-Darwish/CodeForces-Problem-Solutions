#include <bits/stdc++.h>
#define F first
#define S second
#define pb push_back
#define MEM(a,b) memset(a,b,sizeof(a))

using namespace std;
typedef long long ll;

char a[1000][1000];
ll temp1 = -1, temp2 = -1, n, m, mn = 10000000,mx = -1;

int main()
{
    cin >> n >> m;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cin >> a[i][j];
        }
    }
    for(int i = 0 ; i < n ; i++){
        mn = 10000000, mx = -1;
        for(int j = 0 ; j < m ; j++){
            if(a[i][j] == 'X'){
                mn = min(mn, (ll)j);
            }
            if(a[i][j] == 'X'){
                mx = max(mx, (ll)j);
            }
        }
        if(mn != 10000000 && mx != -1){
        for(int j = mn ; j <= mx ; j++){
            if(a[i][j] != 'X'){
                cout << "NO";
                exit(0);
            }
        }
        if(temp1 != -1){
            if(temp1 != mn || temp2 != mx){
                cout << "NO";
                return 0;
            }
        }
        temp1 = mn;
        temp2 = mx;
        }
    }
    cout << "YES";
    return 0;
}