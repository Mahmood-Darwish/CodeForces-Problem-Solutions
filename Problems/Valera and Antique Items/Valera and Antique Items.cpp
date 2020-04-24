#include <iostream>

using namespace std;
int n,sum,k,num,r,i;
bool a[100000];
bool found;
int main()
{
    cin>>n>>sum;
    for(int i=0;i<n;i++){
        cin>>k;
        for(int i2=0;i2<k;i2++){
            cin>>num;
            if(sum>num&&found ==0){
                a[i+1]=1;
                r++;
                found=1;
            }}
            found =0;
    }
    cout<<r<<endl;
    for(int i=0;i<=n;i++){
        if(a[i]==1){
            cout<<i<<" ";
        }

    }
    return 0;
}