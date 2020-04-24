#include <iostream>
#include <string>
using namespace std;
string s1,s2;
int n,i,i2,i3,fok,taht,res;
int main()
{
    cin>>n;
    cin>>s1;
    cin>>s2;
    for(int i=0;i<n;i++){
        for(i2=s1[i]-48;i2!=s2[i]-48;i2++){
            if(i2==10){
                i2=0;
    if(i2==s2[i]-48){
        break;
         }
            }
            fok++;
        }
        for(i3=(int)s1[i]-48;i3!=(int)s2[i]-48;i3--){
            if(i3==-1){
                i3=9;
            if(i3==s2[i]-48){
                break;
                }
            }
            taht++;
        }
        res+=min(taht,fok);
        taht=fok=0;
    }
    cout<<res;
    return 0;
}