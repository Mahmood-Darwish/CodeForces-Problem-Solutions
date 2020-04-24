#include <iostream>

using namespace std;
int b,n,k;
int a[1000];
int main()
{
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n-1;i++){
        b=max(b,a[i]-a[i+1]-k);
    }
    cout<<b;
    return 0;
}