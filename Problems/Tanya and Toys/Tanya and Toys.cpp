#include <iostream>
#include <vector>
using namespace std;
vector <bool> a(1000000100);
int n,k,i,i2,sum,num;
int b[1000000];
int main()
{
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>num;
        a[num]=true;
    }
    for(int i=1;i<=1000000000;i++){
        if((!a[i])&&(k-i>=0)){
            k-=i;
            sum++;
            a[i]=true;
            b[i2]=i;
            i2++;
            if(k<=i) break;
        }
            if(k<=i) break;
    }
    cout<<sum<<endl;
    for(int i=0;i<sum;i++)
        cout<<b[i]<<" ";
    return 0;
}