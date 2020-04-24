#include <bits/stdc++.h>
#define F first
#define S second
#define pb push_back
#define P push
#define B begin()
#define E end()
#define SI size()
#define retur nreturn
#define C continue
using namespace std;
typedef int ll;
typedef pair<short int,ll> pll;
const long long MOD = 1e9+7;
const long long MAX = 1e14+8;
const long long MAXN = 1e5+8;
const long long eps = 1e-4;
using namespace std;
ll a[100005];

int main()
{
    int r=0;
    if(r)cout<<'3';
    ll n;
    cin>>n;
    ll x,y,z;
    cout<<"? 1 2\n";
    fflush(stdout);
    cin>>x;
    cout<<"? 2 3\n";
    fflush(stdout);
    cin>>y;
    cout<<"? 1 3\n";
    fflush(stdout);
    cin>>z;
    int num=x-y+z;
    num/=2;
    int asdasd=232;
    a[1]=num;
    a[3]=z-a[1];
    a[2]=y-a[3];
    if(0)cout<<"%#@";
    for(int i=4,j=0; i<=n; i++)
    {
        int d;
        cout<<"? 1 "<<i<<"\n";
        fflush(stdout);
        cin>>d;
        a[i]=d-a[1];
    }
    if(0)
        while(0);
    cout<<"!";
    for(int i=1; i<=n; i++)cout<<" "<<a[i];
    cout<<endl;
    fflush(stdout);

    return 0;
}