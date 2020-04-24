#include <iostream>

using namespace std;
int x,w[1000],q[1000];
int main()
{
    cin >> x;
    for (int i=0;i<x;i++)
        cin >> w[i];
    for (int i=0;i<x;i++)
        q[w[w[i]]-1]=w[i];
    for (int i=0;i<x;i++)
        cout << q[i]+1 << " ";
    return 0;
}