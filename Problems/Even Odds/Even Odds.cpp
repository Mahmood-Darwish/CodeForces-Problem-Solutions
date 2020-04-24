#include <iostream>

using namespace std;
long long int n,k,res;
int main ()
{
    cin >> n >>k;
    if (n%2!=0){
    if (k<=(n/2)+1)
        res=(k*2)-1;
    else{
        k-=(n/2)+1;
        res=k*2;
        }
    cout << res;
    }
    else
    {
        if (k<=n/2)
            res=(k*2)-1;
        else{
            k-=n/2;
            res=k*2;
        }
     cout << res;
    }
    return 0;
}