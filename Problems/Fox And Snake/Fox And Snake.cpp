#include <iostream>

using namespace std;
int r,k,sure=1;
int main()
{
    cin>>r>>k;
    for(int i=0;i<r;i++){
        for(int i2=0;i2<k;i2++){
            cout<<"#";
        }
        cout<<endl;
        i++;
        if(i==r){
        cout<<endl;
        return 0;}
        if(sure==0){
            sure=1;
            cout<<"#";
            for(int i3=0;i3<k-1;i3++){
                cout<<".";
            }
            cout<<endl;
        }
        else {
            sure =0;
            for(int i3=0;i3<k-1;i3++){
                cout<<".";
            }
            cout<<"#"<<endl;

        }

    }
    return 0;
}