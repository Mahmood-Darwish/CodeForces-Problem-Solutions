#include <iostream>

using namespace std;
int s,sum,n,num,maxx;
int a[1000000];
int main()
{
    cin>>n>>s;
    cin>>num;
    sum+=num;
    maxx=num;
    for(int i=0;i<n-1;i++){
        cin>>a[i];
        maxx=max(maxx,a[i]);
        sum+=a[i];
    }
    sum-=maxx;
    if(sum>s){
        cout<<"NO";
    }
    else {
        cout<<"YES";
    }
    return 0;
}