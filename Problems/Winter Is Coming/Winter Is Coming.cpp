#include <iostream>
#include <algorithm>
#include <vector>

#define pb push_back
#define F first
#define S second

using namespace std;

vector < pair < int , int > > segs;
int n, k, temp, sum , ans, var;
vector < int > V;
int a[1000000];

int main()
{
    cin >> n >> k;
    for(int i = 1 ; i <= n ; i++){
        cin >> a[i];
    }
    for(int i = 1 ; i <= n ; i++){
        if(a[i] < 0)
            sum++;
    }
    if(sum > k){
        cout << -1 << endl;
        return 0;
    }
    temp = k - sum;
    for(int i = 1 ; i <= n ; i++){
        if(a[i] < 0){
            int j;
            for( j = i ; j <= n; j++){
                if(a[j] >= 0){
                    segs.pb({i, j - 1});
                    break;
                }
                if(j == n){
                    segs.pb({i, j});
                    break;
                }
            }
            i = j;
        }
    }
    ans = segs.size() * 2;
    if(!ans)
        return cout << 0,0;
    for(unsigned int i = 0 ; i < segs.size() - 1; i++){
        V.pb((segs[i + 1].F - segs[i].S) - 1);
    }
    sort(V.begin(), V.end());
    for(unsigned int i = 0 ; i < V.size() ; i++){
        if(V[i] <= temp){
            temp -= V[i];
            ans -= 2;
        }
        else break;
    }
    for(int i = 1 ; i <= n ; i++){
        if(a[i] < 0 && a[i + 1] >= 0)
            var = i;
    }
    if(n - var <= temp)
        ans--;
    cout << ans << endl;
    return 0;
}