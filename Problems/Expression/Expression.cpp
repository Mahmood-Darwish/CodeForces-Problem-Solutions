#include <iostream>

using namespace std;
int a,b,c,res;
int main()
{
    cin>>a>>b>>c;
    res=max(a+b+c,max(a+b*c,max(a*b+c,max(a*b*c,max((a+b)*c,a*(b+c))))));
    cout<<res;
    return 0;
}