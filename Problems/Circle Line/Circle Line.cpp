#include <iostream>

using namespace std;
int n,had,s,t,sum1,sum2;
int a[100000];
int main()
{
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum2+=a[i];
    }
    cin>>s>>t;
    if(s<t){
    for(int i=s-1;i<t-1;i++){
            sum1+=a[i];
    }
    }
    else {
    for(int i=t-1;i<s-1;i++){
            sum1+=a[i];
    }
    }
    cout<<min(sum1,sum2-sum1);
    return 0;
}