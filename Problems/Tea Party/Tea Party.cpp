#include <iostream>

using namespace std;

int n, w, a[110], b[110];

bool check()
{
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            if(i == j) continue;
            if(b[j] > b[i] && a[i] > a[j]){
                return false;
            }
        }
    }
    return true;
}

int main()
{
    cin >> n >> w;
    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
        w -= (a[i] / 2) + (a[i] % 2);
        b[i] = (a[i] / 2) + (a[i] % 2);
        if(w < 0){
            cout << -1 << endl;
            return 0;
        }
    }
    for(int i = 0 ; i < n ; i++){
        int mx = 0, idx = 0;
        for(int j = 0 ; j < n ; j++){
            if(mx < a[j] && a[j] != b[j]){
                mx = a[j];
                idx = j;
            }
        }
        int temp = w;
        w = max(w - (a[idx] - b[idx]), 0);
        b[idx] = min(a[idx], temp + b[idx]);
    }
    if(!check()){
        cout << -1 << endl;
        return 0;
    }
    for(int i = 0 ; i < n ; i++){
        cout << b[i] << ' ';
    }
    cout << endl;
    return 0;
}