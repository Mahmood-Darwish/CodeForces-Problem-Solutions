#include <iostream>

using namespace std;
int k,sum,i,i2;
char a[1000][1000];
int main()
{
    cin>>k;
    for(int i=0;i<k;i++){
        for(int i2=0;i2<k;i2++){
            cin>>a[i][i2];
        }
    }
    for(int i=0;i<k;i++){
        for(int i2=0;i2<k;i2++){
            if(a[i][i2+1]=='o'){
                sum++;
            }
            if(a[i][i2-1]=='o'&&i2!=0){
            sum++;
            }
            if(a[i+1][i2]=='o'){
            sum++;
            }
            if(a[i-1][i2]=='o'&&i!=0){
            sum++;
            }
            if(sum%2==0){
                continue;
            }
            else {
                cout<<"NO";
                return 0;
            }
        }
    }
    cout<<"YES";
    return 0;
}