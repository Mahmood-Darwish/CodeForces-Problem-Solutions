#include <iostream>

using namespace std;
int i,i2,sum;
char char1;
int a[10000];
int main()
{
    for(;;){
        cin>>char1;
        if(char1=='{'||char1==','||char1==' '){
            continue;
        } else {
        if(char1=='}'){
            break;
        }
        else { a[(int)char1]=1;
        i++;
    }}}
    for(int i=0;i<173;i++){
        sum+=a[i];
    }
    cout<<sum;

    return 0;
}