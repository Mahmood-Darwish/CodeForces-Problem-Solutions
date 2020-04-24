#include <iostream>

using namespace std;
int t;
int gcd(int a,int b){
    while (b != 0){
       t = b;
       b = a % b;
       a = t;
    }
    return a;
}
int n,a[100000],sum,b[100000],m;
int main()
{
    cin>>n;
    cin>>a[0];
    for(int i=1;i<n;i++){
        cin>>a[i];
        m=gcd(a[i],a[i-1]);
        if(m!=1){
            for(int i2=1;i2<=min(a[i],a[i-1]);i2++){
                if(gcd(a[i],i2)==1&&gcd(a[i-1],i2)==1){
                    b[i-1]=i2;
                    sum++;
                    break;
                }
            }
        }
    }
    cout<<sum<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
        if(b[i]) cout<<b[i]<<" ";
    }
    return 0;
}