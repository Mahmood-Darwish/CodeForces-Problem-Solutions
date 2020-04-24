#include <bits/stdc++.h>
#define SF(x) scanf("%I64d",&x)
#define F first
#define S second
#define MEM(a,b) memset(a,b,sizeof(a))
#define DB(x) cout << #x << " is " << x << endl
#define ffs(x) __builtin_ffs(x) // This function returns 1 + least significant 1-bit of x. If x == 0, returns 0. Here x is int, this function with suffix 'l' gets a long argument and with suffix 'll' gets a long long argument.
#define clz(x) __builtin_clz(x) // This function returns number of leading 0-bits of x which starts from most significant bit position. x is unsigned int and like previous function this function with suffix 'l gets a unsigned long argument and with suffix 'll' gets a unsigned long long argument. If x == 0, returns an undefined value.
#define ctz(x) __builtin_ctz(x) // This function returns number of trailing 0-bits of x which starts from least significant bit position. x is unsigned int and like previous function this function with suffix 'l' gets a unsigned long argument and with suffix 'll' gets a unsigned long long argument. If x == 0, returns an undefined value.
#define popcount(x) __builtin_popcount(x) // This function returns number of active bits in the binary represintation of the number
#define pb push_back

using namespace std;
typedef long long ll;

ll INF = (1 << 29);

ll Mypow(ll X,ll Y){
    if(Y < 0)return 0;
    if(Y == 0)return 1;
    if(Y == 1){
        return X;
    }
    else{
        ll x = Mypow(X ,Y / 2);
        x *= x;
        if(Y % 2)
            return (x * X);
        else
            return x;
    }
}

int n, k, q, a ,b, sum;
int arr[200100];
vector < int > V;

int bs1(int x, int y)
{
    int ans = -1;
    int low = 0, high = V.size() - 1;
    while(low <= high){
        int mid = (low + high )/ 2;
        if(V[mid] >= x && V[mid] <= y){
            ans = mid;
            high = mid - 1;
        }
        else{
            if(V[mid] < x)
                low = mid + 1;
            else high = mid - 1;
        }
    }
    return ans;
}

int bs2(int x, int y)
{
    int ans = -1;
    int low = 0, high = V.size() - 1;
    while(low <= high){
        int mid = (low + high )/ 2;
        if(V[mid] >= x && V[mid] <= y){
            ans = mid;
            low = mid + 1;
        }
        else{
            if(V[mid] < x)
                low = mid + 1;
            else high = mid - 1;
        }
    }
    return ans;
}

int main()
{
    cin >> n >> k >> q;
    for(int i = 1 ; i <= n ; i++){
        scanf("%d %d", &a ,&b);
        arr[a]++;
        arr[b + 1]--;
    }
    for(int i = 1 ; i <= 200050 ; i++){
        sum += arr[i];
        if(sum >= k){
            V.push_back(i);
        }
    }
    while(q--){
        scanf("%d %d", &a, &b);
        if(bs1(a, b) == -1){
            printf("0\n");
            continue;
        }
        printf("%d\n", bs2(a, b) - bs1(a, b) + 1);
    }
    return 0;
}