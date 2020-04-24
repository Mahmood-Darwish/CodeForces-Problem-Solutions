#include <iostream>

using namespace std;

long long x1 , x2 , y1 , y2 , a , b , c , n , sum;

int main()
{
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> n;
    for(int i = 0 ; i < n ; i++)
    {
        cin >> a >> b >> c;
        if((((a*x1) + (b*y1) + c) > 0) ^ (((a*x2) + (b*y2) + c) > 0))
            sum++;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            
    }
    cout << sum;
    return 0;
}