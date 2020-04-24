#include <bits/stdc++.h>

using namespace std;
int a[31];
int k,i,r,res;
int main()
{
    cin>>k;
    for(i=0;i<12;i++){
        cin>>a[i];
    }
    if(k==0){
        cout<<0;
        return 0;
    }
    sort(a,a+12);
    for(r=11;r>=0;r--){
        k-=a[r];
        res++;
        if(k<=0){
            cout<<res;
            return 0;
        }
    }
    cout<<-1;
    return 0;
}