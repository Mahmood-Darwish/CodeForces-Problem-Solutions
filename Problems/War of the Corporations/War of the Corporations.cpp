#include <iostream>
#include <string>
using namespace std;
int p,p2,i,i2,i3,sum,found;
string s,s2;
int main()
{
    cin>>s;
    cin>>s2;
    p=s.size();
    p2=s2.size();
    for(int i=0;i<p;i++){
        for(int i2=i,i3=0;i3<p2;i2++,i3++){
            if(s[i2]!=s2[i3]){
                found=1;
            }
        }
        if(found!=1){
           sum++;
           i+=p2-1;
        }
        found=0;
    }
    cout<<sum;
    return 0;
}