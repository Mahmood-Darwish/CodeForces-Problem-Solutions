#include <iostream>
using namespace std;

int main() {
    int n,p,i;
    string y;
    cin>>n;
    for(i=0;i<n;i++){
        cin>> y;
        p=y.size();
        if(p>10){
            cout<<y[0];
            cout<<p-2;
            cout<<y[p-1];
            cout<<endl;
        }
        else
        cout<<y;
        cout<<endl;
    }
    
    return 0;
}