#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

ll n, m, k, SQ = 350;
ll a[(1 << 22)];
ll pre[(1 << 22)];
ll cnt[(1 << 22)];
ll ans[(1 << 22)];

struct query{
    ll L, R, Ind;
};

vector < query > V;

bool comp(const query &lhs, const query &rhs)
{
    if(lhs.L / SQ != rhs.L / SQ){
        return lhs.L / SQ < rhs.L / SQ;
    }
    return lhs.R < rhs.R;
}

int main()
{
    cin >> n >> m >> k;
    for(int i = 1 ; i <= n ; i++){
        cin >> a[i];
    }
    pre[0] = 0;
    for(int i = 1 ; i <= n ; i++){
        pre[i] = pre[i - 1];
        pre[i] ^= a[i];
    }
    for(int i = 1 ; i <= m ; i++){
        ll x, y;
        cin >> x >> y;
        query temp;
        temp.L = x, temp.R = y;
        temp.Ind = i;
        V.push_back(temp);
    }
    sort(V.begin(), V.end(), comp);
    ll L = 1, R = 1;
    cnt[pre[1]]++;
    cnt[0]++;
    ll sum = 0;
    if(pre[1] == k) sum++;
    for(unsigned int i = 0 ; i < V.size() ; i++){
        ll l = V[i].L, r = V[i].R;
        while(R < r){
            R++;
            sum += cnt[pre[R] ^ k];
            cnt[pre[R]]++;
        }
        while(R > r){
            cnt[pre[R]]--;
            sum -= cnt[pre[R] ^ k];
            R--;
        }
        while(L > l){
            L--;
            sum += cnt[pre[L - 1] ^ k];
            cnt[pre[L - 1]]++;
        }
        while(L < l){
            cnt[pre[L - 1]]--;
            sum -= cnt[pre[L - 1] ^ k];
            L++;
        }
        ans[V[i].Ind] = sum;
    }
    for(int i = 1 ; i <= m ; i++){
        cout << ans[i] << endl;
    }
    return 0;
}