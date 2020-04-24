#include <bits/stdc++.h>

using namespace std;
int x,t,y;
int main()
{
    cin>>x;
    t=x%10;
    y=x%100-t;
    if(x<0){
    if(((x/100)*10)+t<=x/10){

            cout<<x/10;

    }
    else {
        cout<<((x/100)*10)+t;
    }
    }
    else {
        cout<<x;
    }

    return 0;
}