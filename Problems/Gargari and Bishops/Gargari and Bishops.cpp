#include <iostream>
#include <stdio.h>

using namespace std;

unsigned long long n , maxx1 , maxx2 , index1 = 1 , index2 = 1 , index3 = 1, index4 = 2;
int a[2010][2010];
bool b[2010][2010];
unsigned long long int c[100000];
unsigned long long int d[100000];

int main()
{
    scanf("%I64d",&n);
    for ( int i = 1 ; i <= n ; i++)
    {
        for ( int j = 1 ; j <= n ; j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    for ( int i = 1 ; i <= n ; i++)
        b[1][i] = ( i % 2 == 1);
    for ( int i = 2 ; i <= n ; i++)
    {
        for ( int j = 1 ; j <= n ; j++)
        {
            b[i][j] = 1 - b[i-1][j];
        }
    }
    for ( int i = 1 ; i <= n ; i++)
    {
        for ( int j = 1 ; j <= n ; j++)
        {
            c[4000 + (j - i)] += a[i][j];
            d[4000 + (i + j)] += a[i][j];
        }
    }
    for ( int i = 1 ; i <= n  ; i++)
    {
        for ( int j = 1 ; j <= n ; ++j)
        {
            if(b[i][j])
            {
                if( maxx1 <= d[4000 + (i+j)] + c[4000 + (j-i)] - a[i][j])
                {
                    maxx1 = d[4000 + (i+j)] + c[4000 + (j-i)] - a[i][j];
                    index1 = i;
                    index2 = j;
                }
            }
            else
            {
                if( maxx2 <= d[4000 + (i+j)] + c[4000 + (j-i)] - a[index3][index4])
                {
                    maxx2 = d[4000 + (i+j)] + c[4000 + (j-i)] - a[i][j];
                    index3 = i;
                    index4 = j;
                }
            }
        }
    }
    unsigned long long sum = maxx1 + maxx2 ;
    printf("%I64d\n" , sum);
    printf("%I64d %I64d %I64d %I64d\n" , index1 , index2 , index3 , index4);
    return 0;
}