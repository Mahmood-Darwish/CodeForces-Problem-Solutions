#include <bits/stdc++.h>

using namespace std;

int main()
{   string s1,s2,s3;
    int p,p2,p3,i,i2,i3,i4,i5,i6;
    cin>>s1;
    cin>>s2;
    cin>>s3;
    p=s1.size();
    p3=s3.size();
    p2=s2.size();
    if(p+p2!=p3){
        cout<<"NO";
        return 0;
    }
    for(i=0;i<p;i++)
    {
        for(i2=0;i2<p3;i2++){
            if(s1[i]==s3[i2]){
                s1[i]='1';
                s3[i2]='1';
                break;
            }
        }
        i2=0;
    }
        for(i3=0;i3<p2;i3++){
        for(i4=0;i4<p3;i4++){
            if(s2[i3]==s3[i4]){
                s2[i3]='1';
                s3[i4]='1';
            }
        }
        i4=0;
    }
    for(i5=0;i5<p;i5++){
        if(s1[i5]!='1'){
            cout<<"NO";
            return 0;
        }
    }
        for(i6=0;i6<p2;i6++){
        if(s2[i6]!='1'){
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";
    return 0;
}