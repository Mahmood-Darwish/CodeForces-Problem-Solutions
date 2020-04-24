#include <iostream>

using namespace std;
int a[1000000];
int main()
{   long long int n,i,i2;
    cin>>n;
    for(int i=0;i<n;i++){
        a[i]=1;
        if(i>0)
        while(a[i]==a[i-1]){
            i--;
            n--;
            a[i]=a[i]+1;
        }
        }

    for(int i2=0;i2<n;i2++){
        cout<<a[i2]<<" ";
    }
    return 0;
}