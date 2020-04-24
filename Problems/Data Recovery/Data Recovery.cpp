#include <iostream>

using namespace std;

int n , m , minn , maxx , a[1000] , sure , sure2 , sum;
bool b[10000];

int main()
{
    cin >> n >> m >> minn >> maxx;
    for(int i = 0 ; i < m ; i++)
    {
           cin >> a[i];
           if(a[i] == minn)sure = 1;
           if(a[i] == maxx)sure2 = 1;
           if(a[i] > maxx || a[i] < minn)
           {
               cout << "Incorrect";
               return 0;
           }
           if(b[a[i]] != true){b[a[i]] = true;sum++;}
    }
    if(n - m >= 2 - (sure + sure2) && n - m <= n - sum)
        cout << "Correct";
    else cout << "Incorrect";
    return 0;
}