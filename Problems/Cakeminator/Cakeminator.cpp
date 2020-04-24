#include <bits/stdc++.h>

using namespace std;
int x,y,res,sum,i3,i4,i5,sure;
string s;
int a[1000];
int b[1000];
int main()
{
    cin>>x>>y;
    for(int i=0;i<x;i++){
        cin>>s;
        for(int i2=0;i2<y;i2++){
                if(s[i2]=='S'){
            a[i]=1;
            b[i2]=1;
            }
        }
    }
    for(int i=0;i<y;i++){
            for(int i2=0;i2<x;i2++){
                if(a[i2]==1&&b[i]==1){
                    sum++;
                }
            }
        }
    cout<<(x*y)-sum;
    return 0;
}