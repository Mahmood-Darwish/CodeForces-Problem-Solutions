#include <iostream>

using namespace std;
int n,res,i,i2,l,j;
int a[100][100];
int main()
{
    cin>>n;
    for(int i=0;i<n;i++){
            for(int i2=0;i2<2;i2++)
            cin>>a[i][i2];
    }
    for(int j=0;j<n;j++){
        for(int l=0;l<n;l++){
            if(a[l][0]==a[j][1]&&j!=l){
                res++;
            }
        }
    }
    cout<<res;
    return 0;
}