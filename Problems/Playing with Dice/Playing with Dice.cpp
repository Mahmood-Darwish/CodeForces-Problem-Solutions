#include <bits/stdc++.h>

using namespace std;
int a,b,wina,winb,draw;
int main()
{
    cin>>a>>b;
    for(int i=1;i<=6;i++){
        if(abs(a-i)>abs(b-i)){
            wina++;
        }
        else {
        if(abs(a-i)<abs(b-i)){
            winb++;
        }
        else {
            draw++;
        }
        }
    }
    cout<<winb<<" "<<draw<<" "<<wina;
    return 0;
}