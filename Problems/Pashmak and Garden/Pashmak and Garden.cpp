#include <bits/stdc++.h>

using namespace std;

int main()
{
    int x1,x2,x3,x4,y1,y2,y3,y4;
    cin>>x1>>y1>>x2>>y2;
    if(x1==x2){
    y3=y1;
    y4=y2;
    x3=abs(y1-y2)+x2;
    x4=abs(y1-y2)+x1;
    }
    else {
        if(y1==y2){
            x3=x1;
            x4=x2;
            y3=abs(x1-x2)+y2;
            y4=abs(x1-x2)+y1;
        }
        else {
            x3=x1;
            y3=y2;
            x4=x2;
            y4=y1;
            if(abs(x1-x2)!=abs(y1-y2)){
                cout<<-1;
                return 0;
            }
        }
    }

    cout<<x3<<" "<<y3<<" "<<x4<<" "<<y4;
    return 0;
}