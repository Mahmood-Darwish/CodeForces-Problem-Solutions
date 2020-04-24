#include <iostream>

using namespace std;
int n,d,sum,farag,jokes,f;
int a[100000];
int main()
{
    cin>>n>>d;
    for(int i=0;i<n;i++){
    cin>>a[i];
    sum+=a[i];
    }
    farag=(n-1)*10;
    jokes=farag/5;
    if(farag+sum>d){
        cout<<-1;
    }
    else if(farag+sum==d){
        cout<<jokes;
    }
    else {
        f=d-(farag+sum);
        jokes+=f/5;
        cout<<jokes;
    }
    return 0;
}