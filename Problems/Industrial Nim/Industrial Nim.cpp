#include <iostream>

using namespace std;
typedef long long ll;

ll f(ll a) {
     ll res[] = {a,1,a+1,0};
     return res[a%4];
}

ll getXor(ll a, ll b) {
     return f(b)^f(a-1);
}

int main()
{
    ll n, x, m, sum = 0;
    cin >> n;
    while(n--){
        cin >> x >> m;
        //cout << getXor(x, x + m - 1) << endl;
        sum ^= getXor(x, x + m - 1);
    }
    if(!sum){
        cout << "b";
    }
    else {
        cout << "t";
    }
    cout << "olik\n";
    return 0;
}