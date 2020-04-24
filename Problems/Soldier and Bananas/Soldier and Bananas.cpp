#include <iostream>

using namespace std;
int k,w,n,sum;
int main()
{
    cin>>k>>n>>w;
    for( int i=0;i<=w;i++){
        sum+=i*k;
    }
    if(n-sum>=0)
    {
        cout<<0;
    }
    else
    cout<<sum-n;
    return 0;
}