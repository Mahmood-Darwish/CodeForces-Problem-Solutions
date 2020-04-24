#include <bits/stdc++.h>

using namespace std;
int n,t;
char r;
string s;
int main()
{
    cin>>n>>t;
    cin>>s;
    for(int i=0;i<t;i++){
        for(int i2=0;i2<n;i2++){
            if(s[i2]=='B' && s[i2+1]=='G'){
                r=s[i2];
                s[i2]=s[i2+1];
                s[i2+1]=r ;
                i2++;
            }
        }
    }
    cout<<s;
    return 0;
}