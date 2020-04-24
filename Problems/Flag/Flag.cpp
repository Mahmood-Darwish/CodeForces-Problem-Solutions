#include <iostream>
#include <string>
using namespace std;
int m,n,i,i2,i3,i4,bad;
string s;
int a[1000000];
int main()
{
    cin>>n>>m;
    for(i=0;i<n;i++){
        cin>>s;
        for(i2=0;i2<m;i2++){
            if(s[0]!=s[i2]){
                bad=1;
            }
        }
        a[i]=s[0];
    }
    if(bad==1){
        cout<<"NO";
        return 0;
    }
    for(i3=0;i3<n;i3++){
        for(i4=0;i4<n;i4++){
            if(a[i3]==a[i4] && (i3==i4+1 || i3==i4-1)){
                    cout<<"NO";
                    return 0;
            }
        }
    }
    cout<<"YES";
    return 0;
}