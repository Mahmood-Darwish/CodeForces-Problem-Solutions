#include <bits/stdc++.h>

using namespace std;
int res [100];

main(){
int b,bottens,i,j,bottens1,bulbs;
cin>>bottens>>bulbs;
for(i=0;i<bottens;i++)
    {
    cin>>b;
    for(int j=1;j<=b;j++){
    cin>>bottens1;
    res[bottens1]=1;
        }
    }
    for(int i=1;i<=bulbs;i++)
    {
    if(res[i]==0){cout<<"NO";
    return 0; 
    }
   
       }
       cout<<"YES"; 
return 0;
}