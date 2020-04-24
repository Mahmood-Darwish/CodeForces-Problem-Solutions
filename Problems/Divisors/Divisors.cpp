#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>

#define pb push_back

using namespace std;
typedef long long ll;

map < ll , vector < ll > > m;
vector < ll > V;
ll n, k, found_numbers;

void DFS(ll number, ll stage)
{
    if(found_numbers == 100000){
        return;
    }
    if(stage == k || number == 1){
        printf("%I64d ", number);
        found_numbers++;
        return;
    }
    for(unsigned int i = 0 ; i < m[number].size() ; i++){
        DFS(m[number][i], stage + 1);
    }
    return;
}

int main()
{
    cin >> n >> k;
    for(int i = 1 ; i <= sqrt(n) ; i++){
        if(n % i == 0){
            V.pb(i);
            if(i != n / i)
                V.pb(n / i);
        }
    }
    sort(V.begin(), V.end());
    m[n] = V;
    for(unsigned int i = 0 ; i < V.size() - 1 ; i++){
        for(int j = 1 ; j <= sqrt(V[i]); j++){
            if(V[i] % j == 0){
                m[V[i]].pb(j);
                if(j != V[i] / j)
                    m[V[i]].pb(V[i] / j);
            }
        }
        /*
        cout << V[i] << endl;
        for(auto cur : m[V[i]]){
            cout << cur << ' ';
        }
        cout << endl;*/
        sort(m[V[i]].begin(), m[V[i]].end());
    }
    DFS(n, 0);
    cout << endl;
    return 0;
}