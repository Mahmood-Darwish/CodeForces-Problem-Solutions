#include <iostream>
#include <cmath>
#define F first
#define S second
using namespace std;
typedef long long ll;

pair < ll, int > arr[200010];
ll ans = -1e16, n, high, low;
bool ok;

bool check(ll x)
{
    ll rate = x;
    for(int i = 0 ; i < n ; i++){
        //cout << rate << endl;
        if(arr[i].S == 1 && rate <= 1899){
            low = x + 1;
            //cout << rate << endl;
            return false;
        }
        if(arr[i].S == 2 && rate > 1899){
            high = x - 1;
            //cout << rate << endl;
            return false;
        }
        rate += arr[i].F;
    }
    //cout << rate << endl;
    return true;
}

ll find_answer(ll x)
{
    ll rate = x;
    for(int i = 0 ; i < n ; i++){
        rate += arr[i].F;
    }
    return rate;
}

int main()
{
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i].F >> arr[i].S;
        if(arr[i].S == 2)
            ok = true;
    }
    if(!ok){
        cout << "Infinity" << endl;
        return 0;
    }
    high = 1e16, low = -1e16;
    while(low <= high){
        ll mid = (high + low) / 2;
        //cout << mid << endl;
        if(check(mid)){
            ans = mid;
            low = mid + 1;
        }
    }
    if(ans == -1e16){
        cout << "Impossible" << endl;
    }
    else{
        cout << find_answer(ans) << endl;
    }
    return 0;
}