#include <bits/stdc++.h>

using namespace std;
int a[1000][1000];
int num1,num2;
int main()
{
    for(int i=1;i<6;i++){
        for(int i2=1;i2<6;i2++){
            cin>>a[i][i2];
            if(a[i][i2]==1){
                num1=i;
                num2=i2;
        }
        }
    }
    cout<<abs(3-num1)+abs(3-num2);

    return 0;
}