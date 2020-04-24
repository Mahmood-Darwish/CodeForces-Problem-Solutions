#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


bool comp(pair < ll , ll > a , pair < ll , ll > b)
{
    a.first = abs(a.first);
    a.second = abs(a.second);
    b.first = abs(b.first);
    b.second = abs(b.second);
    return a < b;
}


pair < ll , ll > a[2000000];
pair < ll , pair < ll , char > > ans[2000000];
ll n , sum;


int main()
{
    cin >> n;
    for(int i = 0 ; i < n ; i++)
        scanf("%I64d %I64d" , &a[i].first , &a[i].second);
    sort(a,a+n,comp);
    for(int i = 0 , k = 0; i < n ; i++ , k += 6)
    {
        if(a[i].second != 0){
        ans[k].first = 1;
        ans[k].second.first = abs(a[i].second);
        if(a[i].second >= 0) ans[k].second.second = 'U';
        else ans[k].second.second = 'D';
        sum++;
        }
        if(a[i].first != 0){
        ans[k+1].first = 1;
        ans[k+1].second.first = abs(a[i].first);
        if(a[i].first >= 0) ans[k+1].second.second = 'R';
        else ans[k+1].second.second = 'L';
        sum++;
        }
        ans[k+2].first = 2;
        sum++;
        if(a[i].second != 0){
        ans[k+3].first = 1;
        ans[k+3].second.first = abs(a[i].second);
        if(a[i].second >= 0) ans[k+3].second.second = 'D';
        else ans[k+3].second.second = 'U';
        sum++;
        }
        if(a[i].first != 0){
        ans[k+4].first = 1;
        ans[k+4].second.first = abs(a[i].first);
        if(a[i].first >= 0) ans[k+4].second.second = 'L';
        else ans[k+4].second.second = 'R';
        sum++;
        }
        ans[k+5].first = 3;
        sum++;
    }
    printf("%I64d\n",sum);
    for(int i = 0 ; i < n * 6 ; i++)
    {
        if(ans[i].first == 1)
            printf("%I64d %I64d %c\n" , ans[i].first , ans[i].second.first , ans[i].second.second);
        if(ans[i].first == 2)
            printf("%I64d\n" , ans[i].first);
        if(ans[i].first == 3)
            printf("%I64d\n" , ans[i].first);
    }
    return 0;
}