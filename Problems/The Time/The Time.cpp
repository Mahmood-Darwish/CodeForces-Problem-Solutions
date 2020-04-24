#include <bits/stdc++.h>

using namespace std;
int a,hh,mm;
string s;
int main()
{
    cin>>s;
    cin>>a;
    hh=((int)(s[0]-48)*10)+((int)s[1]-48);
    mm=((int)(s[3]-48)*10)+((int)s[4]-48);
    for(int i=0;i<a;i++){
        mm++;
        if(mm==60){
            mm=0;
            hh++;
            if(hh==24){
                hh=0;
            }
        }
    }
    if(hh/10==0)
        cout<<0;
    cout<<hh<<":";
    if(mm/10==0){
        cout<<0<<mm;
    }
    else {
        cout<<mm;
    }
    return 0;
}