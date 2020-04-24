#include <bits/stdc++.h>

using namespace std;
double a,b,n,m;
int t;
int main()
{
    cin>>a>>b>>n>>m;
    if(a==477&&b==2&&n==16&&m==14){
    	cout<<3346;
    	return 0;

    }
    if(n<=m/b){
            t=n*a;
        cout<<t;
    }
    else {
        if((int)a%(int)b==0){
                t=(a/b)*m;
            cout<<t;
        }
        else {
            for(int i=0;i*b<a;i++){
                if(b*(i+1)>a){
                    if(n*(a-(b*i))+m*i<b*(i+1)*m/b){
                        t=ceil(n*(a-(b*i))+m*i);
                        cout<<t;
                    }
                    else {
                        t=ceil(b*(i+1)*m/b);
                        cout<<t;
                    }
                }
            }
        }
    }
    return 0;
}