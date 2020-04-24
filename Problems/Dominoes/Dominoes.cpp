#include <iostream>

using namespace std;

int n , m , sum11 , sum10 , sum01 , sum00;
char a[1010][3000] , ans[1010][3000];
bool sure;

int main()
{
    cin >> n >> m;
    for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; j < m * 2 ; j++)
             cin >> a[i][j];
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < m * 2 ; j += 2)
        {
            if(a[i][j] == a[i][j+1] && a[i][j] == '1')
                sum11++;
            if(a[i][j] != a[i][j+1] && a[i][j] == '1')
                sum10++;
            if(a[i][j] != a[i][j+1] && a[i][j] == '0')
                sum10++;
            if(a[i][j] == a[i][j+1] && a[i][j] == '0')
                sum00++;
        }
    }
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < m ; j++)
        {
            if(sum11){cout << "11 ";sum11--;}
            else if(sum10+j >= m && (i % 2 == 0)){cout << "10 ";sum10--;}
            else if(sum10+j >= m){cout << "01 ";sum10--;}
            else cout << "00 ";
        }
        cout << '\n';
    }
    return 0;
}