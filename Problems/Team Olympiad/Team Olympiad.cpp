#include <iostream>

using namespace std;
int n,min1,min2,min3,found1,found2,found3,minn;
int a[100000];
int main()
{
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]==1){
            min1++;
        }
            else {
                if(a[i]==2){
                    min2++;
                }
                else {
                    min3++;
                }
            }
        }
    minn=min(min3,min(min2,min1));
    cout<<min(min3,min(min2,min1))<<endl;
    for(int i2=0;i2<minn;i2++){
    for(int i=0;i<n;i++){
        if(a[i]==1&&found1==0){
            cout<<i+1<<" ";
            a[i]=-1;
            found1=1;
        }
        if(a[i]==2&&found2==0){
            cout<<i+1<<" ";
            a[i]=-1;
            found2=1;
        }
        if(a[i]==3&&found3==0){
            cout<<i+1<<" ";
            a[i]=-1;
            found3=1;
        }
    }
    cout<<endl;
    found1=found2=found3=0;
}
    return 0;
}