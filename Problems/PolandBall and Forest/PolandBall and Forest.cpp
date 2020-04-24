#include <iostream>

using namespace std;

int n, sum, ans;
int par[20010], arr[20010];

int main()
{
    cin >> n;
    for(int i = 1 ; i <= n ; i++){
        cin >> par[i];
        if(par[i] == i){
            ans++;
            continue;
        }
        arr[par[i]]++;
    }
    for(int i = 1 ; i <= n ; i++){
        if(arr[i]){
            sum++;
        }
    }
    sum /= 2;
    cout << ans + sum << endl;
    return 0;
}