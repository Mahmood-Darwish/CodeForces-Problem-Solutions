#include <iostream>

using namespace std;

int n , d , h , ans;
pair < int , int > a[1000000];

int main()
{
    bool sure = false;
    cin >> n >> d >> h;
    if( (d == 1 && n != 2) || 2 * h < d || d > n || (n == 2 && h == 2))
    {
        cout << -1;
        return 0;
    }
    int i = 2 , num = i - 1 , sum = 0 , num2 = h;
    while(ans < n - 1)
    {
        for( ; i <= n ; i++)
        {
            a[i] = make_pair( i , num );
            sum++;
            ans++;
            if(!sure)
                num = i;
            if(sum == num2){i++;num2 = d - h;break;}
        }
        sum = 0;
        if(d == h){num = 2;sure = true;}
        else num = 1;
    }
    for(int i = 2 ; i <= n ; i++)
    {
        cout << a[i].first << " " << a[i].second << endl;
    }
    return 0;
}