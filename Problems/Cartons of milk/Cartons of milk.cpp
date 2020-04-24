#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back

using namespace std;

int n , ans = -1 , m , k;
pair < int , int > b[1000009];
vector < int > myvector , cur;
bool check(int x)
{
    cur.clear();
    cur = myvector;
    for(int i= m - 1 , j = 0 ; i >= 0 && j < x ; i--,j++) cur.pb(b[i].F);
    sort(cur.begin() , cur.end());
    int date = 0 , j = 0;
    for(unsigned int i = 0; i < cur.size(); i++){
        if(cur[i] - date < 0) return false;
        j++;
        if(j == k){
            date++;
            j=0;
        }
    }
    return true;
}

int F(int low , int high)
{
    while(low <= high)
    {
        int mid = (low + high) / 2;
        if(check(mid))
        {
            low = mid + 1;
            ans = mid;
        }
        else high = mid - 1;
    }
    return ans;
}

int main()
{
    int x;
    cin >> n >> m >> k;
    for(int i = 0; i < n ; i++){
        scanf("%d" , &x);
        myvector.pb(x);
    }
    for(int i = 0 ; i < m ; i++){
        scanf("%d" , &b[i].F);
        b[i].S = i;
    }
    sort(myvector.begin() ,myvector.end());
    sort(b , b + m);
    x = F(0 , m);
    printf("%d\n",x);
    for(int i = m - 1 , j = 0 ; j < x ; i--,j++) {
        printf("%d ",b[i].S + 1);
    }
    printf("\n");
    return 0;
}