#include <iostream>

using namespace std;

int main()
{
    int x,y,i,m;
    cin>>x>>y;
    if(x==1&&y==1||x==0||y==0){
        cout<<0;
        return 0;
    }
    for(int i=0;x>0&&y>0;i++){
        if(x>y){
            y++;
            x-=2;
        }
        else {
            if (x<=y){
                x++;
                y-=2;
            }
        }
    m=i;
    }
    cout<<m+1;
    return 0;
}