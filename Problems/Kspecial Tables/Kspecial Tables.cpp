#include <iostream>

using namespace std;

long long temp = 1 , n , k , a[600][600] , sum;

int main()
{
    cin >> n >> k;
    k--;
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < k ; j++)
        {
            a[i][j] = temp;
            temp++;
        }
    }
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = k ; j < n ; j++)
        {
            if(j == k)
                sum += temp;
            a[i][j] = temp;
            temp++;
        }
    }
    cout << sum << '\n';
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < n ; j++)
            cout << a[i][j] << " ";
        cout << '\n';
    }
    return 0;
}