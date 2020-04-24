#include <bits/stdc++.h>
#define F first
#define S second

using namespace std;
typedef long long ll;

ll n, T;
ll a[200100];


int main()
{
    cin >> T;
    while(T--){
        scanf("%I64d", &n);
        for(int i = 1 ; i <= n ; i++){
            scanf("%I64d", &a[i]);
        }
        bool B = true;
        for(int i = 1 ; i < n ; i++){
            if(max(a[i], a[i + 1]) - min(a[i], a[i + 1]) >= 2){
                printf("YES\n%d %d\n", i, i + 1);
                B = false;
                break;
            }
        }
        if(B){
            printf("NO\n");
        }
    }
    return 0;
}