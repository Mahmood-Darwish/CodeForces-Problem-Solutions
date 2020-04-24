#include <bits/stdc++.h>
#define F first
#define S second
#define ii pair < int , int >
#define SF(a) scanf("%I64d",&a)
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

int main()
{
    ll l1 , l2 , r1 , r2 , k;
    ll sum = 0;
    cin >> l1 >> r1 >> l2 >> r2 >> k;
    if(r1 < l2 || r2 < l1){
        cout << 0;
        return 0;
    }
    if(l2 >= l1){
        sum = min(r1 , r2) - l2;
        sum++;
        if(k <= min(r1 ,r2) && k >=l2)
            sum--;
        cout << sum;
    }
    else{
        sum = min(r1 , r2) - l1;
        sum++;
        if(k <= min(r1 ,r2) && k >=l1)
            sum--;
        cout << sum;
    }
    return 0;
}