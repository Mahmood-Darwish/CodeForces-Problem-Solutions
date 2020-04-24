#include <iostream>

using namespace std;
int n,k,sum;
int a[100000];
int main()
{
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        if(a[i]+k<=5){
            sum++;
        }
    }
    cout<<sum/3;
    return 0;
}