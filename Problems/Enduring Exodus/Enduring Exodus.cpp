#include <iostream>
#include <cmath>

using namespace std;

long long n , k , sum , minn = 9999999999999 , j , pos , cur;
string s;

int last(int num)
{
    while(s[num] == '1')
        num--;
    return num;
}


int next(int num)
{
    while(s[num] == '1')
        num++;
    return num;
}

int main()
{
    cin >> n >> k;
    cin >> s;
    for(int i = 0 ; i < n ; i++)
    {
        if(s[i] == '0')
        {
            sum++;
            if(sum == k+1)
            {
                for( ; j <= i ; j++)
                {
                    if(s[j] == '0')
                        break;
                }
                int pos1 = last((i+j)/2);
                int pos2 = next((i+j)/2);
                int num1 = max(pos1 - j,(long long)i - pos1);
                int num2 = max(pos2 - j,(long long)i - pos2);
                if( num1 <= num2 )
                {
                    cur = pos1;
                }
                else cur = pos2;
                minn = min (minn ,max(cur - j , i - cur));
                j++;
                sum--;
            }
        }
    }
    cout << minn;
    return 0;
}