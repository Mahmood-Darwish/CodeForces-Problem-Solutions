#include <iostream>

using namespace std;
int x,y,a,b;
int main()
{
    cin>>a>>b;
    cout<<min(a,b)<<" ";
    x=max(a,b);
    y=x-min(a,b);
    cout<<y/2;
    return 0;
}