#include <iostream>
#include <string.h>

using namespace std;

long long a[10000000];
long long dp[1000000];
long long int ans,maxx,num;

long long fuct(int n){
    if(n>maxx) return 0;
    if(dp[n] != -1) return dp[n];
    return dp[n]=max((a[n]*n)+fuct(n+2),fuct(n+1));
}

int main()
{
    memset(dp,-1,sizeof(dp));
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>num;
        maxx=max(maxx,num);
        a[num]++;
    }
    ans=fuct(0);
    cout<<ans<<endl;
    return 0;
}