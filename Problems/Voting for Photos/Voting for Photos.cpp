#include <iostream>

using namespace std;
int a[1000000];
int main()
{
    int n,num,maxx,minn;
    cin>>n;
    cin>>num;
    a[num]++;
    maxx=a[num];
    minn=num;
    for(int i=1;i<n;i++){
        cin>>num;
        a[num]++;
        if(maxx<a[num]) {minn=num;
        maxx=a[num];
    }
    }
    cout<<minn;
    return 0;
}