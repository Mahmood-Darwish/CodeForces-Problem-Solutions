#include <iostream>
#include <stdio.h>

using namespace std;

long long t, l, B, A, m, n, a[2000100];

bool check(long long x)
{
    if(a[x] - a[l - 1] <= m * t && t >= A + ((x - 1) * B))
        return true;
    return false;
}

int main()
{
    cin >> A >> B >> n;
    for(int i = 1 ; i <= 2000050 ; i++){
        a[i] = a[i - 1] + (A + ((i - 1) * B));
    }
    while(n--){
        scanf("%I64d %I64d %I64d", &l, &t, &m);
        if(A + ((l - 1) * B) > t){
            printf("-1\n");
            continue;
        }
        long long low = 1, high = 1e6 + l, ans = 0;
        while(low <= high){
            long long mid = (low + high) / 2;
            //cout << mid << endl;
            if(check(mid)){
                low = mid + 1;
                ans = mid;
            }
            else{
                high = mid - 1;
            }
        }
        printf("%I64d\n", ans);
    }
    return 0;
}