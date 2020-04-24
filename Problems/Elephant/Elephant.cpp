#include <iostream>

using namespace std;
int x,i;
int main()
{
    cin>>x;
    for(i=0;x>0;i++){
            if(x>=5){
        x=x-5;
            }
            else{
                i++;
                break;
            }

    }
    cout<<i;
    return 0;
}