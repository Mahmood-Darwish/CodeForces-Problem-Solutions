#include <iostream>

using namespace std;
int n,k,num,num1,minn;
int a[100000];
int main()
{
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>num>>num1;
        if(num1<=k){
            a[i]=num;}
            else {
                a[i]=num-(num1-k);
            }
        }
    minn=a[0];
    for(int i=1;i<n;i++){
        if(minn<a[i]){
            minn=a[i];
        }
    }
    cout<<minn;
    return 0;
}