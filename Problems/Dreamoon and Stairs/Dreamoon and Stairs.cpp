#include <iostream>

using namespace std;
int x,n,m,i;
int main()
{
    cin>>n>>m;
    if(m>n){
        cout<<-1;
        return 0;
    }
    for(int i=0;i<=n;i++){
        if(i%m==0&&n>=i&&n<=i*2){
            cout<<i;
            return 0;
        }
    }
    return 0;
}