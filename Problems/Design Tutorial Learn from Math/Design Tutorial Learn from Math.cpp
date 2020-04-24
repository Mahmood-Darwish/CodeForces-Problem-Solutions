#include <iostream>

using namespace std;
int x;
int main ()
{
    cin>>x;
    if (x%2==0)
    {
        cout<<x-8<<" "<<8;
    }
    else cout<<9<<" "<<x-9;
    return 0;
}