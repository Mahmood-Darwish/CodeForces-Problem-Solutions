#include <iostream>

using namespace std;
long long int i=1,x,sum;
int sure;
int main()
{
    cin>>x;
    for(;;i++){
            sum+=1+i;
        if(sum>=x){
                sum-=1+i;
            for(int i2=1;;i2++){
                if(sum+1==x&&sure==0){
                    cout<<i;
                    return 0;
                }
                else {
                    sum++;
                    sure=1;
                    if(sum==x){
                        cout<<i2-1;
                        return 0;
                    }
                }
            }
        }
    }
    return 0;
}