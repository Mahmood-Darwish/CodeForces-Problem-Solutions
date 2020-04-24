#include <iostream>
using namespace std;
int a[100000];
int main() {
    int n,n1,n2,n3,i,i2,i3;
    cin>>n;
    cin>>n1>>n2>>n3;
    for(int i=3;i<n;i++){
        cin>>a[i];
    }
    if(n1%2==0 && n2%2==0 && n3%2!=0){
        cout<<3;
        return 0;
    }
        if(n1%2==0 && n2%2!=0 && n3%2==0){
        cout<<2;
        return 0;
    }
        if(n1%2!=0 && n2%2==0 && n3%2==0){
        cout<<1;
        return 0;
    }
        if(n1%2==0 && n2%2!=0 && n3%2!=0){
        cout<<1;
        return 0;
    }
        if(n1%2!=0 && n2%2==0 && n3%2!=0){
        cout<<2;
        return 0;
    }
        if(n1%2!=0 && n2%2!=0 && n3%2==0){
        cout<<3;
        return 0;
    }
        if(n1%2==0 && n2%2==0 && n3%2==0){
        for( int i2=3;i2<n;i2++){
            if(a[i2]%2!=0){
                cout<<i2+1;
                return 0;
            }
        }
    }
        if(n1%2!=0 && n2%2!=0 && n3%2!=0){
            for(int i3=3;i3<n;i3++)
            if(a[i3]%2==0){
                cout<<i3+1;
                return 0;
            }
    }
    return 0;
}