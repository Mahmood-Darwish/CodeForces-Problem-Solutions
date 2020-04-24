#include <iostream>

using namespace std;
typedef long long ll;

ll n, a[5007], cost[5007][5007];

ll best(int low, int high, int hight)
{
    if(high < low)
        return 0;
    return min((ll)((high - low) + 1), best(low, cost[low][high] - 1, a[cost[low][high]]) + best(cost[low][high] + 1, high, a[cost[low][high]]) + (a[cost[low][high]] - hight));
}

int main()
{
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
    }
    for(int i = 0 ; i < n ; i++){
        ll mn = 999999999999LL, temp = -1;
        for(int j = i; j < n ; j++){
            if(mn > a[j]){
                mn = a[j];
                temp = j;
            }
            cost[i][j] = temp;
        }
    }
    cout << best(0, n - 1, 0) << endl;
    return 0;
}