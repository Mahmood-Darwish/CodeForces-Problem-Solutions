#include <iostream>
#include <map>

using namespace std;
typedef long long ll;

ll n, ans;
map < ll , ll > m;
ll a[1001];

int F(ll i, ll j)
{
    if(m[i + j] != 0){
        m[i + j]--;
        int temp = 1 + F(j , i + j);
        m[i + j]++;
        return temp;
    }
    else return 0;
}

int main()
{
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
        m[a[i]]++;
    }
    ans = m[0];
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            if(i == j || (!a[i] && !a[j])){
                continue;
            }
            else{
                m[a[i]]--;
                m[a[j]]--;
                ans = max(ans, F(a[i] ,a[j]) + 2LL);
                m[a[i]]++;
                m[a[j]]++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}