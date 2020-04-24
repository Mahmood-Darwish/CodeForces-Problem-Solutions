#include <iostream>

using namespace std;

long long n, arr[100100], bit[1000100], MOD = 1e9 + 7, mx;

void update(int index, int val)
{
    for(int i = index ; i <= 1000007 ; i += (i&(-i))){
        bit[i] += val;
        bit[i] %= MOD;
    }
    return;
}

int query(int index)
{
    int sum = 0;
    for(int i = index ; i > 0; i -= (i&(-i))){
        sum += bit[i];
        sum %= MOD;
    }
    return sum;
}

int main()
{
    cin >> n;
    for(int i = 1 ; i <= n ; i++){
        cin >> arr[i];
    }
    for(int i = 1 ; i <= n ; i++){
        mx = max(mx, arr[i]);
        int temp = query(arr[i]), temp2 = temp - query(arr[i] - 1);
        update(arr[i], (((temp + 1) * arr[i]) - temp2) % MOD);
    }
    cout << query(mx) << endl;
    return 0;
}