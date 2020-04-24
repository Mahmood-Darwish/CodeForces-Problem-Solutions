#include <iostream>

using namespace std;
int a,b,i,d,res,n;
int main()
{
    cin>>a>>b;
    for(i=a;i<=b;i++){
            n=i;
            while(n>=1){
        d=n%10;
        if(d==0){
            res+=6;
        }
        else if(d==1){
            res+=2;
        }
         else if(d==2){
            res+=5;
        }
         else if(d==3){
            res+=5;
        }
         else if(d==4){
            res+=4;
        }
         else if(d==5){
            res+=5;
        }
         else if(d==6){
            res+=6;

         }
          else if(d==7){
            res+=3;
        }
         else if(d==8){
            res+=7;
        }
         else if(d==9){
            res+=6;
        }
        n=n/10;
    }
    }
    cout<<res;
    return 0;
}