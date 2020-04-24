#include<iostream>
using namespace std;
int main(){
    int n,p1,p2,p3,i,sum=0;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>p1>>p2>>p3;
        if(p1+p2+p3>=2){
        sum=sum+1;
    }
    }
    cout<<sum;

    return 0;
}