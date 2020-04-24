#include <bits/stdc++.h>
#define F first
#define S second

using namespace std;
typedef long long ll;

ll n , num1 , num2 , note , q;
ll w = 0;

set < int > mys[1000000];
vector < pair < pair < int , int > , int  > > a;

int main()
{
    scanf("%I64d %I64d " ,&n , &q);
    for(int i = 1 , p = 0; i <= q ; i++)
    {
        scanf("%I64d %I64d",&num1 , &num2);
        if(num1 == 1)
        {
            note++;
            mys[num2].insert(p);
            a.push_back(make_pair(make_pair(p , num2),0));
            p++;
            printf("%I64d\n" , note);
        }
        if(num1 == 2)
        {
            for (set < int >::iterator it = mys[num2].begin() ; it != mys[num2].end() ; it++)
            {
                int num = (*(it));
                if(a[num].S == 0){
                note--;
                a[num].S = 1;
                }
            }
            mys[num2].clear();
            printf("%I64d\n" , note);
        }
        if(num1 == 3)
        {
            for ( int o = w; o < num2 ; o++ , w++)
            {
                if(a[w].S == 0){
                a[w].S = 1;
                note--;
                }
            }
            printf("%I64d\n" , note);
        }
    }
    return 0;
}