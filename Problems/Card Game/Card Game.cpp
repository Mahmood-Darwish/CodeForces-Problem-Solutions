#include <bits/stdc++.h>
#define F first
#define S second

using namespace std;
typedef long long ll;

ll n, k1, k2, x, mx, win, T;

int main()
{
    cin >> T;
    while(T--){
        cin >> n >> k1 >> k2;
        for(int i = 1 ; i <= k1 ; i++){
            cin >> x;
            if(x > mx){
                mx = x;
                win = 1;
            }
        }
        for(int i = 1 ; i <= k2 ; i++){
            cin >> x;
            if(x > mx){
                mx = x;
                win = 2;
            }
        }
        mx = -1;
        if(win == 1){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    return 0;
}