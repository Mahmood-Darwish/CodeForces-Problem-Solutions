#include <iostream>

using namespace std;
int n,forcap,forcaps=1,backk,backs=1,chests,chest;
int a[100];
int main()
{
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        if(forcaps==1&&backs==1){
            chest+=a[i];
            chests=1;
            forcaps=0;
        }
        else{
        if(chests==1&&backs==1){
            forcap+=a[i];
            forcaps=1;
            backs=0;
        }
        else {
        if(forcaps==1&&chests==1){
            backk+=a[i];
            chests=0;
            backs=1;
        }
    }}}
    if(backk>=forcap&&backk>=chest){
        cout<<"back";
        return 0;
    }
    if(forcap>=backk&&forcap>=chest){
    cout<<"biceps";
    return 0;
    }
    if(chest>=forcap&&chest>backk){
    cout<<"chest";
    return 0;
    }
    return 0;
}