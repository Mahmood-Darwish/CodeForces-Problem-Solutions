#include <iostream>

using namespace std;
long long int n,m,num,sum,c,currently;
int b[100000];
int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>b[i];
    }
    currently=1;
    c=1;
    for(int i=1;;i++){
        if(b[c]>=currently){
            sum+=b[c]-currently;
            currently=b[c];
            c++;
            m--;
        }
        else {
            sum+=n-(currently-b[c]);
            currently =b[c];
            c++;
            m--;
        }
        if(m<=0){
            break ;
        }
    }
    cout<<sum;
    return 0;
}