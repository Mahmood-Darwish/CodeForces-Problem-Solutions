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

set < ll > s;

ll n , a[1000000];

vector < ll > v;
int main()
{
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i];
        s.insert(a[i]);
    }
    if(s.size() > 3){
        cout << "NO";
        return 0;
    }
    if(s.size() <= 2){
        cout << "YES";
        return 0;
    }
    set<ll>::iterator it;
    for(it = s.begin();it!=s.end();it++){
        v.push_back(*it);
    }
    ll sum = v[2] - v[1];
    if(sum == v[1] - v[0]){
        cout << "YES" << endl;
        return 0;
    }
    cout << "NO" << endl;
    return 0;
}