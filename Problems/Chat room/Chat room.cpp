#include <iostream>
#include <string>
using namespace std;
int n,i,h,e,l,o;
string s;
int main()
{
    cin>>s;
    n=s.size();
    for(int i=0;i<n;i++){
        if(s[i]=='h'){
            h=1;
        }
        if(s[i]=='e'&&h==1){
            e=1;
        }
        if(s[i]=='l'&&e==1){
            l+=1;
        }
        if(s[i]=='o'&&l>=2){
            o=1;
        }
    }
    if(o==1){
        cout<<"YES";
    }
    else {
        cout<<"NO";
    }
    return 0;
}