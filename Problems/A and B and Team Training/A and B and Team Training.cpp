#include <iostream>

using namespace std;
long long int NB , XP , sum;
int main()
{
    cin>>XP>>NB;
    while((NB>=2&&XP>=1)||(XP>=2&&NB>=1)){
    if(XP>NB){
    XP-=2;
    NB--;
    sum++;
    }
    else {
        NB-=2;
        XP--;
        sum++;
    }
}
    cout<<sum;
    return 0;
}