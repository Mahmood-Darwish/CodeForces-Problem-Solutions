#include <iostream>

using namespace std;
int n,k,l,c,d,p,nl,np,litter,limes,res;
int main()
{
    cin>>n>>k>>l>>c>>d>>p>>nl>>np;
    litter=k*l;
    limes=c*d;
    res=min((litter/nl)/n,min(limes/n,(p/np)/n));
    cout<<res;
    return 0;
}