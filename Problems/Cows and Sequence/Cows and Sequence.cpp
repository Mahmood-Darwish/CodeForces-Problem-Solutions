#include <bits/stdc++.h>

using namespace std;

int n , a , x , t , num;
long long sum;
int q[10000000];
long long arr[1000000];

int main()
{
    q[num] = 0;
    num++;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&t);
        if(t == 1)
        {
            scanf("%d %d",&a,&x);
            sum += (a * x);
            double ans = (sum / (num + 0.0));
            printf("%.14G\n",ans);
            arr[a] += x;
            continue;
        }
        if(t == 2)
        {
            scanf("%d",&a);
            q[num] = a;
            sum += a;
            num++;
            double ans = (sum / (num + 0.0));
            printf("%.14G\n",ans);
            continue;
        }
        if(t == 3)
        {
            sum -= q[num-1];
            sum -= arr[num];
            arr[num-1] += arr[num];
            arr[num] = 0;
            num--;
            double ans = (sum / (num + 0.0));
            printf("%.14G\n",ans);
            continue;
        }
    }
    return 0;
}