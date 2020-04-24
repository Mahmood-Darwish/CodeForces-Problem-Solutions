#include <iostream>

using namespace std;
int s,n;
int a[2000];
int b[2000];
int main()
{
    cin>>s>>n;
    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i];
    }
    for(int i=0;i<n;i++){
        for(int i2=0;i2<n;i2++){
            if(s>a[i2]&&a[i2]!=-1){
                s+=b[i2];
                a[i2]=-1;
            }
        }
    }
    for(int i=0;i<n;i++){
        if(a[i]!=-1){
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";
    return 0;
}