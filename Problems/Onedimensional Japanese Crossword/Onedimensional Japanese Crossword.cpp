#include <bits/stdc++.h>
#define S second
#define F first
#define MEM(a,b) memset(a,b,sizeof(a))
#define SF(x) scanf("%I64d" , &x)

using namespace std;
typedef long long ll;
double M_PI = 3.14159265358979323846;

ll GCD(ll a , ll b)
{
    if(!b)return a;
    return GCD(b,a%b);
}

ll LCM(ll a , ll b){
    return (a * b)/GCD(a,b);
}

int n ,sum;
string s;
vector < int > sol;

int main()
{
    cin >> n;
    cin >> s;
    for(int i = 0 ; i < n ; i++)
    {
        if(s[i] == 'B')
        {
            sum++;
        }
        else{
            if(sum)
                sol.push_back(sum);
            sum = 0;
        }
    }
    if(sum != 0)
    {
        sol.push_back(sum);
    }
    cout << sol.size() << '\n';
    for(int i = 0 ; i < sol.size() ; i++)
        cout << sol[i] << ' ';
    return 0;
}