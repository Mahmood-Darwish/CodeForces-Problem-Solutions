#include <bits/stdc++.h>

using namespace std;

int main()
{   string s1,s2;
    int p1,p2,first4s=0,second4s=0,diff,ans,ver=0;
    cin>>s1;
    p1=s1.size();
    for(int i=0;i<p1;i++){
        if(s1[i]=='4'){
            first4s++;
        }
    }
    cin>>s2;
    p2=s2.size();
    for(int i2=0;i2<p2;i2++){
        if(s2[i2]=='4'){
            second4s++;
        }
    }
    diff=abs(first4s-second4s);
    for(int i3=0;i3<p1;i3++){
        if(s1[i3]!=s2[i3]){
            ver++;
        }
    }
    ans=((ver-diff)/2)+diff;
    cout<<ans;
    return 0;
}