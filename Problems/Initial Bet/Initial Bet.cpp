#include <iostream>

using namespace std;
int a[6];
int main()
{
    for(int i=0;i<5;i++){
        cin>>a[i];
    }
    if(((a[0]+a[1]+a[2]+a[3]+a[4])%5!=0)||(a[0]+a[1]+a[2]+a[3]+a[4])==0){
        cout<<-1;
        return 0;
    }
    else {
        cout<<(a[0]+a[1]+a[2]+a[3]+a[4])/5;
        return 0;
    }
    return 0;
}