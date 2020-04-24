#include <iostream>
#include <stdio.h>

#define SF(x) scanf("%d", &x)

using namespace std;

long long n, k, ans = -1;
int a[10000000];

long long F(long long num, long long how_much)
{
    long long p = 1LL, j, c = 0LL;
    for (j = how_much ; j <= num ; j *= 2) {
        p *= 2;
    }
    c += max(p / 2, p - j + num);
    return c;
}

bool check(long long x)
{
    if(!x)
        return true;
    long long sum = 0LL, temp;
    for(int i = 1 ; i <= n ; i++){
        if(a[i] == x){
            sum++;
        }
        else{
            if(a[i] > x){
                temp = F(a[i], x);
                sum += temp;
            }
        }
    }
    return (sum >= k);
}

int main()
{
    cin >> n >> k;
    for(int i = 1 ; i <= n ; i++)
        SF(a[i]);
    long long low = 0, high = 1e10;
    while(low <= high){
        long long mid = (low + high) / 2;
        if(check(mid)){
            low = mid + 1;
            ans = mid;
        }
        else
            high = mid - 1;
    }
    if(!ans)
        cout << "-1\n";
    else
        cout << ans << endl;
    return 0;
}